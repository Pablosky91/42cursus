/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:57:13 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/03/01 21:32:36 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//cuando el buffer lee dos lineas a la vez se rompe el programa
//liberar espacio
char	*get_next_line(int fd)
{
	static char *buffer;
	char		*line;
	int			br;
	int			last_pos;
	
	printf("\n\n------->start, buffer: %s\n", buffer);
	br = 1;
	line = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!buffer)
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	line = gnl_strjoin(line, buffer, BUFFER_SIZE);
		printf("line: >%s<\n", line);
	while (br >= 0)
	{
		br = read(fd, buffer, BUFFER_SIZE);
		printf("\tCycle\nbr: %i\n", br);
		printf("buffer: >%s<\n", buffer);
		buffer[br] = 0;
		last_pos = ends_before(buffer, BUFFER_SIZE);
		printf("last_pos: %i\n", last_pos);
		line = gnl_strjoin(line, buffer, last_pos);
		printf("line: >%s<\n", line);
		if(!buffer[0])
		{
			free(buffer);
			return (0);
		}
		if (last_pos != BUFFER_SIZE)
		{
			buffer = gnl_substr(buffer, last_pos + 1, BUFFER_SIZE);
			printf("SUBbuffer: >%s<\n", buffer);
			return (line);
		}
	}
	printf("EXITline: >%s<\n\n", line);
	free(buffer);
	return (0);
}
