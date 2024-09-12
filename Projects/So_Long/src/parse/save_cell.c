/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_cell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:52:17 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/09/12 23:14:44 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_exit_code	save_fish(t_game *game, int row, int col);
static t_exit_code	save_penguin(t_game *game, int row, int col);
static t_exit_code	save_home(t_game *game, int row, int col);

t_exit_code	save_cell(t_game *game, char byte, int row, int col)
{
	if (byte != WALL_CHAR && (row == 0 || col == 0
			|| row == game->map->height - 1 || col == game->map->width - 1))
		return (NOT_SURROUNDED);
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
	else
		return (OTHER_CHARACTERS);
	return (OK);
}

static t_exit_code	save_fish(t_game *game, int row, int col)
{
	static int	fish_id = 0;

	game->map->cells[row][col] = FISH;
	game->fishes[fish_id] = ft_calloc(1, sizeof(t_fish));
	if (!game->fishes[fish_id])
		return (NO_ALLOCATION);
	game->fishes[fish_id]->id = fish_id;
	game->fishes[fish_id]->row = row;
	game->fishes[fish_id]->col = col;
	fish_id++;
	return (OK);
}

static t_exit_code	save_penguin(t_game *game, int row, int col)
{
	if (game->initial_row != -1 || game->initial_col != -1)
		return (NO_PLAYER);
	game->initial_row = row;
	game->initial_col = col;
	game->map->cells[row][col] = PENGUIN;
	return (OK);
}

static t_exit_code	save_home(t_game *game, int row, int col)
{
	if (game->home->exists)
		return (NO_EXIT);
	game->map->cells[row][col] = HOME;
	game->home->exists = true;
	return (OK);
}
