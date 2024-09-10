/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_hexadecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 00:07:05 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/09/10 15:49:28 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_print_hexadecimal(size_t hex, char *hex_case)
{
	int	count;

	count = 0;
	if (hex >= 16)
		count += pf_print_hexadecimal(hex / 16, hex_case);
	count += pf_print(hex_case[hex % 16]);
	return (count);
}
