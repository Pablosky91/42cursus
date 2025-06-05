/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 00:10:22 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/18 16:13:17 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(size_t p)
{
	int	count;

	count = 0;
	count += ft_print_string("0x");
	count += ft_print_hexadecimal(p, HEX_LOWER);
	return (count);
}
