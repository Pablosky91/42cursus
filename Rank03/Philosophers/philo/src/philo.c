/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:41:10 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/06/09 17:46:48 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
