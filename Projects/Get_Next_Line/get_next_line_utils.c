/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:57:09 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/03/01 21:07:25 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strjoin(char *line, char *buffer, int len)
{
	int		line_len;
	int		buffer_len;
	int		i;
	int		j;
	char	*join;

	printf("JOINline: >%s<\n", line);
	printf("JOINbuffer: >%s<\n", buffer);
	buffer_len = gnl_strlen(buffer);
	if(!line)
		line = "";
	line_len = gnl_strlen(line);
	i = 0;
	j = 0;
	join = malloc((line_len + buffer_len + 1) * sizeof(char));
	if (!join)
		return (0);
	while (line[i])
	{
		join[i] = line[i];
		i++;
	}
	while (buffer[j] && j < len)
		join[i++] = buffer[j++];
	join[i] = 0;
	return (join);
}

int	gnl_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ends_before(char *s, int len)
{
	int	i;

	i = 0;
	while (i <= len)
	{
		if (s[i] == (char) '\n' || !s[i])
			return (i);
		i++;
	}
	return (0);
}

char	*gnl_substr(char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;
	size_t	sub_len;
	size_t	i;

	s_len = gnl_strlen(s);
	sub_len = len + 1;
	if (start > s_len)
		sub_len = 1;
	else if (start + len > s_len)
		sub_len = s_len - start + 1;
	sub = malloc(sub_len * sizeof(char));
	if (!sub)
		return (0);
	i = 0;
	while (start < s_len && i + 1 < sub_len)
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = 0;
	return (sub);
}
