/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:43:32 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/06/09 17:45:10 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	wait_to_start(t_table *table);

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	wait_to_start(philo->table);
	while (true)
	{
		print_philo(philo->table, philo->id, 1);
		usleep(philo->table->time_eat * 1000);
		print_philo(philo->table, philo->id, 2);
		usleep(philo->table->time_sleep * 1000);
		print_philo(philo->table, philo->id, 3);
	}
	return (NULL);
}

static void	wait_to_start(t_table *table)
{
	bool	wait;

	wait = true;
	while (wait)
	{
		pthread_mutex_lock(&table->start_mutex);
		if (table->start)
			wait = false;
		pthread_mutex_unlock(&table->start_mutex);
		usleep(100);
	}
}
