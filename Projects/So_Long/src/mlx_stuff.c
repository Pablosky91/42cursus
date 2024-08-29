/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:32:14 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/08/29 16:04:01 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static const int IMG_SIZE = 128;
static const int SPEED = 12;

void	my_loop_hook(void* param)
{
	t_game *game = param;

	if (game->penguin->facing == up)
	{
		game->penguin->still->instances[0].y -= SPEED;
		game->penguin->up->instances[0].y -= SPEED;
		game->penguin->left->instances[0].y -= SPEED;
		game->penguin->down->instances[0].y -= SPEED;
		game->penguin->right->instances[0].y -= SPEED;
	}
	if (game->penguin->facing == left)
	{
		game->penguin->still->instances[0].x -= SPEED;
		game->penguin->up->instances[0].x -= SPEED;
		game->penguin->left->instances[0].x -= SPEED;
		game->penguin->down->instances[0].x -= SPEED;
		game->penguin->right->instances[0].x -= SPEED;
	}
	if (game->penguin->facing == down)
	{
		game->penguin->still->instances[0].y += SPEED;
		game->penguin->up->instances[0].y += SPEED;
		game->penguin->left->instances[0].y += SPEED;
		game->penguin->down->instances[0].y += SPEED;
		game->penguin->right->instances[0].y += SPEED;
	}
	if (game->penguin->facing == right)
	{
		game->penguin->still->instances[0].x += SPEED;
		game->penguin->up->instances[0].x += SPEED;
		game->penguin->left->instances[0].x += SPEED;
		game->penguin->down->instances[0].x += SPEED;
		game->penguin->right->instances[0].x += SPEED;
	}
}

void	move_penguin(t_game *game, t_direction direction)
{
	game->penguin->still->enabled = false;
	game->penguin->up->enabled = false;
	game->penguin->left->enabled = false;
	game->penguin->down->enabled = false;
	game->penguin->right->enabled = false;
	if (direction == still)
		game->penguin->still->enabled = true;
	if (direction == up)
		game->penguin->up->enabled = true;
	if (direction == left)
		game->penguin->left->enabled = true;
	if (direction == down)
		game->penguin->down->enabled = true;
	if (direction == right)
		game->penguin->right->enabled = true;
	game->penguin->facing = direction;
}

void	my_key_hook(mlx_key_data_t keydata, void* param)
{
	t_game *game = param;

	if (keydata.action != MLX_PRESS)
		return ;
	if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		move_penguin(game, up);
	else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		move_penguin(game, left);
	else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		move_penguin(game, down);
	else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		move_penguin(game, right);
	else if (keydata.key == MLX_KEY_ESCAPE && !game->penguin->facing)
	{
		free_game(game);
		exit(0);
	}
	else if (keydata.key == MLX_KEY_ESCAPE)
		move_penguin(game, still);
}

void create_image(mlx_t *mlx, mlx_image_t **img, char *path, __u_int	row, __u_int	col)
{
	mlx_texture_t *texture = mlx_load_png(path);
	*img = mlx_new_image(mlx, texture->width, texture->height);
	*img = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	mlx_resize_image(*img, IMG_SIZE, IMG_SIZE);
	mlx_image_to_window(mlx, *img, col * IMG_SIZE, row * IMG_SIZE);
}

void	print_map(t_game *game)
{
	__u_int	row;
	__u_int	col;
	mlx_image_t	*img;
	mlx_texture_t *texture;

	game->mlx = mlx_init(game->map->width * IMG_SIZE, game->map->height * IMG_SIZE, "So Long", true);

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
			if (game->map->cells[row][col] == wall)
			{
				create_image(game->mlx, &img, "textures/wall.png", row, col);
				img->instances[0].z = 2;
			}

			//penguin
			if (game->map->cells[row][col] == penguin)
			{
				create_image(game->mlx, &(game->penguin->still), "textures/penguin.png", row, col);
				game->penguin->still->instances[0].z = 3;
				
				create_image(game->mlx, &(game->penguin->up), "textures/slide_up.png", row, col);
				game->penguin->up->enabled = false;
				game->penguin->up->instances[0].z = 3;

				create_image(game->mlx, &(game->penguin->left), "textures/slide_left.png", row, col);
				game->penguin->left->enabled = false;
				game->penguin->left->instances[0].z = 3;

				create_image(game->mlx, &(game->penguin->down), "textures/slide_down.png", row, col);
				game->penguin->down->enabled = false;
				game->penguin->down->instances[0].z = 3;

				create_image(game->mlx, &(game->penguin->right), "textures/slide_right.png", row, col);
				game->penguin->right->enabled = false;
				game->penguin->right->instances[0].z = 3;
			}

			//fish
			if (game->map->cells[row][col] == fish)
			{
				create_image(game->mlx, &img, "textures/fish.png", row, col);
				img->instances[0].z = 2;
			}

			//exit
			if (game->map->cells[row][col] == home)
			{
				create_image(game->mlx, &img, "textures/home.png", row, col);
				img->instances[0].z = 2;
			}

			col++;
		}
		row++;
	}
}
