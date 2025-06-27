/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_ms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 21:56:45 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/06/26 11:44:39 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time_ms(t_timeval start)
{
	t_timeval	now;

	if (gettimeofday(&now, NULL))
		return (LONG_MIN);
	return (((now.tv_sec - start.tv_sec) * 1000)
		+ ((now.tv_usec - start.tv_usec) / 1000));
}
