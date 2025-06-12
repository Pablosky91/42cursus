/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_eat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:58:48 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/06/12 18:41:25 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	grab_forks(t_philo *philo);

void	routine_eat(t_philo *philo)
{
	while (!grab_forks(philo))
	{
		if (is_dead(philo))
			return ;
		//usleep(1000);
	}
	philo->times_eaten++;
	philo->time_last_meal = get_time_ms(philo->table->start_time);
	print_philo(philo->table, philo->id, EAT);
	usleep(philo->table->time_eat * 1000);
}

static bool	grab_forks(t_philo *philo)
{
	bool	grabbed;

	grabbed = false;
	pthread_mutex_lock(&philo->left->taken_mutex);
	pthread_mutex_lock(&philo->right->taken_mutex);
	if (!philo->left->taken && !philo->right->taken)
	{
		pthread_mutex_lock(&philo->left->grab_mutex);
		pthread_mutex_lock(&philo->right->grab_mutex);
		print_philo(philo->table, philo->id, FORK);
		print_philo(philo->table, philo->id, FORK);
		philo->left->taken = true;
		philo->right->taken = true;
		grabbed = true;
	}
	pthread_mutex_unlock(&philo->left->taken_mutex);
	pthread_mutex_unlock(&philo->right->taken_mutex);
	return (grabbed);
}
