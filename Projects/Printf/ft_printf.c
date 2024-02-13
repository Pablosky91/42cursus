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

	va_start(args, format);
	printf("%s --> %s\n", format, va_arg(args, char *));
	va_end(args);
	return (0);
}

int	main(void)
{
	char	*arg2;

	arg2 = ft_strdup("Arg2");
	ft_printf("Hola", "Arg1", arg2);
	return (0);
}
