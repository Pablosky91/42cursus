/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:27:13 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/11/15 11:10:32 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static t_exit_code	read_lines(t_game *game, int fd, char *line);

t_exit_code	get_info_map(t_game *game, char *path)
{
	char		*line;
	int			fd;
	t_exit_code	error_code;

	fd = open_file(game, path);
	line = get_next_line(fd);
	if (!line)
		return (SL_NOT_SURROUNDED);
	game->map->width = ft_strlen(line);
	if (line[ft_strlen(line) - 1] == '\n')
		game->map->width--;
	error_code = read_lines(game, fd, line);
	if (!game->quantity_fishes)
		error_code = SL_NO_COIN;
	close(fd);
	return (error_code);
}

/**
 * @brief Reads all lines to compare their width and know how many are there.
 * It also counts the fishes.
 * 
 * @param game All game information.
 * @param fd The file descriptor.
 * @param line The first line of the file.
 * @return Exit code (type of error or success).
 */
static t_exit_code	read_lines(t_game *game, int fd, char *line)
{
	int			length;
	t_exit_code	error_code;

	error_code = SL_OK;
	while (line)
	{
		length = ft_strlen(line);
		if ((line[length - 1] != '\n' || length - 1 != game->map->width)
			&& (line[length - 1] == '\n' || length != game->map->width))
			error_code = SL_NOT_RECTANGULAR;
		game->quantity_fishes += ft_count_char(line, FISH_CHAR);
		game->quantity_seals += ft_count_char(line, SEAL_CHAR);
		game->map->height++;
		free(line);
		line = get_next_line(fd);
	}
	return (error_code);
}
