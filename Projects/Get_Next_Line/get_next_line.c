/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:57:13 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/03/22 18:29:12 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*return_line(char **s)
{
	char	*line;
	size_t	len;
	size_t	ending;

	if (!*s[0])
		return (free_and_null(s));
	len = gnl_strlen(*s, 0);
	ending = gnl_strlen(*s, 1) + 1;
	line = gnl_substr(*s, 0, ending, 0);
	if (!line)
		return (free_and_null(s));
	*s = gnl_substr(*s, ending, len, 1);
	if (!*s)
		return (free_and_null(&line));
	return (line);
}

/*static */char	*loop(/*int fd, char *content, char *buffer*/)
{
	int	bytes_read;
	int	last_pos;

	last_pos = BUFFER_SIZE;
	bytes_read = -2;
	
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*content;
	char		*buffer;
	int			bytes_read;
	int			last_pos;

	init_empty_string(&content);
	if (!content || fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (gnl_strlen(content, 0) != gnl_strlen(content, 1))
		return (return_line(&content));
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free_and_null(&content));
	last_pos = BUFFER_SIZE;
	bytes_read = -2;
	while (last_pos == BUFFER_SIZE && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free_and_null(&buffer), free_and_null(&content));
		buffer[bytes_read] = 0;
		content = gnl_strjoin(content, buffer, bytes_read);
		if (!content)
			return (free_and_null(&buffer), free_and_null(&content));
		last_pos = gnl_strlen(buffer, 1);
	}
	return (free_and_null(&buffer), return_line(&content));
}
