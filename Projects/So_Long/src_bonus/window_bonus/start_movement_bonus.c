/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_movement_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:29:39 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/11/19 15:43:16 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	start_movement(t_game *game, t_direction direction)
{
	int	row;
	int	col;

	if (game->penguin->facing != STILL || game->ending->id_ending != -2)
		return ;
	row = game->penguin->y / game->img_size;
	col = game->penguin->x / game->img_size;
	if (get_cell_by(game, row, col, direction) == WALL)
		return ;
	game->penguin->facing = direction;
	refresh_counter(game, ++game->moves);
}
