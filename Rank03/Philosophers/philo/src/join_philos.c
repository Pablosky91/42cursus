/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:46:14 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/06/09 17:46:52 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	join_philos(t_table *table)
{
	int	i;

	i = 0;
	if (pthread_mutex_destroy(&table->start_mutex))
		return (false);
	while (i < table->number_philosophers)
	{
		if (pthread_join(table->philos[i].thread, NULL))
			return (false);
		i++;
	}
	return (true);
}
