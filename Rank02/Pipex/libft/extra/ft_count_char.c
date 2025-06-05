/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:58:30 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/02/11 00:13:55 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Counts the number of occurrences of c (converted to a char)
	in the string pointed to by s.
*/
size_t	ft_count_char(char *s, int c)
{
	size_t	i;
	size_t	len;
	size_t	count;

	i = 0;
	len = ft_strlen(s);
	count = 0;
	while (i <= len)
	{
		if (s[i] == (char) c)
			count++;
		i++;
	}
	return (count);
}
