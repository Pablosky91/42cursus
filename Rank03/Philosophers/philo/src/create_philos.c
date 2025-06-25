/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:45:50 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/06/25 22:23:50 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	assign_forks(t_table *table, t_philo **philos, t_fork **forks, int i);

bool	create_philos(t_table *table, t_philo **philos, t_fork **forks)
{
	int	i;

	i = 0;
	while (i < table->number_philosophers)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].table = table;
		(*philos)[i].times_eaten = 0;
		(*philos)[i].time_last_meal = 0;
		assign_forks(table, philos, forks, i);
		if (pthread_create(&((*philos)[i].thread), NULL, routine, &((*philos)[i])))
			return (false);
		i++;
	}
	return (true);
}

static void	assign_forks(t_table *table, t_philo **philos, t_fork **forks, int i)
{
	int	j;

	j = (i + 1) % table->number_philosophers;
	if (i < j)
	{
		(*philos)[i].left = &(*forks)[i];
		(*philos)[i].right = &(*forks)[j];
	}
	else
	{
		(*philos)[i].left = &(*forks)[j];
		(*philos)[i].right = &(*forks)[i];
	}
}
