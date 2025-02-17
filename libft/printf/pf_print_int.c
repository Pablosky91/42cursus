/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 00:09:30 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/02/17 16:18:21 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pf_print_int_recursive(int fd, int nbr, int sign);

int	pf_print_int(int fd, int nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		count += pf_print(fd, '-');
		count += pf_print_int_recursive(fd, nbr, -1);
	}
	else
		count += pf_print_int_recursive(fd, nbr, 1);
	return (count);
}

static int	pf_print_int_recursive(int fd, int nbr, int sign)
{
	int	count;

	count = 0;
	if (nbr >= 10 || nbr <= -10)
		count += pf_print_int_recursive(fd, nbr / 10, sign);
	count += pf_print(fd, (nbr % 10) * sign + '0');
	return (count);
}
