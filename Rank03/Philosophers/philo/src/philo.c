/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:41:10 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/06/25 22:22:34 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	init(t_table *table, t_philo **philos, t_fork **forks);

//TODO destroy mutexes
int	main(int argc, char **argv)
{
	t_table	table;
	t_philo	*philos;
	t_fork	*forks;

	if (!parse(&table, argc, argv))
		return (1);
	init(&table, &philos, &forks);
	join_philos(&table, &philos);
	free(philos);
	free(forks);
	return (0);
}

static bool	init(t_table *table, t_philo **philos, t_fork **forks)
{
	table->dead = false;
	init_forks(table, forks);
	if (gettimeofday(&table->start_time, NULL))
		return (false);
	if (pthread_mutex_init(&table->print_mutex, NULL))
		return (false);
	if (pthread_mutex_init(&table->dead_mutex, NULL))
		return (false);
	*philos = malloc(table->number_philosophers * sizeof(t_philo));
	if (!*philos)
		return (false);
	return (create_philos(table, philos, forks));
}
