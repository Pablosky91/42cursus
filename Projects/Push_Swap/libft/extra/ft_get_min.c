/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:10:17 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/07/29 21:12:40 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Returns the lower of the two given numbers.
*/
int	ft_get_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
