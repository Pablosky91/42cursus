/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_forks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:25:41 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/06/26 11:51:34 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	release_forks(t_philo *philo)
{
	if (philo->left == philo->right)
		return ;
	if (pthread_mutex_lock(&philo->left->mutex))
		kill_philo(philo);
	if (pthread_mutex_lock(&philo->right->mutex))
		kill_philo(philo);
	if (philo->left->taken && philo->right->taken
		&& philo->left->orientation == philo->id
		&& philo->right->orientation == philo->id)
	{
		philo->left->taken = false;
		philo->right->taken = false;
	}
	if (pthread_mutex_unlock(&philo->left->mutex))
		kill_philo(philo);
	if (pthread_mutex_unlock(&philo->right->mutex))
		kill_philo(philo);
}
