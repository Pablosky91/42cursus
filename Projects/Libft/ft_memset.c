/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:05:30 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/01/16 18:57:55 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			aux;
	unsigned char	*copy;

	copy = (unsigned char *) s;
	aux = 0;
	while (aux < n)
	{
		copy[aux] = c;
		aux++;
	}
	return (copy);
}
