/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:41:08 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/04/18 21:32:55 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_philo	t_philo;

struct s_philo
{
	int	number_philosophers;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	min_number_eat;
};

bool	parse(t_philo *philo, int argc, char **argv);

#endif