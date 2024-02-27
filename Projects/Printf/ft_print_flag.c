/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:50:23 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/02/27 14:09:58 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_flag(char flag, va_list args)
{
	if (flag == 'c')
		return (ft_print_char(va_arg(args, int)));
	if (flag == 's')
		return (ft_print_string(va_arg(args, char *)));
	if (flag == 'p')
		return (ft_print_pointer(va_arg(args, size_t)));
	if (flag == 'd' || flag == 'i')
		return (ft_print_int(va_arg(args, int)));
	if (flag == 'u')
		return (ft_print_unsigned_int(va_arg(args, unsigned int)));
	if (flag == 'x')
		return (ft_print_hexadecimal(va_arg(args, unsigned int), HEX_LOWER));
	if (flag == 'X')
		return (ft_print_hexadecimal(va_arg(args, unsigned int), HEX_UPPER));
	if (flag == '%')
		return (ft_print_char(PRINTF_SPECIFIER));
	return (0);
}
