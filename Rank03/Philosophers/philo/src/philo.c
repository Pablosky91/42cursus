/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:41:10 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/06/26 11:32:59 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init(t_table *table, t_philo **philos, t_fork **forks);
static void	cleanup(t_table *table, t_philo **philos, t_fork **forks);

int	main(int argc, char **argv)
{
	t_table	table;
	t_philo	*philos;
	t_fork	*forks;

	philos = NULL;
	if (!parse(&table, argc, argv))
		return (0);
	init(&table, &philos, &forks);
	cleanup(&table, &philos, &forks);
	return (0);
}

static void	init(t_table *table, t_philo **philos, t_fork **forks)
{
	table->dead = false;
	table->dead_mutex_ok = true;
	table->print_mutex_ok = true;
	if (!init_forks(table, forks))
		return ;
	if (gettimeofday(&table->start_time, NULL))
		return ;
	if (pthread_mutex_init(&table->dead_mutex, NULL))
	{
		table->dead_mutex_ok = false;
		return ;
	}
	if (pthread_mutex_init(&table->print_mutex, NULL))
	{
		table->print_mutex_ok = false;
		return ;
	}
	*philos = malloc(table->number_philosophers * sizeof(t_philo));
	if (!*philos)
		return ;
	create_philos(table, philos, forks);
}

static void	cleanup(t_table *table, t_philo **philos, t_fork **forks)
{
	int	i;

	i = -1;
	join_philos(table, philos);
	while (++i < table->number_philosophers)
		if ((*forks)[i].mutex_ok)
			pthread_mutex_destroy(&(*forks)[i].mutex);
	if (table->dead_mutex_ok)
		pthread_mutex_destroy(&table->dead_mutex);
	if (table->print_mutex_ok)
		pthread_mutex_destroy(&table->print_mutex);
	free(*philos);
	free(*forks);
}
