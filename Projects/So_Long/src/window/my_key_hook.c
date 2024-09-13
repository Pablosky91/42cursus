/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 20:19:02 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/09/13 20:26:48 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE)
		exit_game(game, OK);
	if (keydata.key == MLX_KEY_KP_ADD && keydata.action != MLX_RELEASE
		&& game->speed < game->img_size - 1)
		game->speed++;
	if (keydata.key == MLX_KEY_KP_SUBTRACT && keydata.action != MLX_RELEASE
		&& game->speed > 1)
		game->speed--;
	/* BONUS if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS
		&& game->moves != 0)
		retry(game); */
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
