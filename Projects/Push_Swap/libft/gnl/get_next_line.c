/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:57:13 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/18 16:13:17 by pdel-olm         ###   ########.fr       */
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
	len = gnl_strlen(*s, WHOLE_LEN);
	ending = gnl_strlen(*s, LINE_LEN) + 1;
	line = gnl_substr(*s, 0, ending, NOT_TO_FREE);
	if (!line)
		return (free_and_null(s));
	*s = gnl_substr(*s, ending, len, TO_FREE);
	if (!*s)
		return (free_and_null(&line));
	return (line);
}

static char	*loop(int fd, char **content)
{
	int		bytes_read;
	int		last_pos;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free_and_null(content));
	last_pos = BUFFER_SIZE;
	bytes_read = -2;
	while (last_pos == BUFFER_SIZE && bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free_and_null(&buffer), free_and_null(content));
		buffer[bytes_read] = 0;
		*content = gnl_strjoin(*content, buffer, bytes_read);
		if (!*content)
			return (free_and_null(&buffer), free_and_null(content));
		last_pos = gnl_strlen(buffer, LINE_LEN);
	}
	return (free_and_null(&buffer), return_line(content));
}

char	*get_next_line(int fd)
{
	static char	*content[MAX_FD];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	init_empty_string(&content[fd]);
	if (!content[fd])
		return (0);
	if (gnl_strlen(content[fd], WHOLE_LEN) != gnl_strlen(content[fd], LINE_LEN))
		return (return_line(&content[fd]));
	return (loop(fd, &content[fd]));
}
