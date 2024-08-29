/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:58:30 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/08/29 16:58:54 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
