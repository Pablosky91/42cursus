/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:46:14 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/06/26 11:21:17 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_philos(t_table *table, t_philo **philos)
{
	int	i;

	i = 0;
	if (!*philos)
		return ;
	while (i < table->number_philosophers)
	{
		pthread_join((*philos)[i].thread, NULL);
		i++;
	}
}
