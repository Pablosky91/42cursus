/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:41:10 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/05/01 18:50:39 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philo(long ms, int id, int action)
{
	printf("\e[30;47m%li\e[0m", ms);
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
}

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (parse(&philo, argc, argv))
	{
		printf("Number of philosophers: %i\n", philo.number_philosophers);
		printf("Time to die: %i\n", philo.time_die);
		printf("Time to eat: %i\n", philo.time_eat);
		printf("Time to sleep: %i\n", philo.time_sleep);
		printf("Number of times to eat: %i\n", philo.min_number_eat);
	}
	return (0);
}
