/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:18:01 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/05/01 18:44:05 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	better_atoi(char *str, int *num);

bool	parse(t_philo *philo, int argc, char **argv)
{
	philo->min_number_eat = -1;
	if (argc < 5 || argc > 6
		|| !better_atoi(argv[1], &philo->number_philosophers)
		|| !better_atoi(argv[2], &philo->time_die)
		|| !better_atoi(argv[3], &philo->time_eat)
		|| !better_atoi(argv[4], &philo->time_sleep)
		|| (argc == 6 && !better_atoi(argv[5], &philo->min_number_eat))
		|| philo->number_philosophers <= 0
		|| philo->time_die < 0
		|| philo->time_eat < 0
		|| philo->time_sleep < 0
		|| (argc == 6 && philo->min_number_eat < 0))
	{
		printf("\
Usage: ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep\
[number_of_times_each_philosopher_must_eat]\n\
All arguments must be positive integers\n\
number_of_philosophers must be greater than zero\n");
		return (false);
	}
	return (true);
}

static bool	better_atoi(char *str, int *num)
{
	long	result;
	int		i;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		if (!str[i + 1])
			return (false);
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		result = result * 10 + str[i++] - '0';
		if (result * sign < INT_MIN || result * sign > INT_MAX)
			return (false);
	}
	*num = result * sign;
	return (true);
}
