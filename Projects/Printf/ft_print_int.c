/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 00:09:30 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/02/27 17:16:49 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_int_recursive(int nbr, int sign);

int	ft_print_int(int nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		count += ft_print('-');
		count += ft_print_int_recursive(nbr, -1);
	}
	else
		count += ft_print_int_recursive(nbr, 1);
	return (count);
}

static int	ft_print_int_recursive(int nbr, int sign)
{
	int	count;

	count = 0;
	if (nbr >= 10 || nbr <= -10)
		count += ft_print_int_recursive(nbr / 10, sign);
	count += ft_print((nbr % 10) * sign + '0');
	return (count);
}
