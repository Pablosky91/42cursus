/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:26:38 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/03/21 16:17:51 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include <string.h>

void leaks()
{
	printf("\n\n\tLEAKS:\n");
	system("leaks test.out");
}

int	main(void)
{
	atexit(leaks);
	int fd = open("empty.txt", O_RDONLY);
	char *line = "";

	printf("BUFFER: %d\nfd: %d\n__________\n\n", BUFFER_SIZE, fd);

	while (line)
	{
		line = get_next_line(fd);
		printf("\tMAINline: %s", line);
		free(line);
	}
	close(fd);
	return (0);
}
