/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep_lesser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:33:01 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/06/26 11:46:21 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	usleep_lesser(t_philo *philo, long ms1, long ms2)
{
	if (ms1 < ms2 && usleep(ms1 * 1000))
		kill_philo(philo);
	else if (usleep(ms2 * 1000))
		kill_philo(philo);
	is_dead(philo);
}
