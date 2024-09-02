/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:32:14 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/09/02 20:24:37 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static const int	IMG_SIZE = 100;
static int	SPEED = 5;

t_cell	get_cell_at(t_game *game, int32_t x, int32_t y)
{
	printf ("%i %i -> %i %i -> %i\n", y, x, y/IMG_SIZE, x/IMG_SIZE, game->map->cells[y / IMG_SIZE][x / IMG_SIZE]);
	return (game->map->cells[y / IMG_SIZE][x / IMG_SIZE]);
}

void	start_penguin_movement(t_game *game, t_direction direction)
{
	game->penguin->still->enabled = false;
	game->penguin->north->enabled = false;
	game->penguin->west->enabled = false;
	game->penguin->south->enabled = false;
	game->penguin->east->enabled = false;
	if (direction == STILL)
		game->penguin->still->enabled = true;
	if (direction == NORTH)
		game->penguin->north->enabled = true;
	if (direction == WEST)
		game->penguin->west->enabled = true;
	if (direction == SOUTH)
		game->penguin->south->enabled = true;
	if (direction == EAST)
		game->penguin->east->enabled = true;
	game->penguin->facing = direction;
}




void	move_img(t_game *game, mlx_image_t *img, t_direction direction)
{
	if (direction == NORTH)
	{
		if (get_cell_at(game, img->instances[0].x, img->instances[0].y - SPEED) == WALL)
			start_penguin_movement(game, STILL);
		else
			img->instances[0].y -= SPEED;
	}
	else if (direction == WEST)
	{
		if (get_cell_at(game, img->instances[0].x -SPEED, img->instances[0].y) == WALL)
			start_penguin_movement(game, STILL);
		else
			img->instances[0].x -= SPEED;
	}
	else if (direction == SOUTH)
	{
		if (get_cell_at(game, img->instances[0].x, img->instances[0].y + SPEED + IMG_SIZE - 1) == WALL)
		{
			
			start_penguin_movement(game, STILL);
		}
		else
			img->instances[0].y += SPEED;
	}
	else if (direction == EAST)
	{
		if (get_cell_at(game, img->instances[0].x + SPEED + IMG_SIZE - 1, img->instances[0].y) == WALL)
			start_penguin_movement(game, STILL);
		else
			img->instances[0].x += SPEED;
	}
}



void	my_loop_hook(void *param)
{
	t_game	*game;

	game = param;
	move_img(game, game->penguin->still, game->penguin->facing);
	move_img(game, game->penguin->north, game->penguin->facing);
	move_img(game, game->penguin->west, game->penguin->facing);
	move_img(game, game->penguin->south, game->penguin->facing);
	move_img(game, game->penguin->east, game->penguin->facing);
	//static int frame = 0;
	//ft_printf("Frame: %i\n", frame++);
	//mlx_put_string(game->mlx, ft_strjoin("Frame: ", ft_itoa(frame)), 50, 50);
}

void	my_key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		free_game(game);
		exit(0);
	}
	if (keydata.key == MLX_KEY_KP_ADD && keydata.action == MLX_PRESS)
		SPEED++;
	if (keydata.key == MLX_KEY_KP_SUBTRACT && keydata.action == MLX_PRESS)
		SPEED--;
	if (keydata.key == MLX_KEY_SPACE)//TODO remove space
		start_penguin_movement(game, STILL);
	if (keydata.action != MLX_PRESS || game->penguin->facing != STILL)
		return ;
	if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		start_penguin_movement(game, NORTH);
	else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		start_penguin_movement(game, WEST);
	else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		start_penguin_movement(game, SOUTH);
	else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		start_penguin_movement(game, EAST);
	else if (keydata.key == MLX_KEY_ESCAPE)
	{
		free_game(game);
		exit(0);
	}
	if (keydata.key == MLX_KEY_SPACE)
		start_penguin_movement(game, STILL);
}

void	create_image(mlx_t *mlx, mlx_image_t **img, char *path, int row, int col)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	*img = mlx_new_image(mlx, texture->width, texture->height);
	*img = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	mlx_resize_image(*img, IMG_SIZE, IMG_SIZE);
	mlx_image_to_window(mlx, *img, col * IMG_SIZE, row * IMG_SIZE);
}

void	print_map(t_game *game)
{
	int			row;
	int			col;
	mlx_image_t	*img;

	game->mlx = mlx_init(game->map->width * IMG_SIZE, game->map->height * IMG_SIZE, "So Long", false);

	row = 0;
	while (row < game->map->height)
	{
		col = 0;
		while (col < game->map->width)
		{
			//ice
			create_image(game->mlx, &img, "textures/ice.png", row, col);
			img->instances[0].z = 1;


			//wall
			if (game->map->cells[row][col] == WALL)
			{
				create_image(game->mlx, &img, "textures/wall.png", row, col);
				img->instances[0].z = 2;
			}

			//penguin
			if (game->map->cells[row][col] == PENGUIN)
			{
				create_image(game->mlx, &(game->penguin->still), "textures/penguin.png", row, col);
				game->penguin->still->instances[0].z = 3;

				create_image(game->mlx, &(game->penguin->north), "textures/slide_up.png", row, col);
				game->penguin->north->enabled = false;
				game->penguin->north->instances[0].z = 3;

				create_image(game->mlx, &(game->penguin->west), "textures/slide_left.png", row, col);
				game->penguin->west->enabled = false;
				game->penguin->west->instances[0].z = 3;

				create_image(game->mlx, &(game->penguin->south), "textures/slide_down.png", row, col);
				game->penguin->south->enabled = false;
				game->penguin->south->instances[0].z = 3;

				create_image(game->mlx, &(game->penguin->east), "textures/slide_right.png", row, col);
				game->penguin->east->enabled = false;
				game->penguin->east->instances[0].z = 3;
			}

			//fish
			if (game->map->cells[row][col] == FISH)
			{
				create_image(game->mlx, &img, "textures/fish.png", row, col);
				img->instances[0].z = 2;
			}

			//exit
			if (game->map->cells[row][col] == HOME)
			{
				create_image(game->mlx, &img, "textures/home.png", row, col);
				img->instances[0].z = 2;
			}

			col++;
		}
		row++;
	}
}
