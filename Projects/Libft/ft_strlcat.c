/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:49:01 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/01/24 01:51:42 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len >= dstsize)
		return (dstsize + src_len);
	if (dst_len + src_len < dstsize)
		ft_memmove(&dst[dst_len], src, src_len + 1);
	else
	{
		ft_memmove(&dst[dst_len], src, dstsize - dst_len - 1);
		ft_memset(&dst[dstsize - 1], '\0', 1);
	}
	return (dst_len + src_len);
}
