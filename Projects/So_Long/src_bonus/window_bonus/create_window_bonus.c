/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:28:58 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/24 17:29:59 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	create_logo(t_game *game);
static void	create_cursor(t_game *game);

void	create_window(t_game *game)
{
	int32_t	width;
	int32_t	height;

	mlx_set_setting(MLX_HEADLESS, true);
	game->mlx = mlx_init(1, 1, WINDOW_TITLE, false);
	if (!game->mlx)
		exit_game(game, SL_MLX_INIT);
	mlx_get_monitor_size(0, &width, &height);
	mlx_terminate(game->mlx);
	mlx_set_setting(MLX_HEADLESS, false);
	game->img_size = ft_get_min ((width * WINDOW_SIZE) / game->map->width,
			(height * WINDOW_SIZE) / game->map->height);
	game->speed = game->img_size * RELATIVE_SPEED;
	game->mlx = mlx_init(game->map->width * game->img_size,
			game->map->height * game->img_size, WINDOW_TITLE, false);
	if (!game->mlx)
		exit_game(game, SL_MLX_INIT);
	create_logo(game);
	create_cursor(game);
}

/**
 * @brief Creates the logo of the window.
 * 
 * @param game All game information.
 */
static void	create_logo(t_game *game)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(IMG_LOGO);
	if (!texture)
		exit_game(game, SL_MLX_PNG);
	mlx_set_icon(game->mlx, texture);
	mlx_delete_texture(texture);
}

/**
 * @brief Creates all cursors to be displayed.
 * 
 * @param game All game information.
 */
static void	create_cursor(t_game *game)
{
	mlx_texture_t	*texture;

	game->cursor = ft_calloc(1, sizeof(t_cursor));
	if (!game->cursor)
		exit_game(game, SL_NO_ALLOCATION);
	texture = mlx_load_png(IMG_CURSOR_N);
	if (!texture)
		exit_game(game, SL_MLX_PNG);
	game->cursor->up = mlx_create_cursor(texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png(IMG_CURSOR_W);
	if (!texture)
		exit_game(game, SL_MLX_PNG);
	game->cursor->left = mlx_create_cursor(texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png(IMG_CURSOR_S);
	if (!texture)
		exit_game(game, SL_MLX_PNG);
	game->cursor->down = mlx_create_cursor(texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png(IMG_CURSOR_E);
	if (!texture)
		exit_game(game, SL_MLX_PNG);
	game->cursor->right = mlx_create_cursor(texture);
	mlx_delete_texture(texture);
}
