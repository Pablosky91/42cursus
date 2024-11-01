/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cell_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 23:10:27 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/11/02 00:52:09 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	draw_cell_continuation(t_game *game, int row, int col);
static void	draw_counter(t_game *game, int row, int col, mlx_image_t **numbers);
static void	draw_penguin(t_game *game, int row, int col);
static void	create_image(t_game *game,
				mlx_image_t **img, char *path, int position[]);

void	draw_cell(t_game *game, int row, int col)
{
	create_image(game, NULL, IMG_ICE,
		(int []){row, col, ICE_LAYER, true});
	if (game->map->cells[row][col] == WALL)
	{
		if (row == 0 && col == game->map->width - 1)
			draw_counter(game, row, col, game->counter->units);
		else if (row == 0 && col == game->map->width - 2)
			draw_counter(game, row, col, game->counter->tens);
		else if (row == 0 && col == game->map->width - 3)
			draw_counter(game, row, col, game->counter->hundreds);
		else
			create_image(game, NULL, IMG_WALL,
				(int []){row, col, OBJECTS_LAYER, true});
	}
	else if (game->map->cells[row][col] == SEAL)
		create_image(game, NULL, IMG_SEAL,
			(int []){row, col, SEAL_LAYER, true});
	else if (game->map->cells[row][col] == PENGUIN)
		draw_penguin(game, row, col);
	else
		draw_cell_continuation(game, row, col);
}

/**
 * @brief Continuation of draw_cell.
 * 
 * @param game All game information.
 * @param row The row of the map to print.
 * @param col The column of the map to print.
 */
static void	draw_cell_continuation(t_game *game, int row, int col)
{
	static int	id_fish = 0;

	if (game->map->cells[row][col] == FISH)
	{
		create_image(game, &game->fishes[id_fish]->alive, IMG_FISH_ALIVE,
			(int []){row, col, OBJECTS_LAYER, true});
		create_image(game, &game->fishes[id_fish]->dead, IMG_FISH_DEAD,
			(int []){row, col, OBJECTS_LAYER, false});
		id_fish++;
	}
	else if (game->map->cells[row][col] == HOME)
	{
		create_image(game, &game->home->closed, IMG_HOME_CLOSED,
			(int []){row, col, OBJECTS_LAYER, true});
		create_image(game, &game->home->open, IMG_HOME_OPEN,
			(int []){row, col, OBJECTS_LAYER, false});
	}
}

/**
 * @brief Continuation of draw_cell to draw the move counter.
 * 
 * @param game All game information.
 * @param row The row of the map to print.
 * @param col The column of the map to print.
 * @param numbers Array of images containing all numbers.
 */
static void	draw_counter(t_game *game, int row, int col, mlx_image_t **numbers)
{
	create_image(game, &numbers[0], IMG_WALL_0,
		(int []){row, col, OBJECTS_LAYER, true});
	create_image(game, &numbers[1], IMG_WALL_1,
		(int []){row, col, OBJECTS_LAYER, false});
	create_image(game, &numbers[2], IMG_WALL_2,
		(int []){row, col, OBJECTS_LAYER, false});
	create_image(game, &numbers[3], IMG_WALL_3,
		(int []){row, col, OBJECTS_LAYER, false});
	create_image(game, &numbers[4], IMG_WALL_4,
		(int []){row, col, OBJECTS_LAYER, false});
	create_image(game, &numbers[5], IMG_WALL_5,
		(int []){row, col, OBJECTS_LAYER, false});
	create_image(game, &numbers[6], IMG_WALL_6,
		(int []){row, col, OBJECTS_LAYER, false});
	create_image(game, &numbers[7], IMG_WALL_7,
		(int []){row, col, OBJECTS_LAYER, false});
	create_image(game, &numbers[8], IMG_WALL_8,
		(int []){row, col, OBJECTS_LAYER, false});
	create_image(game, &numbers[9], IMG_WALL_9,
		(int []){row, col, OBJECTS_LAYER, false});
}

/**
 * @brief Continuation of draw_cell in case the cell is the penguin.
 * 
 * @param game All game information.
 * @param row The row of the map to print.
 * @param col The column of the map to print.
 */
static void	draw_penguin(t_game *game, int row, int col)
{
	game->penguin->y = row * game->img_size;
	game->penguin->x = col * game->img_size;
	create_image(game, &game->penguin->still_a, IMG_PENGUIN_A,
		(int []){row, col, PENGUIN_LAYER, true});
	create_image(game, &game->penguin->still_b, IMG_PENGUIN_B,
		(int []){row, col, PENGUIN_LAYER, false});
	create_image(game, &game->penguin->north_a, IMG_PENGUIN_N_A,
		(int []){row, col, PENGUIN_LAYER, false});
	create_image(game, &game->penguin->north_b, IMG_PENGUIN_N_B,
		(int []){row, col, PENGUIN_LAYER, false});
	create_image(game, &game->penguin->west_a, IMG_PENGUIN_W_A,
		(int []){row, col, PENGUIN_LAYER, false});
	create_image(game, &game->penguin->west_b, IMG_PENGUIN_W_B,
		(int []){row, col, PENGUIN_LAYER, false});
	create_image(game, &game->penguin->south_a, IMG_PENGUIN_S_A,
		(int []){row, col, PENGUIN_LAYER, false});
	create_image(game, &game->penguin->south_b, IMG_PENGUIN_S_B,
		(int []){row, col, PENGUIN_LAYER, false});
	create_image(game, &game->penguin->east_a, IMG_PENGUIN_E_A,
		(int []){row, col, PENGUIN_LAYER, false});
	create_image(game, &game->penguin->east_b, IMG_PENGUIN_E_B,
		(int []){row, col, PENGUIN_LAYER, false});
	game->penguin->showing = game->penguin->still_a;
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
	mlx_image_t		*img_null;

	img_null = NULL;
	if (!img)
		img = &img_null;
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
	mlx_set_instance_depth(&(*img)->instances[0], position[2]);
	(*img)->enabled = position[3];
}
