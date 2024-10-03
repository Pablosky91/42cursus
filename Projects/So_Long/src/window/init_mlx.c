/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 20:08:49 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/03 15:22:26 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_cell(t_game *game, int row, int col);
static void	draw_cell_2(t_game *game, int row, int col);
static void	create_image(t_game *game, mlx_image_t **img,
				char *path, int position[]);

void	init_mlx(t_game *game)
{
	int			row;
	int			col;

	create_window(game);
	create_logo(game);
	row = 0;
	while (row < game->map->height)
	{
		col = 0;
		while (col < game->map->width)
		{
			draw_cell(game, row, col);
			col++;
		}
		row++;
	}
}

static void	draw_cell(t_game *game, int row, int col)
{
	mlx_image_t	*img;

	create_image(game, &img, "textures/ice.png",
		(int []){row, col, 1, true});
	if (game->map->cells[row][col] == WALL)
		create_image(game, &img, "textures/wall.png",
			(int []){row, col, 2, true});
	if (game->map->cells[row][col] == PENGUIN)
	{
		game->penguin->y = row * game->img_size;
		game->penguin->x = col * game->img_size;
		create_image(game, &(game->penguin->still), "textures/penguin.png",
			(int []){row, col, 3, true});
		create_image(game, &(game->penguin->north), "textures/slide_up.png",
			(int []){row, col, 3, false});
		create_image(game, &(game->penguin->west), "textures/slide_left.png",
			(int []){row, col, 3, false});
		create_image(game, &(game->penguin->south), "textures/slide_down.png",
			(int []){row, col, 3, false});
		create_image(game, &(game->penguin->east), "textures/slide_right.png",
			(int []){row, col, 3, false});
	}
	draw_cell_2(game, row, col);
}

static void	draw_cell_2(t_game *game, int row, int col)
{
	static int	id_fish = 0;

	if (game->map->cells[row][col] == FISH)
	{
		create_image(game, &(game->fishes[id_fish]->alive), "textures/fish.png",
			(int []){row, col, 2, true});
		create_image(game, &(game->fishes[id_fish]->dead), "textures/bones.png",
			(int []){row, col, 2, false});
		id_fish++;
	}
	if (game->map->cells[row][col] == HOME)
	{
		create_image(game, &(game->home->closed), "textures/home_closed.png",
			(int []){row, col, 2, true});
		create_image(game, &(game->home->open), "textures/home_open.png",
			(int []){row, col, 2, false});
	}
}

//position: row, col, layer, enabled,
static void	create_image(t_game *game, mlx_image_t **img,
	char *path, int position[])
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		exit_game(game, _MLX_PNG);
	*img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	if (!mlx_resize_image(*img, game->img_size, game->img_size))
		exit_game(game, _MLX_RESIZE);
	if (mlx_image_to_window(game->mlx, *img,
			position[1] * game->img_size, position[0] * game->img_size) < 0)
		exit_game(game, _MLX_PRINT);
	mlx_set_instance_depth(&((*img)->instances[0]), position[2]);
	(*img)->enabled = position[3];
}
