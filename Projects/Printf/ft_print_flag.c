/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:50:23 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/02/23 19:04:50 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	 	ft_print_flag(char flag, va_list args)
{
	if (flag == 'c')
		ft_print(va_arg(args, int));
	if (flag == 's')
		ft_print_string(va_arg(args, char *));
	if (flag == 'p')
		ft_print('p');
	if (flag == 'd' || flag == 'i')
		ft_print('d');
	if (flag == 'u')
		ft_print('u');
	if (flag == 'x')
		ft_print('x');
	if (flag == 'X')
		ft_print('X');
	if (flag == '%')
		ft_print('%');
	return (1000);
}
