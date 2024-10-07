/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:39:20 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/07 21:25:37 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_exit_code	read_lines(t_game *game, int fd, char *line);

/*
Gets width, height and number of fishes
*/
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
		game->map->height++;
		free(line);
		line = get_next_line(fd);
	}
	return (error_code);
}
