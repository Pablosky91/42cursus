/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_eat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:58:48 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/06/26 11:54:37 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	grab_forks(t_philo *philo);
static void	use_forks(t_philo *philo);

void	routine_eat(t_philo *philo)
{
	while (!is_dead(philo) && !grab_forks(philo))
		;
	if (is_dead(philo))
		return ;
	print_philo(philo->table, philo, EAT);
	philo->time_last_meal = get_time_ms(philo->table->start_time);
	philo->times_eaten++;
	usleep_lesser(philo, philo->table->time_die, philo->table->time_eat);
}

static bool	grab_forks(t_philo *philo)
{
	bool	grabbed;

	grabbed = false;
	if (philo->left == philo->right)
		return (grabbed);
	if (pthread_mutex_lock(&philo->left->mutex))
		kill_philo(philo);
	if (pthread_mutex_lock(&philo->right->mutex))
		kill_philo(philo);
	if (!philo->left->taken && !philo->right->taken
		&& philo->left->orientation != philo->id
		&& philo->right->orientation != philo->id)
	{
		use_forks(philo);
		grabbed = true;
	}
	if (pthread_mutex_unlock(&philo->left->mutex))
		kill_philo(philo);
	if (pthread_mutex_unlock(&philo->right->mutex))
		kill_philo(philo);
	return (grabbed);
}

static void	use_forks(t_philo *philo)
{
	print_philo(philo->table, philo, FORK);
	print_philo(philo->table, philo, FORK);
	philo->left->taken = true;
	philo->right->taken = true;
	philo->left->orientation = philo->id;
	philo->right->orientation = philo->id;
}
