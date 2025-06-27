/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_sleep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:58:45 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/06/26 11:54:42 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine_sleep(t_philo *philo)
{
	print_philo(philo->table, philo, SLEEP);
	release_forks(philo);
	usleep_lesser(philo, philo->table->time_die - philo->table->time_eat,
		philo->table->time_sleep);
}
