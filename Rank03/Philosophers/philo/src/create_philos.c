/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:45:50 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/06/09 23:38:47 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	create_philos(t_table *table)
{
	int	i;

	if (gettimeofday(&table->start_time, NULL))
		return (false);
	table->start = false;
	if (pthread_mutex_init(&table->start_mutex, NULL))
		return (false);
	if (pthread_mutex_init(&table->print_mutex, NULL))
		return (false);
	table->philos = malloc(table->number_philosophers * sizeof(t_philo));
	if (!table->philos)
		return (false);
	i = 0;
	while (i < table->number_philosophers)
	{
		table->philos[i].id = i + 1;
		table->philos[i].table = table;
		if (pthread_create(&(table->philos[i].thread), NULL, routine, &(table->philos[i])))
			return (false);
		table->philos[i].left = &table->forks[i];
		table->philos[i].right = &table->forks[(i + 1) % table->number_philosophers];
		table->philos[i].times_eaten = 0;
		table->philos[i].time_last_meal = 0;
		i++;
	}
	pthread_mutex_lock(&table->start_mutex);
	table->start = true;
	// if (gettimeofday(&table->start_time, NULL))
	// 	return (false);
	pthread_mutex_unlock(&table->start_mutex);
	return (true);
}
