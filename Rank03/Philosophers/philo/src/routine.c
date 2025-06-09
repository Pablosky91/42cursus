/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:43:32 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/06/09 23:39:35 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// static void	wait_to_start(t_table *table);

void	release_forks(t_philo *philo)
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

bool	grab_forks(t_philo *philo)
{
	bool	grabbed;

	grabbed = false;
	pthread_mutex_lock(&philo->left->taken_mutex);
	pthread_mutex_lock(&philo->right->taken_mutex);
	if (!philo->left->taken && !philo->right->taken)
	{
		pthread_mutex_lock(&philo->left->grab_mutex);
		print_philo(philo->table, philo->id, FORK);
		philo->left->taken = true;
		pthread_mutex_lock(&philo->right->grab_mutex);
		print_philo(philo->table, philo->id, FORK);
		philo->right->taken = true;
		grabbed = true;
	}
	pthread_mutex_unlock(&philo->left->taken_mutex);
	pthread_mutex_unlock(&philo->right->taken_mutex);
	return (grabbed);
}

void	eat(t_philo *philo)
{
	while (!grab_forks(philo))
	{
		// if (get_time_ms(philo->table->start_time) - philo->time_last_meal >= philo->table->time_die)
			// TODO death
			// usleep(1000);
	}
	philo->times_eaten++;
	philo->time_last_meal = get_time_ms(philo->table->start_time);
	print_philo(philo->table, philo->id, EAT);
	usleep(philo->table->time_eat * 1000);
	release_forks(philo);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	// wait_to_start(philo->table);
	while (philo->times_eaten < philo->table->min_number_eat || philo->table->min_number_eat == -1)
	{
		eat(philo);
		print_philo(philo->table, philo->id, SLEEP);
		usleep(philo->table->time_sleep * 1000);
		print_philo(philo->table, philo->id, THINK);
	}
	return (NULL);
}

// static void	wait_to_start(t_table *table)
// {
// 	bool	wait;

// 	wait = true;
// 	while (wait)
// 	{
// 		pthread_mutex_lock(&table->start_mutex);
// 		if (table->start)
// 			wait = false;
// 		pthread_mutex_unlock(&table->start_mutex);
// 		usleep(100);
// 	}
// }
