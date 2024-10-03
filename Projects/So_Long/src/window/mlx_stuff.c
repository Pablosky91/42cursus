/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:32:14 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/03 16:28:52 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	center_of_position(t_game *game, int row, int col, int32_t *x, int32_t *y)
{
	*y = game->img_size * (row + 0.5);
	*x = game->img_size * (col + 0.5);
}

void	pixels_to_position(t_game *game, int32_t x, int32_t y, int *row, int *col)
{
	*row = y / game->img_size;
	*col = x / game->img_size;
}

t_cell	get_cell_at(t_game *game, int32_t x, int32_t y)
{
	return (game->map->cells[y / game->img_size][x / game->img_size]);
}

void	start_movement(t_game *game, t_direction direction)
{
	int	row;
	int	col;

	if (game->penguin->facing != STILL)
		return ;
	pixels_to_position(game, game->penguin->x, game->penguin->y, &row, &col);
	if (get_cell_by(game, row, col, direction) == WALL)
		return ;
	game->penguin->facing = direction;
	ft_printf("Moves: %i\n", ++game->moves);
}

void	show_penguin(t_game *game)
{
	game->penguin->still->enabled = false;
	game->penguin->north->enabled = false;
	game->penguin->west->enabled = false;
	game->penguin->south->enabled = false;
	game->penguin->east->enabled = false;
	if (game->penguin->facing == STILL)
	{
		game->penguin->still->instances[0].x = game->penguin->x;
		game->penguin->still->instances[0].y = game->penguin->y;
		game->penguin->still->enabled = true;
	}
	else if (game->penguin->facing == NORTH)
	{
		game->penguin->north->instances[0].x = game->penguin->x;
		game->penguin->north->instances[0].y = game->penguin->y;
		game->penguin->north->enabled = true;
	}
	else if (game->penguin->facing == WEST)
	{
		game->penguin->west->instances[0].x = game->penguin->x;
		game->penguin->west->instances[0].y = game->penguin->y;
		game->penguin->west->enabled = true;
	}
	else if (game->penguin->facing == SOUTH)
	{
		game->penguin->south->instances[0].x = game->penguin->x;
		game->penguin->south->instances[0].y = game->penguin->y;
		game->penguin->south->enabled = true;
	}
	else if (game->penguin->facing == EAST)
	{
		game->penguin->east->instances[0].x = game->penguin->x;
		game->penguin->east->instances[0].y = game->penguin->y;
		game->penguin->east->enabled = true;
	}
}

//TODO movement based on the center
void	move_penguin(t_game *game)
{
	if (game->penguin->facing == NORTH)
	{
		if (get_cell_at(game, game->penguin->x, game->penguin->y - game->speed) == WALL)
		{
			game->penguin->y = game->penguin->y / game->img_size * game->img_size;
			game->penguin->facing = STILL;
		}
		else
			game->penguin->y -= game->speed;
	}
	else if (game->penguin->facing == WEST)
	{
		if (get_cell_at(game, game->penguin->x - game->speed, game->penguin->y) == WALL)
		{
			game->penguin->x = game->penguin->x / game->img_size * game->img_size;
			game->penguin->facing = STILL;
		}
		else
			game->penguin->x -= game->speed;
	}
	else if (game->penguin->facing == SOUTH)
	{
		if (get_cell_at(game, game->penguin->x, game->penguin->y + game->speed + game->img_size - 1) == WALL)
		{
			game->penguin->y = ((game->penguin->y - 1) / game->img_size + 1) * game->img_size;
			game->penguin->facing = STILL;
		}
		else
			game->penguin->y += game->speed;
	}
	else if (game->penguin->facing == EAST)
	{
		if (get_cell_at(game, game->penguin->x + game->speed + game->img_size - 1, game->penguin->y) == WALL)
		{
			game->penguin->x = ((game->penguin->x - 1) / game->img_size + 1) * game->img_size;
			game->penguin->facing = STILL;
		}
		else
			game->penguin->x += game->speed;
	}
	show_penguin(game);
}

void	collect_fish(t_game *game)
{
	int	id_fish;
	int	row;
	int	col;

	pixels_to_position(game, game->penguin->x, game->penguin->y, &row, &col);
	id_fish = get_id_fish(game, row, col);
	if (id_fish != -1 && !game->fishes[id_fish]->collected)
	{
		game->fishes[id_fish]->alive->enabled = false;
		game->fishes[id_fish]->dead->enabled = true;
		game->fishes[id_fish]->collected = true;
		game->collected_fishes++;
		if (game->collected_fishes == game->quantity_fishes)
		{
			game->home->closed->enabled = false;
			game->home->open->enabled = true;
		}
	}
}

void	enter_home(t_game *game)
{
	if (game->collected_fishes == game->quantity_fishes && get_cell_at(game, game->penguin->x, game->penguin->y) == HOME)
		exit_game(game, OK);
}
