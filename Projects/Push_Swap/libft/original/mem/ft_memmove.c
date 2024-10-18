/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:57:48 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/18 16:13:17 by pdel-olm         ###   ########.fr       */
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
	size_t			i;
	unsigned char	*dst_copy;
	unsigned char	*src_copy;

	if (dst <= src)
		return (ft_memcpy(dst, src, len));
	i = 1;
	dst_copy = (unsigned char *) dst;
	src_copy = (unsigned char *) src;
	while (i <= len)
	{
		ft_memcpy(&dst_copy[len - i], &src_copy[len - i], 1);
		i++;
	}
	return (dst);
}
