/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cell_by_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:28:10 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/14 21:19:40 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_cell	get_cell_by(t_game *game, int row, int col, t_direction direction)
{
	if (direction == NORTH)
		row--;
	if (direction == WEST)
		col--;
	if (direction == SOUTH)
		row++;
	if (direction == EAST)
		col++;
	return (game->map->cells[row][col]);
}
