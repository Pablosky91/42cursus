/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_cell_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:27:32 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/18 16:13:24 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static t_exit_code	save_fish(t_game *game, int row, int col);
static t_exit_code	save_penguin(t_game *game, int row, int col);
static t_exit_code	save_home(t_game *game, int row, int col);
static t_exit_code	save_seal(t_game *game, int row, int col);

t_exit_code	save_cell(t_game *game, char byte, int row, int col)
{
	if (byte != WALL_CHAR && (row == 0 || col == 0
			|| row == game->map->height - 1 || col == game->map->width - 1))
		return (SL_NOT_SURROUNDED);
	if (byte == WALL_CHAR)
		game->map->cells[row][col] = WALL;
	else if (byte == ICE_CHAR)
		game->map->cells[row][col] = ICE;
	else if (byte == FISH_CHAR)
		return (save_fish(game, row, col));
	else if (byte == PENGUIN_CHAR)
		return (save_penguin(game, row, col));
	else if (byte == HOME_CHAR)
		return (save_home(game, row, col));
	else if (byte == SEAL_CHAR)
		return (save_seal(game, row, col));
	else
		return (SL_OTHER_CHARACTERS);
	return (SL_OK);
}

/**
 * @brief Saves a fish in the map structure.
 * 
 * @param game All game information.
 * @param row The row of the map where to save.
 * @param col The column of the map where to save.
 * @return Exit code (type of error or success).
 */
static t_exit_code	save_fish(t_game *game, int row, int col)
{
	static int	fish_id = 0;

	game->map->cells[row][col] = FISH;
	game->fishes[fish_id] = ft_calloc(1, sizeof(t_fish));
	if (!game->fishes[fish_id])
		return (SL_NO_ALLOCATION);
	game->fishes[fish_id]->id = fish_id;
	game->fishes[fish_id]->row = row;
	game->fishes[fish_id]->col = col;
	fish_id++;
	return (SL_OK);
}

/**
 * @brief Saves the penguin in the map structure.
 * 
 * @param game All game information.
 * @param row The row of the map where to save.
 * @param col The column of the map where to save.
 * @return Exit code (type of error or success).
 */
static t_exit_code	save_penguin(t_game *game, int row, int col)
{
	if (game->initial_row != -1 || game->initial_col != -1)
		return (SL_NO_PLAYER);
	game->initial_row = row;
	game->initial_col = col;
	game->map->cells[row][col] = PENGUIN;
	return (SL_OK);
}

/**
 * @brief Saves the home in the map structure.
 * 
 * @param game All game information.
 * @param row The row of the map where to save.
 * @param col The column of the map where to save.
 * @return Exit code (type of error or success).
 */
static t_exit_code	save_home(t_game *game, int row, int col)
{
	if (game->home->exists)
		return (SL_NO_EXIT);
	game->map->cells[row][col] = HOME;
	game->home->exists = true;
	return (SL_OK);
}

/**
 * @brief Saves a seal in the map structure.
 * 
 * @param game All game information.
 * @param row The row of the map where to save.
 * @param col The column of the map where to save.
 * @return Exit code (type of error or success).
 */
static t_exit_code	save_seal(t_game *game, int row, int col)
{
	game->map->cells[row][col] = SEAL;
	return (SL_OK);
}