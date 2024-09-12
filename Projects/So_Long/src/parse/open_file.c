/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:58:13 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/09/12 12:58:18 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_file(t_game *game, char *path)
{
	int	fd;

	errno = 0;
	fd = open(path, O_RDWR);
	if (errno == ENOENT)
		exit_game(game, INEXISTENT_FILE);
	else if (errno == EISDIR)
		exit_game(game, FILE_IS_DIRECTORY);
	close(fd);
	fd = open(path, O_RDONLY);
	if (errno == EACCES)
		exit_game(game, FILE_NO_PERMISSION);
	if (errno)
		exit_game(game, UNKNOWN);
	return (fd);
}
