/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 20:44:11 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/02/23 20:28:19 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "printf.h"

int	main(void)
{
	char			*s;
	int				i;
	unsigned int	u;
	int				orig;
	int				mine;
	char 			*format;

	s = ft_strdup("Hello");
	i = 120;
	u = 123;
	////////////////////////////////////
	format = ft_strdup("Character: %c\n");
	orig = printf(format, i);
	mine = ft_printf(format, i);
	printf("%d %d\n\n", orig, mine);
	////////////////////////////////////
	format = ft_strdup("String: %s\n");
	orig = printf(format, s);
	mine = ft_printf(format, s);
	printf("%d %d\n\n", orig, mine);
	////////////////////////////////////
	format = ft_strdup("Address: %p\n");
	orig = printf(format, (void *)&i);
	mine = ft_printf(format, (void *)&i);
	printf("%d %d\n\n", orig, mine);
	////////////////////////////////////
	format = ft_strdup("Decimal integer: %d\n");
	orig = printf(format, i);
	mine = ft_printf(format, i);
	printf("%d %d\n\n", orig, mine);
	////////////////////////////////////
	format = ft_strdup("decimal Integer: %i\n");
	orig = printf(format, i);
	mine = ft_printf(format, i);
	printf("%d %d\n\n", orig, mine);
	////////////////////////////////////
	format = ft_strdup("Unsigned integer: %u\n");
	orig = printf(format, u);
	mine = ft_printf(format, u);
	printf("%d %d\n\n", orig, mine);
	////////////////////////////////////
	format = ft_strdup("Lowercase hexadecimal: %x\n");
	orig = printf(format, u);
	mine = ft_printf(format, u);
	printf("%d %d\n\n", orig, mine);
	////////////////////////////////////
	format = ft_strdup("Uppercase hexadecimal: %X\n");
	orig = printf(format, u);
	mine = ft_printf(format, u);
	printf("%d %d\n\n", orig, mine);
	////////////////////////////////////
	format = ft_strdup("Percent sign: %%\n");
	orig = printf("%s", format);
	mine = ft_printf("%s", format);
	printf("%d %d\n\n", orig, mine);

	return (0);
}
