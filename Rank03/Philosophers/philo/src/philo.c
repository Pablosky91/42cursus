/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:41:10 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/06/05 22:35:23 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	time_difference_ms(t_timeval start)
{
	t_timeval	now;

	gettimeofday(&now, NULL);
	return (((now.tv_sec - start.tv_sec) * 1000)
		+ ((now.tv_usec - start.tv_usec) / 1000));
}

void	print_philo(t_table *table, int id, int action)
{
	pthread_mutex_lock(&table->print_mutex);
	printf("\e[30;47m%li\e[0m", time_difference_ms(table->start_time));
	if (id % 5 == 0)
		printf("\e[1;31m %d\e[0m", id);
	else if (id % 5 == 1)
		printf("\e[1;32m %d\e[0m", id);
	else if (id % 5 == 2)
		printf("\e[1;33m %d\e[0m", id);
	else if (id % 5 == 3)
		printf("\e[1;34m %d\e[0m", id);
	else if (id % 5 == 4)
		printf("\e[1;35m %d\e[0m", id);
	if (action == 0)
		printf("\e[91m has taken a fork\e[0m\n");
	else if (action == 1)
		printf("\e[92m is eating\e[0m\n");
	else if (action == 2)
		printf("\e[93m is sleeping\e[0m\n");
	else if (action == 3)
		printf("\e[94m is thinking\e[0m\n");
	else if (action == 4)
		printf("\e[95m died\e[0m\n");
	pthread_mutex_unlock(&table->print_mutex);
}

void	wait_to_start(t_table *table)
{
	bool	wait;

	wait = true;
	while (wait)
	{
		pthread_mutex_lock(&table->start_mutex);
		if (table->start)
			wait = false;
		pthread_mutex_unlock(&table->start_mutex);
		usleep(100);
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	wait_to_start(philo->table);
	while (true)
	{
		print_philo(philo->table, philo->id, 1);
		usleep(philo->table->time_eat * 1000);
		print_philo(philo->table, philo->id, 2);
		usleep(philo->table->time_sleep * 1000);
		print_philo(philo->table, philo->id, 3);
	}
	return (NULL);
}

bool	create_philos(t_table *table)
{
	int	i;

	table->start = false;
	if (pthread_mutex_init(&table->start_mutex, NULL))
		return (false);
	table->philos = malloc(table->number_philosophers * sizeof(t_philo));
	if (!table->philos)
		return (false);
	i = 0;
	while (i < table->number_philosophers)
	{
		table->philos[i].id = i + 1;
		table->philos[i].table = table;
		if (pthread_create(&(table->philos[i].thread), NULL, routine, &(table->philos[i])))
			return (false);
		i++;
	}
	pthread_mutex_lock(&table->start_mutex);
	table->start = true;
	if (gettimeofday(&table->start_time, NULL))
		return (false);
	pthread_mutex_unlock(&table->start_mutex);
	return (true);
}

bool	join_philos(t_table *table)
{
	int	i;

	i = 0;
	if (pthread_mutex_destroy(&table->start_mutex))
		return (false);
	while (i < table->number_philosophers)
	{
		if (pthread_join(table->philos[i].thread, NULL))
			return (false);
		i++;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (parse(&table, argc, argv))
	{
		printf("Number of philosophers: %i\n", table.number_philosophers);
		printf("Time to die: %i\n", table.time_die);
		printf("Time to eat: %i\n", table.time_eat);
		printf("Time to sleep: %i\n", table.time_sleep);
		printf("Number of times to eat: %i\n", table.min_number_eat);
	}
	create_philos(&table);
	join_philos(&table);
	free(table.philos);
	return (0);
}
