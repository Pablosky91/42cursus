/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:57:48 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/01/19 16:42:31 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
