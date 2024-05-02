/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:19:25 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/02/23 23:58:36 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(char *str)
{
	int	i;

	if (!str)
		return (ft_print_string(PRINT_NULL));
	i = 0;
	while (str[i])
		i += ft_print(str[i]);
	return (i);
}
