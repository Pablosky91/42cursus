/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:12:24 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/02/17 16:32:52 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		iter;
	int		written_chars;

	iter = 0;
	written_chars = 0;
	va_start(args, format);
	while (format[iter])
	{
		if (format[iter] == PRINTF_SPECIFIER)
		{
			iter++;
			written_chars += pf_print_flag(STDOUT_FILENO, format[iter], args);
		}
		else
			written_chars += pf_print(STDOUT_FILENO, format[iter]);
		iter++;
	}
	va_end(args);
	return (written_chars);
}
