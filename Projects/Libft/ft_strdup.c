/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:38:25 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/01/26 23:25:30 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Allocates sufficient memory for a copy of the string s1,
	does the copy, and returns a pointer to it.
The pointer may subsequently be used as an argument to the function free(3).
*/
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
