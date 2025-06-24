/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:43:31 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/06/24 17:34:32 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philo(t_table *table, int id, t_message message)
{
	pthread_mutex_lock(&table->dead_mutex);
	if (!table->dead)
	{
		pthread_mutex_lock(&table->print_mutex);
		printf("\e[30;47m%li\e[0m", get_time_ms(table->start_time));
		printf("\e[1;%dm %d\e[0m", 31 + id % 5, id);
		if (message == DIE)
			printf("\e[91m died\e[0m\n");
		else if (message == EAT)
			printf("\e[92m is eating\e[0m\n");
		else if (message == SLEEP)
			printf("\e[93m is sleeping\e[0m\n");
		else if (message == THINK)
			printf("\e[94m is thinking\e[0m\n");
		else if (message == FORK)
			printf("\e[95m has taken a fork\e[0m\n");
		pthread_mutex_unlock(&table->print_mutex);
	}
	pthread_mutex_unlock(&table->dead_mutex);
}
