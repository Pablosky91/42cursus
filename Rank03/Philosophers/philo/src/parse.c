/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:18:01 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/06/05 21:39:04 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	better_atoi(char *str, int *num);

bool	parse(t_table *table, int argc, char **argv)
{
	table->min_number_eat = -1;
	if (argc < 5 || argc > 6
		|| !better_atoi(argv[1], &table->number_philosophers)
		|| !better_atoi(argv[2], &table->time_die)
		|| !better_atoi(argv[3], &table->time_eat)
		|| !better_atoi(argv[4], &table->time_sleep)
		|| (argc == 6 && !better_atoi(argv[5], &table->min_number_eat))
		|| table->number_philosophers <= 0
		|| table->time_die < 0
		|| table->time_eat < 0
		|| table->time_sleep < 0
		|| (argc == 6 && table->min_number_eat < 0))
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
