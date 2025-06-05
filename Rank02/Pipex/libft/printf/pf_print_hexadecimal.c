/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_hexadecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 00:07:05 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/02/17 16:18:30 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_print_hexadecimal(int fd, size_t hex, char *hex_case)
{
	int	count;

	count = 0;
	if (hex >= 16)
		count += pf_print_hexadecimal(fd, hex / 16, hex_case);
	count += pf_print(fd, hex_case[hex % 16]);
	return (count);
}
