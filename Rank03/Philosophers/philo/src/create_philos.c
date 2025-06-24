/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:45:50 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/06/24 21:59:10 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	assign_forks(t_table *table, int i);

bool	create_philos(t_table *table)
{
	int	i;

	if (gettimeofday(&table->start_time, NULL))
		return (false);
	if (pthread_mutex_init(&table->print_mutex, NULL))
		return (false);
	if (pthread_mutex_init(&table->dead_mutex, NULL))
		return (false);
	table->philos = malloc(table->number_philosophers * sizeof(t_philo));
	table->dead = false;
	if (!table->philos)
		return (false);
	i = 0;
	while (i < table->number_philosophers)
	{
		table->philos[i].id = i + 1;
		table->philos[i].table = table;
		assign_forks(table, i);
		table->philos[i].times_eaten = 0;
		table->philos[i].time_last_meal = 0;
		if (pthread_create(&(table->philos[i].thread), NULL, routine, &(table->philos[i])))
			return (false);
		i++;
	}
	return (true);
}

static void	assign_forks(t_table *table, int i)
{
	int	j;

	j = (i + 1) % table->number_philosophers;
	if (i < j)
	{
		table->philos[i].left = &table->forks[i];
		table->philos[i].right = &table->forks[j];
	}
	else
	{
		table->philos[i].left = &table->forks[j];
		table->philos[i].right = &table->forks[i];
	}
}
