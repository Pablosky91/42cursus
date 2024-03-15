/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:57:13 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/03/15 18:18:24 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*return_line(char **s)
{
	char	*line;
	size_t	len;
	size_t	ending;

	if (!*s[0])
	{
		free(*s);
		return (0);
	}
	//printf("s:%s\n", *s);
	len = gnl_strlen(*s);
	ending = ends_before(*s, len) + 1;
	//printf("len:%zu\nending:%zu\n", len, ending);
	line = gnl_substr(*s, 0, ending, 0);
	///////printf("line:>%s<\n", line);
	*s = gnl_substr(*s, ending, len, 1);
	//printf("s2:%s\n", *s);
	//printf("len2:%zu\n", gnl_strlen(*s));
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*remaining = 0;
	char		*buffer;
	//char		*line;
	int			bytes_read;
	int			last_pos;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (remaining)
	{
		//puede que aqui strlen falle si remaining no está NULL terminated
		if (gnl_strlen(remaining) != ends_before(remaining, gnl_strlen(remaining)))
		{
			return (return_line(&remaining));
		}
	}
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
	{
 		if (remaining)
			free(remaining); 
		return (0);
	}
	last_pos = BUFFER_SIZE;
	bytes_read = -2;
	while (last_pos == BUFFER_SIZE && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(remaining);
			free(buffer);
			return (0);
		}
		//if (buffer[bytes_read])
		//	/////printf("c:%c\n", buffer[bytes_read]);
		buffer[bytes_read] = 0;
		remaining = gnl_strjoin(remaining, buffer, bytes_read);
		last_pos = ends_before(buffer, gnl_strlen(remaining));
		///////printf("pos:%i\n", last_pos);
		/////printf("remaining:>%s<\nbuffer:>%s<\n", remaining, buffer);
		/////printf("br:%i\n", bytes_read);
	}
	free(buffer);
	//line = gnl_substr(remaining, 0, ends_before(remaining, gnl_strlen(remaining)), 0);
	//remaining = gnl_substr(remaining, ends_before(remaining, gnl_strlen(remaining)) + 1, gnl_strlen(remaining), 1);
	return (return_line(&remaining));
}








//cuando el buffer lee dos lineas a la vez se rompe el programa
//liberar espacio
/*
char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			br;
	int			last_pos;
	
	///////printf("\n\n------->start, buffer: %s\n", buffer);
	br = 1;
	line = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!buffer)
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	line = gnl_strjoin(line, buffer, BUFFER_SIZE);
		///////printf("line: >%s<\n", line);
	while (br >= 0)
	{
		br = read(fd, buffer, BUFFER_SIZE);
		///////printf("\tCycle\nbr: %i\n", br);
		///////printf("buffer: >%s<\n", buffer);
		buffer[br] = 0;
		last_pos = ends_before(buffer, BUFFER_SIZE);
		///////printf("last_pos: %i\n", last_pos);
		line = gnl_strjoin(line, buffer, last_pos);
		///////printf("line: >%s<\n", line);
		if(!buffer[0])
		{
			free(buffer);
			return (0);
		}
		if (last_pos != BUFFER_SIZE)
		{
			buffer = gnl_substr(buffer, last_pos + 1, BUFFER_SIZE);
			///////printf("SUBbuffer: >%s<\n", buffer);
			return (line);
		}
	}
	///////printf("EXITline: >%s<\n\n", line);
	free(buffer);
	return (0);
}
*/
