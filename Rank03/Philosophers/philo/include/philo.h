/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:41:08 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/06/24 21:38:15 by pdel-olm         ###   ########.fr       */
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

typedef enum e_message		t_message;

typedef struct s_table		t_table;
typedef struct s_philo		t_philo;
typedef struct s_fork		t_fork;
typedef struct timeval		t_timeval;

typedef pthread_t			t_thread;
typedef pthread_mutex_t		t_mutex;

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
	bool		dead;
	t_mutex		dead_mutex;
	t_timeval	start_time;
	t_philo		*philos;
	t_mutex		print_mutex;
	t_fork		*forks;
};

struct s_philo
{
	int			id;
	long		time_last_meal;
	int			times_eaten;
	bool		dead;
	t_thread	thread;
	t_table		*table;
	t_fork		*left;
	t_fork		*right;
};

struct s_fork
{
	int		id;
	bool	taken;
	int		orientation;
	t_mutex	grab_mutex;
	t_mutex	taken_mutex;
};

bool	parse(t_table *philo, int argc, char **argv);
bool	init_forks(t_table *table);
bool	create_philos(t_table *table);
bool	all_alive(t_table *table);
bool	is_dead(t_philo *philo);
bool	is_satisfied(t_philo *philo);
void	usleep_lesser(t_philo *philo, long ms1, long ms2);
void	*routine(void *arg);
void	routine_eat(t_philo *philo);
void	routine_sleep(t_philo *philo);
void	routine_think(t_philo *philo);
void	release_forks(t_philo *philo);
void	print_philo(t_table *table, int id, t_message message);
long	get_time_ms(t_timeval start);
bool	join_philos(t_table *table);

#endif