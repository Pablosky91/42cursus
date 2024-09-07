/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:32:14 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/09/06 22:24:24 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static const int	IMG_SIZE = 100;
static int	SPEED = 10;

t_direction direction_from_to(int32_t from_x, int32_t from_y, int32_t to_x, int32_t to_y)
{
	int32_t	x;
	int32_t	y;

	x = to_x - from_x;
	y = to_y - from_y;
	//TODO abs
	if (y < 0 && abs(x) < abs(y))
		return (NORTH);
	else if (x < 0 && abs(x) > abs(y))
		return (WEST);
	else if (y > 0 && abs(x) < abs(y))
		return (SOUTH);
	else
		return (EAST);
}

void center_of_position(t_position *position, int32_t *x, int32_t *y)
{
	*y = IMG_SIZE * (position->row + 0.5);
	*x = IMG_SIZE * (position->col + 0.5);
}

t_position	pixels_to_position(int32_t x, int32_t y)
{
	t_position	position;

	position.row = y / IMG_SIZE;
	position.col = x / IMG_SIZE;

	return (position);
}

t_cell	get_cell_at(t_game *game, int32_t x, int32_t y)
{
	return (game->map->cells[y / IMG_SIZE][x / IMG_SIZE]);
}

void	start_movement(t_game *game, t_direction direction)
{
	if (game->penguin->facing != STILL)
		return ;
	game->penguin->facing = direction;
	if (get_cell_by(game, pixels_to_position(game->penguin->x, game->penguin->y), game->penguin->facing) != WALL)
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
		if (get_cell_at(game, game->penguin->x, game->penguin->y - SPEED) == WALL)
		{
			game->penguin->y = game->penguin->y / IMG_SIZE * IMG_SIZE;
			game->penguin->facing = STILL;
		}
		else
			game->penguin->y -= SPEED;
	}
	else if (game->penguin->facing == WEST)
	{
		if (get_cell_at(game, game->penguin->x - SPEED, game->penguin->y) == WALL)
		{
			game->penguin->x = game->penguin->x / IMG_SIZE * IMG_SIZE;
			game->penguin->facing = STILL;
		}
		else
			game->penguin->x -= SPEED;
	}
	else if (game->penguin->facing == SOUTH)
	{
		if (get_cell_at(game, game->penguin->x, game->penguin->y + SPEED + IMG_SIZE - 1) == WALL)
		{
			game->penguin->y = ((game->penguin->y - 1) / IMG_SIZE + 1) * IMG_SIZE;
			game->penguin->facing = STILL;
		}
		else
			game->penguin->y += SPEED;
	}
	else if (game->penguin->facing == EAST)
	{
		if (get_cell_at(game, game->penguin->x + SPEED + IMG_SIZE - 1, game->penguin->y) == WALL)
		{
			game->penguin->x = ((game->penguin->x - 1) / IMG_SIZE + 1) * IMG_SIZE;
			game->penguin->facing = STILL;
		}
		else
			game->penguin->x += SPEED;
	}
	show_penguin(game);
}

void	collect_fish(t_game *game)
{
	int	id_fish;

	id_fish = get_id_fish(game, pixels_to_position(game->penguin->x, game->penguin->y));
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
	if (keydata.key == MLX_KEY_KP_ADD && keydata.action != MLX_RELEASE && SPEED < IMG_SIZE - 1)
		SPEED++;
	if (keydata.key == MLX_KEY_KP_SUBTRACT && keydata.action != MLX_RELEASE && SPEED > 1)
		SPEED--;
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

	game = param;
	int32_t	x;
	int32_t	y;
	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS && game->penguin->facing == STILL)
	{
		mlx_get_mouse_pos(game->mlx, &x, &y);
		start_movement(game, direction_from_to(game->penguin->x + IMG_SIZE / 2, game->penguin->y + IMG_SIZE / 2, x, y));
	}
}

