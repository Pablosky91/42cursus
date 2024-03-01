/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:26:38 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/03/01 20:06:50 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int fd = open("3mediums.txt", O_RDONLY);
	char *line;

	printf("BUFFER: %d\nfd: %d\n__________\n\n", BUFFER_SIZE, fd);
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		printf("MAINline: %s\n", line);
	}
	close(fd);
	return (0);
}
