/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:19:25 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/02/17 16:33:00 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_print_string(int fd, char *str)
{
	int	iter;

	if (!str)
		return (pf_print_string(fd, PRINT_NULL_STRING));
	iter = 0;
	while (str[iter])
		iter += pf_print(fd, str[iter]);
	return (iter);
}
