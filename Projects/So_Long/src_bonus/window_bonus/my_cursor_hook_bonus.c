/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cursor_hook_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:00:18 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/24 17:59:18 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	my_cursor_hook(double x_pos, double y_pos, void *param)
{
	t_game		*game;
	t_direction	direction;

	game = param;
	(void) x_pos;
	(void) y_pos;
	direction = direction_to_mouse(game);
	if (direction == NORTH)
		mlx_set_cursor(game->mlx, game->cursor->up);
	else if (direction == WEST)
		mlx_set_cursor(game->mlx, game->cursor->left);
	else if (direction == SOUTH)
		mlx_set_cursor(game->mlx, game->cursor->down);
	else if (direction == EAST)
		mlx_set_cursor(game->mlx, game->cursor->right);
}
