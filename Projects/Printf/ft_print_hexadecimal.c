/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexadecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 00:07:05 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/02/28 02:34:08 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_print_hexadecimal(long hex, char *hex_case)
{
	int	count;

	count = 0;
	if (hex >= 16)
		count += ft_print_hexadecimal(hex / 16, hex_case);
	count += ft_print(hex_case[hex % 16]);
	return (count);
}
