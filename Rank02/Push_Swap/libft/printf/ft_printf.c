/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:12:24 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/18 16:13:17 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		written_chars;

	i = 0;
	written_chars = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == PRINTF_SPECIFIER)
		{
			i++;
			written_chars += ft_print_flag(format[i], args);
		}
		else
			written_chars += ft_print(format[i]);
		i++;
	}
	va_end(args);
	return (written_chars);
}
