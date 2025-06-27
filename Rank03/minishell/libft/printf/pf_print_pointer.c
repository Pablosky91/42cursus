/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 00:10:22 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/02/17 16:31:43 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_print_pointer(int fd, size_t p)
{
	int	count;

	if (!p)
		return (pf_print_string(fd, PRINT_NULL_POINTER));
	count = 0;
	count += pf_print_string(fd, "0x");
	count += pf_print_hexadecimal(fd, p, HEX_LOWER);
	return (count);
}
