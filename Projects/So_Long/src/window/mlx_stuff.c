/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:32:14 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/09/12 23:21:37 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static const int	IMG_SIZE = 100;
static int	SPEED = 10;

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
	game->penguin->facing = direction;
	pixels_to_position(game, game->penguin->x, game->penguin->y, &row, &col);
	if (get_cell_by(game, row, col, game->penguin->facing) != WALL)
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
	if (game->penguin->facing == NORTH)
	{
		game->penguin->north->instances[0].x = game->penguin->x;
		game->penguin->north->instances[0].y = game->penguin->y;
		game->penguin->north->enabled = true;
	}
	if (game->penguin->facing == WEST)
	{
		game->penguin->west->instances[0].x = game->penguin->x;
		game->penguin->west->instances[0].y = game->penguin->y;
		game->penguin->west->enabled = true;
	}
	if (game->penguin->facing == SOUTH)
	{
		game->penguin->south->instances[0].x = game->penguin->x;
		game->penguin->south->instances[0].y = game->penguin->y;
		game->penguin->south->enabled = true;
	}
	if (game->penguin->facing == EAST)
	{
		game->penguin->east->instances[0].x = game->penguin->x;
		game->penguin->east->instances[0].y = game->penguin->y;
		game->penguin->east->enabled = true;
	}
}

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

void	my_loop_hook(void *param)
{
	t_game	*game;

	game = param;
	move_penguin(game);
	collect_fish(game);
	enter_home(game);
	//static int frame = 0;
	//ft_printf("Frame: %i\n", frame++);
	//mlx_put_string(game->mlx, ft_strjoin("Frame: ", ft_itoa(frame)), 50, 50);
}

void	my_key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE)
		exit_game(game, OK);
	if (keydata.key == MLX_KEY_KP_ADD && keydata.action != MLX_RELEASE && game->speed < game->img_size - 1)
		game->speed++;
	if (keydata.key == MLX_KEY_KP_SUBTRACT && keydata.action != MLX_RELEASE && game->speed > 1)
		game->speed--;
	if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS && game->moves != 0)
		retry(game);
	if (keydata.action != MLX_PRESS || game->penguin->facing != STILL)
		return ;
	if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		start_movement(game, NORTH);
	else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		start_movement(game, WEST);
	else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		start_movement(game, SOUTH);
	else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		start_movement(game, EAST);
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


void	create_image(t_game *game, mlx_image_t **img, char *path, int row, int col, int layer, bool enabled)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	*img = mlx_new_image(game->mlx, texture->width, texture->height);
	*img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	mlx_resize_image(*img, game->img_size, game->img_size);
	mlx_image_to_window(game->mlx, *img, col * game->img_size, row * game->img_size);
	mlx_set_instance_depth(&((*img)->instances[0]), layer);
	(*img)->enabled = enabled;
}

void	print_map(t_game *game)
{
	int			row;
	int			col;
	mlx_image_t	*img;
	int id_fish = 0;
	// mlx_set_setting(MLX_STRETCH_IMAGE, true);
	// mlx_set_setting(MLX_FULLSCREEN, true);
	game->mlx = mlx_init(game->map->width * game->img_size, game->map->height * game->img_size, "So Long", false);
	mlx_texture_t	*texture = mlx_load_png("textures/penguin.png");
	mlx_set_icon(game->mlx, texture);
	mlx_delete_texture(texture);
	int32_t	width = 5, height = 7;
	mlx_get_monitor_size(0, &width, &height);
	ft_printf("monitor width: %i, height: %i\n", width, height);
	ft_printf("screen width: %i, height: %i\n", game->mlx->width, game->mlx->height);
	row = 0;
	while (row < game->map->height)
	{
		col = 0;
		while (col < game->map->width)
		{
			create_image(game, &img, "textures/ice.png", row, col, 1, true);
			if (game->map->cells[row][col] == WALL)
				create_image(game, &img, "textures/wall.png", row, col, 2, true);
			if (game->map->cells[row][col] == PENGUIN)
			{
				game->penguin->y = row * game->img_size;
				game->penguin->x = col * game->img_size;
				create_image(game, &(game->penguin->still), "textures/penguin.png", row, col, 3, true);
				create_image(game, &(game->penguin->north), "textures/slide_up.png", row, col, 3, false);
				create_image(game, &(game->penguin->west), "textures/slide_left.png", row, col, 3, false);
				create_image(game, &(game->penguin->south), "textures/slide_down.png", row, col, 3, false);
				create_image(game, &(game->penguin->east), "textures/slide_right.png", row, col, 3, false);
			}
			if (game->map->cells[row][col] == FISH)
			{
				create_image(game, &(game->fishes[id_fish]->alive), "textures/fish.png", row, col, 2, true);
				create_image(game, &(game->fishes[id_fish]->dead), "textures/bones.png", row, col, 2, false);
				id_fish++;
			}
			if (game->map->cells[row][col] == HOME)
			{
				create_image(game, &(game->home->closed), "textures/home_closed.png", row, col, 2, true);
				create_image(game, &(game->home->open), "textures/home_open.png", row, col, 2, false);
			}
			col++;
		}
		row++;
	}
}
