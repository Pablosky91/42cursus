/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:05:30 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/01/26 23:23:22 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Writes len bytes of value c (converted to an unsigned char) to the string b.
*/
void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*copy;

	copy = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		copy[i] = c;
		i++;
	}
	return (copy);
}
