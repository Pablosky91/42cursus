/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_sleep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:58:45 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/06/12 17:59:40 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	release_forks(t_philo *philo);

void	routine_sleep(t_philo *philo)
{
	print_philo(philo->table, philo->id, SLEEP);
	release_forks(philo);
	usleep(philo->table->time_sleep * 1000);
}

static void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->left->grab_mutex);
	pthread_mutex_unlock(&philo->right->grab_mutex);
	pthread_mutex_lock(&philo->left->taken_mutex);
	philo->left->taken = false;
	pthread_mutex_unlock(&philo->left->taken_mutex);
	pthread_mutex_lock(&philo->right->taken_mutex);
	philo->right->taken = false;
	pthread_mutex_unlock(&philo->right->taken_mutex);
}
