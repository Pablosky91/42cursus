/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 00:10:22 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/09/10 15:49:59 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_print_pointer(size_t p)
{
	int	count;

	count = 0;
	count += pf_print_string("0x");
	count += pf_print_hexadecimal(p, HEX_LOWER);
	return (count);
}
