/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 18:26:20 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/06/12 18:41:14 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_dead(t_philo *philo)
{
	if (get_time_ms(philo->table->start_time) - philo->time_last_meal
		< philo->table->time_die)
		return (false);
	pthread_mutex_lock(&philo->table->dead_mutex);
	philo->table->dead = true;
	pthread_mutex_unlock(&philo->table->dead_mutex);
	print_philo(philo->table, philo->id, DIE);
	return (true);
}
