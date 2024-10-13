/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_penguin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:32:14 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/13 12:03:06 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int		get_id_fish_exit(t_game *game,
					t_direction moving, int32_t x, int32_t y);
static void		goes_into_wall(t_game *game,
					t_direction direction, int32_t *x, int32_t *y);
static t_cell	get_cell_at(t_game *game, int32_t x, int32_t y);

int	move_penguin(t_game *game,
		t_direction moving, int32_t x, int32_t y)
{
	int	id_before;
	int	id_after;

	id_before = get_id_fish_exit(game, moving, x, y);
	if (moving == NORTH)
		y -= game->speed;
	else if (moving == WEST)
		x -= game->speed;
	else if (moving == SOUTH)
		y += game->speed;
	else if (moving == EAST)
		x += game->speed;
	id_after = get_id_fish_exit(game, moving, x, y);
	goes_into_wall(game, moving, &x, &y);
	game->penguin->x = x;
	game->penguin->y = y;
	if (id_before != id_after)
		return (id_before);
	return (-1);
}

/**
 * @brief Gets the id of a cell where a pixel is located.
 * 
 * @param game All game information.
 * @param moving Direction in which the penguin is moving.
 * @param x X ordinate of the pixel.
 * @param y Y ordinate of the pixel.
 * @return If there is a fish, its id. If it is the home, -HOME.
 * Any other cell -1.
 */
static int	get_id_fish_exit(t_game *game,
				t_direction moving, int32_t x, int32_t y)
{
	if ((moving == NORTH || moving == WEST) && get_cell_at(game, x, y) == HOME)
		return (-HOME);
	if ((moving == SOUTH || moving == EAST) && get_cell_at(game,
			x + game->img_size - 1, y + game->img_size - 1) == HOME)
		return (-HOME);
	if (moving == NORTH || moving == WEST)
		return (get_id_fish(game, y / game->img_size, x / game->img_size));
	if (moving == SOUTH || moving == EAST)
		return (get_id_fish(game, (y + game->img_size - 1) / game->img_size,
				(x + game->img_size - 1) / game->img_size));
	return (-1);
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
