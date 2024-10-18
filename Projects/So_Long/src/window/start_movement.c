/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:59:59 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/18 16:13:24 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_movement(t_game *game, t_direction direction)
{
	int	row;
	int	col;

	if (game->penguin->facing != STILL)
		return ;
	row = game->penguin->y / game->img_size;
	col = game->penguin->x / game->img_size;
	if (get_cell_by(game, row, col, direction) == WALL)
		return ;
	game->penguin->facing = direction;
	ft_printf(MOVE_MSG, ++game->moves);
}
