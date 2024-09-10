/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:19:25 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/09/10 15:50:07 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_print_string(char *str)
{
	int	i;

	if (!str)
		return (pf_print_string(PRINT_NULL));
	i = 0;
	while (str[i])
		i += pf_print(str[i]);
	return (i);
}
