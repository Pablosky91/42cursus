/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 18:26:20 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/06/26 11:54:17 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_dead(t_philo *philo)
{
	if (get_time_ms(philo->table->start_time) - philo->time_last_meal
		< philo->table->time_die)
		return (false);
	print_philo(philo->table, philo, DIE);
	kill_philo(philo);
	return (true);
}
