/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 21:56:16 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/06/09 22:02:51 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_forks(t_table *table)
{
	int	i;

	i = 0;
	table->forks = malloc(table->number_philosophers * sizeof(t_fork));
	while (i < table->number_philosophers)
	{
		table->forks[i].id = i + 1;
		table->forks[i].taken = false;
		if (pthread_mutex_init(&table->forks[i].grab_mutex, NULL))
			return (false);
		if (pthread_mutex_init(&table->forks[i].taken_mutex, NULL))
			return (false);
		i++;
	}
	return (true);
}
