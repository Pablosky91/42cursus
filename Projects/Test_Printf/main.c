/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 20:44:11 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/02/17 13:54:54 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "libft.h"

static void	flags(void);

int	main(void)
{
	char			*s;
	int				i;
	unsigned int	u;

	s = ft_strdup("Hello");
	i = 120;
	u = 123;
	printf("Character: %c\n", i);
	printf("String: %s\n", s);
	printf("Address: %p\n", (void *)&i);
	printf("Decimal integer: %d\n", i);
	printf("decimal Integer: %i\n", i);
	printf("Unsigned integer: %u\n", u);
	printf("Lowercase hexadecimal: %x\n", u);
	printf("Uppercase hexadecimal: %X\n", u);
	printf("Percent sign: %%\n");
	flags();
	return (0);
}

static void	flags(void)
{
	int		x;
	float	z;

	x = 123;
	z = 123.456;
	printf("----------------------------------------\n");
	printf("Number with hexadecimal prefix: %#x\n", x);
	printf("Positive integer with plus: >%+d<\n", x);
	printf("Integer with leading space: >% d<\n", x);
	printf("Right-justified integer: >%5d<\n", x);
	printf("Left-justified integer: >%-5d<\n", x);
	printf("Zero-padded integer: %05d\n", x);
	printf("Rounded float with one decimal place: %.1f\n", z);
	printf("Rounded float with two decimal places: %.2f\n", z);
}
/*
static void	print(char *format, int argument)
{
	int	orig;
	int	mine;

	orig = printf(format, argument);
	mine = ft_printf(format, argument);
	printf("%d %d\n\n", orig, mine);
}*/
