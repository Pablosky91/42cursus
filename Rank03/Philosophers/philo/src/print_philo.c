/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:43:31 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/06/26 11:51:12 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philo(t_table *table, t_philo *philo, t_action action)
{
	if (pthread_mutex_lock(&table->dead_mutex))
		kill_philo(philo);
	if (!table->dead)
	{
		if (pthread_mutex_lock(&table->print_mutex))
			kill_philo(philo);
		printf("\e[30;47m%li\e[0m", get_time_ms(table->start_time));
		printf("\e[1;%dm %d\e[0m", 31 + philo->id % 5, philo->id);
		if (action == DIE)
			printf("\e[91m died\e[0m\n");
		else if (action == EAT)
			printf("\e[92m is eating\e[0m\n");
		else if (action == SLEEP)
			printf("\e[93m is sleeping\e[0m\n");
		else if (action == THINK)
			printf("\e[94m is thinking\e[0m\n");
		else if (action == FORK)
			printf("\e[95m has taken a fork\e[0m\n");
		if (pthread_mutex_unlock(&table->print_mutex))
			kill_philo(philo);
	}
	if (pthread_mutex_unlock(&table->dead_mutex))
		kill_philo(philo);
}
