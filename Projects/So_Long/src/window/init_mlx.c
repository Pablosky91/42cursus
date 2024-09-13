/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 20:08:49 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/09/13 21:55:52 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_image(t_game *game, mlx_image_t **img, char *path, int row, int col, int layer, bool enabled)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	*img = mlx_new_image(game->mlx, texture->width, texture->height);
	*img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	mlx_resize_image(*img, game->img_size, game->img_size);
	mlx_image_to_window(game->mlx, *img,
		col * game->img_size, row * game->img_size);
	mlx_set_instance_depth(&((*img)->instances[0]), layer);
	(*img)->enabled = enabled;
}

void	create_window(t_game *game)
{
	int32_t	width;
	int32_t	height;
	mlx_t	*mlx;

	mlx_set_setting(MLX_HEADLESS, true);
	mlx = mlx_init(1, 1, WINDOW_TITLE, false);
	mlx_get_monitor_size(0, &width, &height);
	mlx_terminate(mlx);
	mlx_set_setting(MLX_HEADLESS, false);
	game->img_size = ft_get_min ((width * 95 / 100) / game->map->width,
			(height * 95 / 100) / game->map->height);
	game->speed = game->img_size / 8;
	game->mlx = mlx_init(game->map->width * game->img_size,
			game->map->height * game->img_size, WINDOW_TITLE, false);
}

void	create_logo(t_game *game)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("textures/logo.png");
	mlx_set_icon(game->mlx, texture);
	mlx_delete_texture(texture);
}

void	init_mlx(t_game *game)
{
	int			row;
	int			col;
	mlx_image_t	*img;
	int id_fish = 0;

	create_window(game);
	create_logo(game);
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
