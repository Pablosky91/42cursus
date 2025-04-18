/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:41:10 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/04/18 21:36:47 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (parse(&philo, argc, argv))
	{
		printf("Number of philosophers: %i\n", philo.number_philosophers);
		printf("Time to die: %i\n", philo.time_die);
		printf("Time to eat: %i\n", philo.time_eat);
		printf("Time to sleep: %i\n", philo.time_sleep);
		if (argc == 6)
			printf("Number of times to eat: %i\n", philo.min_number_eat);
	}
	return (0);
}
