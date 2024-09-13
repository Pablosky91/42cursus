/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:32:14 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/09/13 21:52:11 by pdel-olm         ###   ########.fr       */
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
	int row;
	int col;

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

/* 
t_direction	direction_from_to(int32_t from_x, int32_t from_y, int32_t to_x, int32_t to_y)
{
	double	x;
	double	y;

	x = to_x - from_x;
	y = to_y - from_y;
	if (y < 0 && fabs(x) < fabs(y))
		return (NORTH);
	else if (x < 0 && fabs(x) > fabs(y))
		return (WEST);
	else if (y > 0 && fabs(x) < fabs(y))
		return (SOUTH);
	else
		return (EAST);
}

void	retry(t_game *game)
{
	int	id_fish;

	game->penguin->y = game->initial_row * game->img_size;
	game->penguin->x = game->initial_col * game->img_size;
	game->penguin->facing = STILL;
	id_fish = 0;

	while (id_fish < game->quantity_fishes)
	{
		game->fishes[id_fish]->alive->enabled = true;
		game->fishes[id_fish]->dead->enabled = false;
		game->fishes[id_fish]->collected = false;
		id_fish++;
	}
	game->collected_fishes = 0;
	game->home->closed->enabled = true;
	game->home->open->enabled = false;
	game->moves = 0;
	ft_printf("---------\n");
}

void	my_mouse_hook(mouse_key_t button, action_t action, modifier_key_t mods, void *param)
{
	t_game	*game;
	int32_t	x;
	int32_t	y;

	game = param;
	(void) mods;
	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS && game->penguin->facing == STILL)
	{
		mlx_get_mouse_pos(game->mlx, &x, &y);
		start_movement(game, direction_from_to(game->penguin->x + game->img_size / 2, game->penguin->y + game->img_size / 2, x, y));
	}
}

void	my_cursor_hook(double x_pos, double y_pos, void *param)
{
	t_game		*game;
	int32_t		x;
	int32_t		y;
	t_direction	direction;

	game = param;
	x = x_pos;
	y = y_pos;
	direction = direction_from_to(game->penguin->x + game->img_size / 2, game->penguin->y + game->img_size / 2, x, y);
	if (direction == NORTH)
		mlx_set_cursor(game->mlx, mlx_create_cursor(mlx_load_png("textures/cursor_up.png")));
	else if (direction == WEST)
		mlx_set_cursor(game->mlx, mlx_create_cursor(mlx_load_png("textures/cursor_left.png")));
	else if (direction == SOUTH)
		mlx_set_cursor(game->mlx, mlx_create_cursor(mlx_load_png("textures/cursor_down.png")));
	else if (direction == EAST)
		mlx_set_cursor(game->mlx, mlx_create_cursor(mlx_load_png("textures/cursor_right.png")));
}

void	my_scroll_hook(double x_delta, double y_delta, void *param)
{
	t_game	*game;

	game = param;
	if (game->penguin->facing != STILL)
		return ;
	if (y_delta > 0)
		start_movement(game, NORTH);
	else if (x_delta > 0)
		start_movement(game, WEST);
	else if (y_delta < 0)
		start_movement(game, SOUTH);
	else
		start_movement(game, EAST);
}
 */
