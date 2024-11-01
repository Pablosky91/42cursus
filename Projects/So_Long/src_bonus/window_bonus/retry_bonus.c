/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retry_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:18:55 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/11/01 14:46:38 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	retry(t_game *game)
{
	int	id_fish;

	if (game->moves == 0)
		return ;
	game->penguin->y = game->map->initial_row * game->img_size;
	game->penguin->x = game->map->initial_col * game->img_size;
	game->penguin->facing = STILL;
	id_fish = 0;
	while (id_fish < game->quantity_fishes)
	{
		game->fishes[id_fish]->alive->enabled = true;
		game->fishes[id_fish]->dead->enabled = false;
		game->fishes[id_fish]->collected = false;
		id_fish++;
	}
	game->collected_fishes = 0;
	game->home->closed->enabled = true;
	game->home->open->enabled = false;
	game->moves = 0;
	refresh_counter(game, game->moves);
}
