/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_alive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 18:06:43 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/06/12 18:30:31 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	all_alive(t_table *table)
{
	bool	all_alive;

	pthread_mutex_lock(&table->dead_mutex);
	all_alive = !table->dead;
	pthread_mutex_unlock(&table->dead_mutex);
	return (all_alive);
}
