/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:46:14 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/06/25 22:34:28 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	join_philos(t_table *table, t_philo **philos)
{
	int	i;

	i = 0;
	while (i < table->number_philosophers)
	{
		if (pthread_join((*philos)[i].thread, NULL))
			return (false);
		i++;
	}
	return (true);
}
