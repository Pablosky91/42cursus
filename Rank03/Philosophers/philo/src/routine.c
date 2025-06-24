/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:43:32 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/06/24 19:15:22 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	while (!is_satisfied(philo) && all_alive(philo->table))
	{
		routine_think(philo);
		if (is_satisfied(philo) || !all_alive(philo->table))
			return (NULL);
		routine_eat(philo);
		if (is_satisfied(philo) || !all_alive(philo->table))
		{
			release_forks(philo);
			return (NULL);
		}
		routine_sleep(philo);
	}
	return (NULL);
}
