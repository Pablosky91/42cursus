/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 00:10:01 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/02/27 16:59:33 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned_int(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr >= 10)
		count += ft_print_unsigned_int(nbr / 10);
	count += ft_print((nbr % 10) + '0');
	return (count);
}
