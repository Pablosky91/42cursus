/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 20:56:30 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/01/25 22:17:33 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_copy;
	unsigned char	*s2_copy;

	if (n == 0)
		return (0);
	i = 0;
	s1_copy = (unsigned char *) s1;
	s2_copy = (unsigned char *) s2;
	while (s1_copy[i] == s2_copy[i] && i + 1 < n)
		i++;
	return (s1_copy[i] - s2_copy[i]);
}
