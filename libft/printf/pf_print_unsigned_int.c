/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 00:10:01 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/02/17 16:17:30 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_print_unsigned_int(int fd, unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr >= 10)
		count += pf_print_unsigned_int(fd, nbr / 10);
	count += pf_print(fd, (nbr % 10) + '0');
	return (count);
}
