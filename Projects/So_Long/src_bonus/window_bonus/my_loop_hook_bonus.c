/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_loop_hook_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:29:26 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/14 21:19:40 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	collect_fish(t_game *game, int id_fish);
static void	enter_home(t_game *game);

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

/**
 * @brief Collects and enables the bones of the given fish.
 * If it is the last fish, enables the open home.
 * 
 * @param game All game information.
 * @param id_fish The fish id.
 */
static void	collect_fish(t_game *game, int id_fish)
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

/**
 * @brief If all fishes are collected, it exits the game in a clean way.
 * 
 * @param game All game information.
 */
static void	enter_home(t_game *game)
{
	if (game->collected_fishes == game->quantity_fishes)
		exit_game(game, SL_OK);
}
