/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 11:46:39 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/09/12 22:18:38 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(t_game *game, char *path)
{
	char	*buffer;
	int		row;
	int		col;
	int		fd;
	t_error	error_code;

	check_extension(game, path);
	error_code = get_info_map(game, path);
	if (error_code)
		exit_game(game, error_code);
	game->map->cells = ft_calloc(game->map->height + 1, sizeof(t_cell *));
	if (!game->map->cells)
		exit_game(game, NO_ALLOCATION);
	game->fishes = ft_calloc(game->quantity_fishes + 1, sizeof(t_fish *));
	if (!game->fishes)
		exit_game(game, NO_ALLOCATION);
	fd = open_file(game, path);
	buffer = ft_calloc(1, sizeof(char));
	if (!buffer)
		exit_game(game, NO_ALLOCATION);
	row = 0;
	while (row < game->map->height)
	{
		col = 0;
		game->map->cells[row] = ft_calloc(game->map->width + 1, sizeof(t_cell));
		if (!game->map->cells[row])
		{
			free(buffer);
			exit_game(game, NO_ALLOCATION);
		}
		while (col < game->map->width)
		{
			if (read(fd, buffer, 1) < 0)
			{
				free(buffer);
				exit_game(game, UNKNOWN);
			}
			error_code = save_cell(game, buffer[0], row, col);
			if (error_code)
			{
				free(buffer);
				exit_game(game, error_code);
			}
			col++;
		}
		read(fd, buffer, 1);
		row++;
	}
	free(buffer);
	//if (!game->initial_pos)
	if (game->initial_row == -1 || game->initial_col == -1)
		exit_game(game, NO_PLAYER);
	if (!game->home->exists)
		exit_game(game, NO_EXIT);
	valid_path(game);
}
