/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_counter_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:08:06 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/11/01 13:09:00 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	refresh_counter(t_game *game, int moves)
{
	game->counter->units[game->counter->units_show]->enabled = false;
	game->counter->units_show = moves % 10;
	game->counter->units[game->counter->units_show]->enabled = true;
	if (moves % 10 == 0)
	{
		game->counter->tens[game->counter->tens_show]->enabled = false;
		game->counter->tens_show = (moves / 10) % 10;
		game->counter->tens[game->counter->tens_show]->enabled = true;
	}
	if (moves % 100 == 0)
	{
		game->counter->hundreds[game->counter->hundreds_show]->enabled = false;
		game->counter->hundreds_show = (moves / 100) % 10;
		game->counter->hundreds[game->counter->hundreds_show]->enabled = true;
	}
}
