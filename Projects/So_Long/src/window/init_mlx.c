/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 20:08:49 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/13 11:50:09 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_cell(t_game *game, int row, int col);
static void	draw_cell_2(t_game *game, int row, int col);
static void	create_image(t_game *game,
				mlx_image_t **img, char *path, int position[]);

void	init_mlx(t_game *game)
{
	int			row;
	int			col;

	create_window(game);
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

/**
 * @brief Prints an image corresponding to the cell type.
 * 
 * @param game All game information.
 * @param row The row of the map to print.
 * @param col The column of the map to print.
 */
static void	draw_cell(t_game *game, int row, int col)
{
	mlx_image_t	*img;

	create_image(game, &img, IMG_ICE,
		(int []){row, col, ICE_LAYER, true});
	if (game->map->cells[row][col] == WALL)
		create_image(game, &img, IMG_WALL,
			(int []){row, col, OBJECTS_LAYER, true});
	else if (game->map->cells[row][col] == PENGUIN)
	{
		game->penguin->y = row * game->img_size;
		game->penguin->x = col * game->img_size;
		create_image(game, &(game->penguin->still), IMG_PENGUIN,
			(int []){row, col, PENGUIN_LAYER, true});
		create_image(game, &(game->penguin->north), IMG_PENGUIN_N,
			(int []){row, col, PENGUIN_LAYER, false});
		create_image(game, &(game->penguin->west), IMG_PENGUIN_W,
			(int []){row, col, PENGUIN_LAYER, false});
		create_image(game, &(game->penguin->south), IMG_PENGUIN_S,
			(int []){row, col, PENGUIN_LAYER, false});
		create_image(game, &(game->penguin->east), IMG_PENGUIN_E,
			(int []){row, col, PENGUIN_LAYER, false});
	}
	else
		draw_cell_2(game, row, col);
}

/**
 * @brief Continuation of draw_cell.
 * 
 * @param game All game information.
 * @param row The row of the map to print.
 * @param col The column of the map to print.
 */
static void	draw_cell_2(t_game *game, int row, int col)
{
	static int	id_fish = 0;

	if (game->map->cells[row][col] == FISH)
	{
		create_image(game, &(game->fishes[id_fish]->alive), IMG_FISH_ALIVE,
			(int []){row, col, OBJECTS_LAYER, true});
		create_image(game, &(game->fishes[id_fish]->dead), IMG_FISH_DEAD,
			(int []){row, col, OBJECTS_LAYER, false});
		id_fish++;
	}
	if (game->map->cells[row][col] == HOME)
	{
		create_image(game, &(game->home->closed), IMG_HOME_CLOSED,
			(int []){row, col, OBJECTS_LAYER, true});
		create_image(game, &(game->home->open), IMG_HOME_OPEN,
			(int []){row, col, OBJECTS_LAYER, false});
	}
}

/**
 * @brief Prints the given png to the given position.
 * 
 * @param game All game information.
 * @param img The image to save.
 * @param path The path to the png to print.
 * @param position Array consisting of row, column, layer and wether is enabled.
 */
static void	create_image(t_game *game,
				mlx_image_t **img, char *path, int position[])
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		exit_game(game, SL_MLX_PNG);
	*img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	if (!mlx_resize_image(*img, game->img_size, game->img_size))
		exit_game(game, SL_MLX_RESIZE);
	if (mlx_image_to_window(game->mlx, *img,
			position[1] * game->img_size, position[0] * game->img_size) < 0)
		exit_game(game, SL_MLX_PRINT);
	mlx_set_instance_depth(&((*img)->instances[0]), position[2]);
	(*img)->enabled = position[3];
}
