/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:41:08 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/06/09 22:02:26 by pdel-olm         ###   ########.fr       */
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
typedef struct s_fork	t_fork;
typedef struct timeval	t_timeval;
typedef enum e_message	t_message;

typedef pthread_t		t_thread;
typedef pthread_mutex_t	t_mutex;

enum e_message
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIE,
};

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
	t_fork		*forks;
};

struct s_philo
{
	int			id;
	long		time_last_meal;
	int			times_eaten;
	t_thread	thread;
	t_table		*table;
	t_fork		*left;
	t_fork		*right;
};

struct s_fork
{
	int		id;
	bool	taken;
	t_mutex	grab_mutex;
	t_mutex	taken_mutex;
};

bool	parse(t_table *philo, int argc, char **argv);
bool	init_forks(t_table *table);
bool	create_philos(t_table *table);
void	*routine(void *arg);
void	print_philo(t_table *table, int id, t_message message);
long	get_time_ms(t_timeval start);
bool	join_philos(t_table *table);

#endif