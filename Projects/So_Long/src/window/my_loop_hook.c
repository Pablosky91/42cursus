/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_loop_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:03:25 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/07 21:24:11 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collect_fish(t_game *game, int id_fish)
{
	if (!game->fishes[id_fish]->collected)
	{
		game->fishes[id_fish]->alive->enabled = false;
		game->fishes[id_fish]->dead->enabled = true;
		game->fishes[id_fish]->collected = true;
		game->collected_fishes++;
		if (game->collected_fishes == game->quantity_fishes)
		{
			game->home->closed->enabled = false;
			game->home->open->enabled = true;
		}
	}
}

void	enter_home(t_game *game)
{
	if (game->collected_fishes == game->quantity_fishes)
		exit_game(game, SL_OK);
}

void	my_loop_hook(void *param)
{
	t_game	*game;
	int		id_fish_home;

	game = param;
	id_fish_home = -1;
	if (game->penguin->facing != STILL)
		id_fish_home = move_penguin(game,
				game->penguin->facing, game->penguin->x, game->penguin->y);
	show_penguin(game);
	if (id_fish_home == -1)
		return ;
	if (id_fish_home >= 0)
		collect_fish(game, id_fish_home);
	if (id_fish_home == -HOME)
		enter_home(game);
}
