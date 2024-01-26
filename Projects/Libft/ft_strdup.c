/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:38:25 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/01/26 18:31:20 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	size_t	len;
	char	*copy;

	i = 0;
	len = ft_strlen(s1) + 1;
	copy = malloc((len) * sizeof(char));
	if (!copy)
		return (0);
	ft_memmove(copy, s1, len);
	return (copy);
}
