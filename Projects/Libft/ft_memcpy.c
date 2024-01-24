/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:41:31 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/01/24 01:34:21 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dst_copy;
	char	*src_copy;

	if (dst == 0 && src == 0)
		return (dst);
	i = 0;
	dst_copy = (char *) dst;
	src_copy = (char *) src;
	while (i < n)
	{
		ft_memset(&dst_copy[i], src_copy[i], 1);
		i++;
	}
	return (dst);
}