void	my_cursor_hook(double x_pos, double y_pos, void* param)
{
	t_game		*game;
	int32_t		x;
	int32_t		y;
	t_direction	direction;

	game = param;
	x = x_pos;
	y = y_pos;
	direction = direction_from_to(game->penguin->x + IMG_SIZE / 2, game->penguin->y + IMG_SIZE / 2, x, y);
	if (direction == NORTH)
		mlx_set_cursor(game->mlx, mlx_create_cursor(mlx_load_png("textures/cursor_up.png")));
	else if (direction == WEST)
		mlx_set_cursor(game->mlx, mlx_create_cursor(mlx_load_png("textures/cursor_left.png")));
	else if (direction == SOUTH)
		mlx_set_cursor(game->mlx, mlx_create_cursor(mlx_load_png("textures/cursor_down.png")));
	else if (direction == EAST)
		mlx_set_cursor(game->mlx, mlx_create_cursor(mlx_load_png("textures/cursor_right.png")));
}

void	my_scroll_hook(double xdelta, double ydelta, void* param)
{
	t_game	*game;

	game = param;
	if (game->penguin->facing != STILL)
		return ;
	if (ydelta > 0)
		start_movement(game, NORTH);
	else if (xdelta < 0)
		start_movement(game, WEST);
	else if (ydelta < 0)
		start_movement(game, SOUTH);
	else
		start_movement(game, EAST);
}

void	create_image(mlx_t *mlx, mlx_image_t **img, char *path, int row, int col, int layer, bool enabled)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	*img = mlx_new_image(mlx, texture->width, texture->height);
	*img = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	mlx_resize_image(*img, IMG_SIZE, IMG_SIZE);
	mlx_image_to_window(mlx, *img, col * IMG_SIZE, row * IMG_SIZE);
	mlx_set_instance_depth(&((*img)->instances[0]), layer);
	(*img)->enabled = enabled;
}

void	print_map(t_game *game)
{
	int			row;
	int			col;
	mlx_image_t	*img;
	int id_fish = 0;
	//mlx_set_setting(MLX_STRETCH_IMAGE, true);
	//mlx_set_setting(MLX_MAXIMIZED, true);
	game->mlx = mlx_init(game->map->width * IMG_SIZE, game->map->height * IMG_SIZE, "So Long", false);
	//mlx_set_cursor_mode(game->mlx, MLX_MOUSE_HIDDEN);
	//mlx_set_cursor(game->mlx, mlx_create_std_cursor(MLX_CURSOR_CROSSHAIR));
	//mlx_set_cursor(game->mlx, mlx_create_cursor(mlx_load_png("textures/penguin.png")));
	mlx_set_icon(game->mlx, mlx_load_png("textures/penguin.png"));
	

	row = 0;
	while (row < game->map->height)
	{
		col = 0;
		while (col < game->map->width)
		{
			create_image(game->mlx, &img, "textures/ice.png", row, col, 1, true);
			if (game->map->cells[row][col] == WALL)
				create_image(game->mlx, &img, "textures/wall.png", row, col, 2, true);
			if (game->map->cells[row][col] == PENGUIN)
			{
				game->penguin->x = col * IMG_SIZE;
				game->penguin->y = row * IMG_SIZE;
				create_image(game->mlx, &(game->penguin->still), "textures/penguin.png", row, col, 3, true);
				create_image(game->mlx, &(game->penguin->north), "textures/slide_up.png", row, col, 3, false);
				create_image(game->mlx, &(game->penguin->west), "textures/slide_left.png", row, col, 3, false);
				create_image(game->mlx, &(game->penguin->south), "textures/slide_down.png", row, col, 3 ,false);
				create_image(game->mlx, &(game->penguin->east), "textures/slide_right.png", row, col, 3, false);
			}
			if (game->map->cells[row][col] == FISH)
			{
				create_image(game->mlx, &(game->fishes[id_fish]->alive), "textures/fish.png", row, col, 2, true);
				create_image(game->mlx, &(game->fishes[id_fish]->dead), "textures/bones.png", row, col, 2, false);
				id_fish++;
			}
			if (game->map->cells[row][col] == HOME)
			{
				create_image(game->mlx, &(game->home->closed), "textures/home_closed.png", row, col, 2, true);
				create_image(game->mlx, &(game->home->open), "textures/home_open.png", row, col, 2, false);
			}
			col++;
		}
		row++;
	}
}
