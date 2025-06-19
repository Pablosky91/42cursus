/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_satisfied.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 20:39:18 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/06/19 20:41:27 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_satisfied(t_philo *philo)
{
	return (philo->table->min_number_eat != -1
		&& philo->times_eaten >= philo->table->min_number_eat);
}
