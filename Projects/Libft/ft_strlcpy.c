/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:48:52 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/01/23 18:12:43 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (src_len < dstsize)
		ft_memmove(dst, src, src_len + 1);
	else if (dstsize != 0)
	{
		ft_memmove(dst, src, dstsize - 1);
		ft_memset(&dst[dstsize - 1], '\0', 1);
	}
	return (src_len);
}
