/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:43:31 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/06/09 17:43:32 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long	time_difference_ms(t_timeval start);

void	print_philo(t_table *table, int id, int action)
{
	pthread_mutex_lock(&table->print_mutex);
	printf("\e[30;47m%li\e[0m", time_difference_ms(table->start_time));
	if (id % 5 == 0)
		printf("\e[1;31m %d\e[0m", id);
	else if (id % 5 == 1)
		printf("\e[1;32m %d\e[0m", id);
	else if (id % 5 == 2)
		printf("\e[1;33m %d\e[0m", id);
	else if (id % 5 == 3)
		printf("\e[1;34m %d\e[0m", id);
	else if (id % 5 == 4)
		printf("\e[1;35m %d\e[0m", id);
	if (action == 0)
		printf("\e[91m has taken a fork\e[0m\n");
	else if (action == 1)
		printf("\e[92m is eating\e[0m\n");
	else if (action == 2)
		printf("\e[93m is sleeping\e[0m\n");
	else if (action == 3)
		printf("\e[94m is thinking\e[0m\n");
	else if (action == 4)
		printf("\e[95m died\e[0m\n");
	pthread_mutex_unlock(&table->print_mutex);
}

static long	time_difference_ms(t_timeval start)
{
	t_timeval	now;

	gettimeofday(&now, NULL);
	return (((now.tv_sec - start.tv_sec) * 1000)
		+ ((now.tv_usec - start.tv_usec) / 1000));
}
