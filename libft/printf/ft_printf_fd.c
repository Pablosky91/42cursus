/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:13:44 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/02/17 16:32:39 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_fd(int fd, const char *format, ...)
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
			written_chars += pf_print_flag(fd, format[iter], args);
		}
		else
			written_chars += pf_print(fd, format[iter]);
		iter++;
	}
	va_end(args);
	return (written_chars);
}
