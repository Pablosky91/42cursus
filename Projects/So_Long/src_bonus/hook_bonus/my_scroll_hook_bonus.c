/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_scroll_hook_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:56:59 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/22 18:57:24 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	my_scroll_hook(double x_delta, double y_delta, void *param)
{
	t_game	*game;

	game = param;
	if (game->penguin->facing != STILL)
		return ;
	if (y_delta > 0)
		start_movement(game, NORTH);
	else if (x_delta > 0)
		start_movement(game, WEST);
	else if (y_delta < 0)
		start_movement(game, SOUTH);
	else
		start_movement(game, EAST);
}
