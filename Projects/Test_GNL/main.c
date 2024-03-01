/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:26:38 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/03/01 12:42:18 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int fd = open("1long.txt", O_RDONLY);
	char	buf[100];
	read(fd, buf, 7);
	printf("%s\n", buf);
	close(fd);
	get_next_line(fd);
	return (0);
}
