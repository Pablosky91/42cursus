/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:29:06 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/30 11:06:40 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	else if (game->map->cells[row][col] == HOME)
	{
		create_image(game, &(game->home->closed), IMG_HOME_CLOSED,
			(int []){row, col, OBJECTS_LAYER, true});
		create_image(game, &(game->home->open), IMG_HOME_OPEN,
			(int []){row, col, OBJECTS_LAYER, false});
	}
	else if (game->map->cells[row][col] == SEAL)
		create_image(game, &img, IMG_SEAL,
			(int []){row, col, SEAL_LAYER, true});
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

	if (game->map->cells[row][col] == PENGUIN)
	{
		game->penguin->y = row * game->img_size;
		game->penguin->x = col * game->img_size;
		create_image(game, &(game->penguin->still_a), IMG_PENGUIN_A,
			(int []){row, col, PENGUIN_LAYER, true});
		create_image(game, &(game->penguin->still_b), IMG_PENGUIN_B,
			(int []){row, col, PENGUIN_LAYER, true});
		create_image(game, &(game->penguin->north_a), IMG_PENGUIN_N_A,
			(int []){row, col, PENGUIN_LAYER, false});
		create_image(game, &(game->penguin->north_b), IMG_PENGUIN_N_B,
			(int []){row, col, PENGUIN_LAYER, false});
		create_image(game, &(game->penguin->west_a), IMG_PENGUIN_W_A,
			(int []){row, col, PENGUIN_LAYER, false});
		create_image(game, &(game->penguin->west_b), IMG_PENGUIN_W_B,
			(int []){row, col, PENGUIN_LAYER, false});
		create_image(game, &(game->penguin->south_a), IMG_PENGUIN_S_A,
			(int []){row, col, PENGUIN_LAYER, false});
		create_image(game, &(game->penguin->south_b), IMG_PENGUIN_S_B,
			(int []){row, col, PENGUIN_LAYER, false});
		create_image(game, &(game->penguin->east_a), IMG_PENGUIN_E_A,
			(int []){row, col, PENGUIN_LAYER, false});
		create_image(game, &(game->penguin->east_b), IMG_PENGUIN_E_B,
			(int []){row, col, PENGUIN_LAYER, false});
	}
	if (game->map->cells[row][col] == FISH)
	{
		create_image(game, &(game->fishes[id_fish]->alive), IMG_FISH_ALIVE,
			(int []){row, col, OBJECTS_LAYER, true});
		create_image(game, &(game->fishes[id_fish++]->dead), IMG_FISH_DEAD,
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
