/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:12:24 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/02/13 19:15:34 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	size_t	written_chars;

	i = 0;
	written_chars = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == "%")
		{
			i++;
			written_chars += print_flag(format[i], args);
		}
		else
			written_chars += print(format[i]);
		i++;
	}
	va_end(args);
	return (written_chars);
}
/*
int	main(void)
{
	char	*arg2;

	arg2 = ft_strdup("Arg2");
	ft_printf("Hello", "Arg1", arg2);
	return (0);
}*/
