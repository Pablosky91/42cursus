/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:57:09 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/18 16:13:24 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*free_and_null(char **s)
{
	if (*s)
	{
		free(*s);
		*s = 0;
	}
	return (0);
}

char	*gnl_strjoin(char *s1, char *s2, size_t len)
{
	size_t		s1_len;
	size_t		s2_len;
	size_t		i;
	size_t		j;
	char		*join;

	s2_len = gnl_strlen(s2, WHOLE_LEN);
	s1_len = gnl_strlen(s1, WHOLE_LEN);
	i = 0;
	j = 0;
	join = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!join)
		return (free_and_null(&s1));
	while (i < s1_len)
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j] && j < len)
		join[i++] = s2[j++];
	join[i] = 0;
	return (free_and_null(&s1), join);
}

size_t	gnl_strlen(char *s, int len_line)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	if (!len_line)
		while (s[i])
			i++;
	else
	{
		while (s[i])
		{
			if (s[i] == (char) '\n')
				return (i);
			i++;
		}
	}
	return (i);
}

char	*gnl_substr(char *s, size_t start, size_t len, int to_free)
{
	char	*sub;
	size_t	s_len;
	size_t	sub_len;
	size_t	i;

	s_len = gnl_strlen(s, WHOLE_LEN);
	sub_len = len + 1;
	if (start > s_len)
		sub_len = 1;
	else if (start + len > s_len)
		sub_len = s_len - start + 1;
	sub = malloc(sub_len * sizeof(char));
	if (!sub)
		return (free_and_null(&s));
	i = 0;
	while (start < s_len && i + 1 < sub_len)
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = 0;
	if (to_free)
		free_and_null(&s);
	return (sub);
}

void	init_empty_string(char	**s)
{
	if (*s)
		return ;
	*s = malloc(1 * sizeof(char));
	if (!*s)
		return ;
	*s[0] = 0;
}
