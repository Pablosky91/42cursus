/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 21:45:21 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/01/31 16:40:57 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char const c, char const *set);

/*
Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters
	specified in ’set’ removed from the beginning and the end of the string.
*/
//printf("%d--->%d_%d-->%d\n", len, i, j, join_len);
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	int		i;
	int		j;
	size_t	join_len;
	char	*trim;

	if (!s1 || !set)
		return (0);
//	printf("start\n");
	len = ft_strlen(s1);
	i = 0;
	while (is_in_set(s1[i], set))
		i++;
	j = len - 1;
	while (is_in_set(s1[j], set) && j > i)
	{
//		printf("j--");
		j--;
	}
	join_len = 1;
	if (i <= j)
		join_len = j - i + 2;
	printf("%d--->%d_%d-->%d\n", len, i, j, join_len);
	trim = ft_calloc(join_len, sizeof(char));
	if (!trim)
		return (0);
	if (join_len > 1)
		trim = ft_substr(s1, i, join_len - 1);
	return (trim);
}

static int	is_in_set(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}
