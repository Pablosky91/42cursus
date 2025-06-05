/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:41:08 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/06/05 21:39:49 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>

typedef struct s_table	t_table;
typedef struct s_philo	t_philo;
typedef struct timeval	t_timeval;

typedef pthread_t		t_thread;
typedef pthread_mutex_t	t_mutex;

struct s_table
{
	int			number_philosophers;
	int			time_die;
	int			time_eat;
	int			time_sleep;
	int			min_number_eat;
	t_timeval	start_time;
	t_philo		*philos;
	bool		start;
	t_mutex		start_mutex;
	t_mutex		print_mutex;
};

struct s_philo
{
	int			id;
	t_thread	thread;
	t_table		*table;
};

bool	parse(t_table *philo, int argc, char **argv);

#endif