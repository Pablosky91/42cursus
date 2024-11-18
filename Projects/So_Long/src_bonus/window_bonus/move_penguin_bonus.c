/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_penguin_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:29:13 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/11/18 19:32:54 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static t_id_cell	get_id_cell(t_game *game,
					t_direction moving, int32_t x, int32_t y);
static void			goes_into_wall(t_game *game,
					t_direction direction, int32_t *x, int32_t *y);
static t_cell		get_cell_at(t_game *game, int32_t x, int32_t y);

t_id_cell	move_penguin(t_game *game,
		t_direction moving, int32_t x, int32_t y)
{
	t_id_cell	id_before;
	t_id_cell	id_after;

	id_before = get_id_cell(game, moving, x, y);
	if (moving == NORTH)
		y -= game->speed;
	else if (moving == WEST)
		x -= game->speed;
	else if (moving == SOUTH)
		y += game->speed;
	else if (moving == EAST)
		x += game->speed;
	id_after = get_id_cell(game, moving, x, y);
	goes_into_wall(game, moving, &x, &y);
	game->penguin->x = x;
	game->penguin->y = y;
	if (id_before.type != id_after.type || id_before.id != id_after.id)
		return (id_before);
	id_after.id = -1;
	id_after.type = ICE;
	return (id_after);
}

//TODO redo doc
/**
 * @brief Gets the id of a cell where a pixel is located.
 * 
 * @param game All game information.
 * @param moving Direction in which the penguin is moving.
 * @param x X ordinate of the pixel.
 * @param y Y ordinate of the pixel.
 * @return If there is a fish, its id. If it is the home, -HOME.
 * If it is a seal, -SEAL. Any other cell -1.
 */
static t_id_cell	get_id_cell(t_game *game,
				t_direction moving, int32_t x, int32_t y)
{
	t_id_cell	id_cell;
	int32_t		coord_x;
	int32_t		coord_y;

	coord_x = x;
	coord_y = y;
	if (moving == SOUTH || moving == EAST)
	{
		coord_x = x + game->img_size - 1;
		coord_y = y + game->img_size - 1;
	}
	id_cell.id = -1;
	id_cell.type = get_cell_at(game, coord_x, coord_y);
	if (id_cell.type == SEAL)
		id_cell.id = get_id_seal(game,
				coord_y / game->img_size, coord_x / game->img_size);
	if (id_cell.type == FISH)
		id_cell.id = get_id_fish(game,
				coord_y / game->img_size, coord_x / game->img_size);
	return (id_cell);
}

/**
 * @brief Checks if the penguin entered a wall and relocates it.
 * 
 * @param game All game information.
 * @param direction Direction in which the penguin is moving.
 * @param x X ordinate of the penguin.
 * @param y Y ordinate of the penguin.
 */
static void	goes_into_wall(t_game *game,
				t_direction direction, int32_t *x, int32_t *y)
{
	if ((direction == NORTH || direction == WEST)
		&& get_cell_at(game, *x, *y) != WALL)
		return ;
	if ((direction == SOUTH || direction == EAST) && get_cell_at(game,
			*x + game->img_size - 1, *y + game->img_size - 1) != WALL)
		return ;
	if (direction == NORTH)
		*y = (*y + game->speed) / game->img_size * game->img_size;
	else if (direction == WEST)
		*x = (*x + game->speed) / game->img_size * game->img_size;
	else if (direction == SOUTH)
		*y = ((*y - game->speed - 1) / game->img_size + 1) * game->img_size;
	else if (direction == EAST)
		*x = ((*x - game->speed - 1) / game->img_size + 1) * game->img_size;
	game->penguin->facing = STILL;
}

/**
 * @brief Gets the cell type of the cell in which a pixel is located.
 * 
 * @param game All game information.
 * @param x X ordinate of the pixel.
 * @param y Y ordinate of the pixel.
 * @return The type of cell.
 */
static t_cell	get_cell_at(t_game *game, int32_t x, int32_t y)
{
	return (game->map->cells[y / game->img_size][x / game->img_size]);
}
