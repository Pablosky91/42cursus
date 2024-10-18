/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:27:26 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/18 16:13:24 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	save_map(t_game *game, char *buffer, int fd);
static void	exit_game_free_buffer(t_game *game,
				t_exit_code error, char *buffer);

void	read_map(t_game *game, char *path)
{
	char		*buffer;
	int			fd;
	t_exit_code	error_code;

	check_extension(game, path);
	error_code = get_info_map(game, path);
	if (error_code)
		exit_game(game, error_code);
	game->map->cells = ft_calloc(game->map->height + 1, sizeof(t_cell *));
	if (!game->map->cells)
		exit_game(game, SL_NO_ALLOCATION);
	game->fishes = ft_calloc(game->quantity_fishes + 1, sizeof(t_fish *));
	if (!game->fishes)
		exit_game(game, SL_NO_ALLOCATION);
	fd = open_file(game, path);
	buffer = ft_calloc(1, sizeof(char));
	if (!buffer)
		exit_game(game, SL_NO_ALLOCATION);
	save_map(game, buffer, fd);
	free(buffer);
	if (game->initial_row == -1 || game->initial_col == -1)
		exit_game(game, SL_NO_PLAYER);
	if (!game->home->exists)
		exit_game(game, SL_NO_EXIT);
	valid_path(game);
}

/**
 * @brief Reads the file byte by byte and saves the cell type in the map.
 * 
 * @param game All game information.
 * @param buffer The read buffer.
 * @param fd The file descriptor.
 */
static void	save_map(t_game *game, char *buffer, int fd)
{
	int			row;
	int			col;
	t_exit_code	error_code;

	row = 0;
	while (row < game->map->height)
	{
		col = 0;
		game->map->cells[row] = ft_calloc(game->map->width + 1, sizeof(t_cell));
		if (!game->map->cells[row])
			exit_game_free_buffer(game, SL_NO_ALLOCATION, buffer);
		while (col < game->map->width)
		{
			if (read(fd, buffer, 1) < 0)
				exit_game_free_buffer(game, SL_UNKNOWN, buffer);
			error_code = save_cell(game, buffer[0], row, col);
			if (error_code)
				exit_game_free_buffer(game, error_code, buffer);
			col++;
		}
		read(fd, buffer, 1);
		row++;
	}
}

/**
 * @brief Exits the program in a clean way and frees the read buffer.
 * 
 * @param game All game information.
 * @param error The reason why the program is closed.
 * @param buffer The read buffer to free.
 */
static void	exit_game_free_buffer(t_game *game, t_exit_code error, char *buffer)
{
	free(buffer);
	exit_game(game, error);
}
