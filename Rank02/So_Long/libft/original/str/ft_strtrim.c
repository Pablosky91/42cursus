/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 21:45:21 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/18 16:13:17 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char const c, char const *set);

/*
Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters
	specified in ’set’ removed from the beginning and the end of the string.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	first;
	size_t	last;
	size_t	join_len;
	char	*trim;

	if (!s1 || !set)
		return (0);
	len = ft_strlen(s1);
	first = 0;
	while (is_in_set(s1[first], set))
		first++;
	last = len - 1;
	while (is_in_set(s1[last], set) && last > first)
		last--;
	join_len = 0;
	if (first <= last)
		join_len = last - first + 1;
	trim = ft_substr(s1, first, join_len);
	if (!trim)
		return (0);
	return (trim);
}

static int	is_in_set(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}
