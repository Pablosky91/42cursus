/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:50:23 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/18 16:13:17 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_print_flag(char flag, va_list args)
{
	if (flag == 'c')
		return (pf_print_char(va_arg(args, int)));
	else if (flag == 's')
		return (pf_print_string(va_arg(args, char *)));
	else if (flag == 'p')
		return (pf_print_pointer(va_arg(args, size_t)));
	else if (flag == 'd' || flag == 'i')
		return (pf_print_int(va_arg(args, int)));
	else if (flag == 'u')
		return (pf_print_unsigned_int(va_arg(args, unsigned int)));
	else if (flag == 'x')
		return (pf_print_hexadecimal(va_arg(args, unsigned int), HEX_LOWER));
	else if (flag == 'X')
		return (pf_print_hexadecimal(va_arg(args, unsigned int), HEX_UPPER));
	else if (flag == '%')
		return (pf_print_char(PRINTF_SPECIFIER));
	return (0);
}
