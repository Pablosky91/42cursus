/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:57:48 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/01/26 23:17:49 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Copies len bytes from string src to string dst.
The two strings may overlap;
	the copy is always done in a non-destructive manner.
*/
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst <= src)
		ft_memcpy(dst, src, len);
	else
	{
		while (i < len)
		{
			ft_memcpy(&dst[len - i - 1], &src[len - i - 1], 1);
			i++;
		}
	}
	return (dst);
}
