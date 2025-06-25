/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 00:04:34 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/06/26 00:05:41 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	kill_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->dead_mutex);
	philo->table->dead = true;
	pthread_mutex_unlock(&philo->table->dead_mutex);
}