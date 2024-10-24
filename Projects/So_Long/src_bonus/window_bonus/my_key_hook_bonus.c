/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_key_hook_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:29:20 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/22 18:55:22 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	change_speed(mlx_key_data_t keydata, t_game *game);

void	my_key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.action != MLX_PRESS)
		return ;
	if (keydata.key == MLX_KEY_ESCAPE)
		exit_game(game, SL_OK);
	if (keydata.key == MLX_KEY_R)
		retry(game);
	change_speed(keydata, game);
	if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		start_movement(game, NORTH);
	else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		start_movement(game, WEST);
	else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		start_movement(game, SOUTH);
	else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		start_movement(game, EAST);
}

/**
 * @brief Changes the speed of the penguin.
 * 0 stands for max speed, and the other number keys as 10 times the percentage.
 * 
 * @param keydata All keydata information.
 * @param game All game information.
 */
static void	change_speed(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.key == MLX_KEY_0 || keydata.key == MLX_KEY_KP_0)
		game->speed = game->img_size;
	else if (keydata.key >= MLX_KEY_1 && keydata.key <= MLX_KEY_9)
		game->speed = game->img_size * (keydata.key - MLX_KEY_0) / 10;
	else if (keydata.key >= MLX_KEY_KP_1 && keydata.key <= MLX_KEY_KP_9)
		game->speed = game->img_size * (keydata.key - MLX_KEY_KP_0) / 10;
}
