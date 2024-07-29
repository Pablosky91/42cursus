/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:10:12 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/07/29 21:21:52 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Returns the higher of the two given numbers.
*/
int	ft_get_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
