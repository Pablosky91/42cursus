/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_key_hook_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:29:20 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/14 21:19:40 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	my_key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE)
		exit_game(game, SL_OK);
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
