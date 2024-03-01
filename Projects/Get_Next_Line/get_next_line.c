/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:57:13 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/03/01 17:06:24 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;
	int			br;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!line)
		return (0);
	br = read(fd, line, BUFFER_SIZE);
	printf("br: %i\n", br);
	if (br <= 0)
		return (0);
	line[br] = 0;
	printf("line: >%s<\n\n", line);
	return (line);
}
