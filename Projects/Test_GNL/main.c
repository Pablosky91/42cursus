/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:26:38 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/03/01 16:07:12 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int fd = open("5shorts.txt", O_RDONLY);
	char *line;

	printf("BUFFER: %d\n", BUFFER_SIZE);
	printf("fd: %d\n", fd);
	line = "";
	while (line)
		line = get_next_line(fd);
	close(fd);
	return (0);
}
