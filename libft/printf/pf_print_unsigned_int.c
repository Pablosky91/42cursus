/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 00:10:01 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/09/10 15:50:14 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_print_unsigned_int(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr >= 10)
		count += pf_print_unsigned_int(nbr / 10);
	count += pf_print((nbr % 10) + '0');
	return (count);
}
