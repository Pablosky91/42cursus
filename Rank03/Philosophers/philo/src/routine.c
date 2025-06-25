/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:43:32 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/06/25 23:02:26 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo		*philo;
	t_action	action;

	philo = (t_philo *) arg;
	action = THINK;
	while (!is_satisfied(philo) && all_alive(philo->table))
	{
		if (action == THINK)
		{
			routine_think(philo);
			action = EAT;
		}
		else if (action == EAT)
		{
			routine_eat(philo);
			action = SLEEP;
		}
		else if (action == SLEEP)
		{
			routine_sleep(philo);
			action = THINK;
		}
	}
	release_forks(philo);
	return (NULL);
}
