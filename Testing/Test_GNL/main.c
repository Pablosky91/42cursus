/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:26:38 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/18 16:13:17 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include <string.h>

void	leaks()
{
	printf("\n\n\tLEAKS:\n");
	system("leaks test.out");
}

void	read_lines(int fd, int num_lines)
{
	char *line = "";
	int	i = 0;

	while (i < num_lines)
	{
		line = get_next_line(fd);
		printf("(fd %i): %s", fd, line);
		free(line);
		i++;
	}
	if (num_lines < 0)
	{
		while (line)
		{
			line = get_next_line(fd);
			printf("(fd %i): %s", fd, line);
			free(line);
		}
	}
}

int	main(void)
{
	atexit(leaks);
	int fd1 = open("5shorts.txt", O_RDONLY);
	int fd2 = open("3mediums.txt", O_RDONLY);
	int fd3 = open("half.txt", O_RDONLY);

	read_lines(fd1, 1);
	read_lines(fd2, 2);
	read_lines(fd3, -1);
	read_lines(fd1, 2);

	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
