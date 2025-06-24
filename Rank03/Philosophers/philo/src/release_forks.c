/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_forks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:25:41 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/06/24 21:34:30 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	release_forks(t_philo *philo)
{
	if (philo->left == philo->right)
		return ;
	pthread_mutex_lock(&philo->left->taken_mutex);
	pthread_mutex_lock(&philo->right->taken_mutex);
	if (philo->left->taken && philo->left->orientation == philo->id)
		pthread_mutex_unlock(&philo->left->grab_mutex);
	if (philo->right->taken && philo->right->orientation == philo->id)
		pthread_mutex_unlock(&philo->right->grab_mutex);
	philo->left->taken = false;
	philo->right->taken = false;
	pthread_mutex_unlock(&philo->left->taken_mutex);
	pthread_mutex_unlock(&philo->right->taken_mutex);
}
