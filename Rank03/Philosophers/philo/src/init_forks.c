/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 21:56:16 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/06/25 22:22:20 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_forks(t_table *table, t_fork **forks)
{
	int	i;

	i = 0;
	*forks = malloc(table->number_philosophers * sizeof(t_fork));
	if (!*forks)
		return (false);
	while (i < table->number_philosophers)
	{
		(*forks)[i].id = i + 1;
		(*forks)[i].taken = false;
		(*forks)[i].orientation = 0;
		if (pthread_mutex_init(&(*forks)[i].mutex, NULL))
			return (false);
		i++;
	}
	return (true);
}
