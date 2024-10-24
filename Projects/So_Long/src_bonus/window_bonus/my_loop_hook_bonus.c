/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_loop_hook_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:29:26 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/24 17:49:53 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	collect_fish(t_game *game, int id_fish);
static void	enter_home(t_game *game);
static void	enemy(t_game *game);

void	my_loop_hook(void *param)
{
	t_game	*game;
	int		id_cell;

	game = param;
	id_cell = -1;
	if (game->penguin->facing != STILL)
		id_cell = move_penguin(game,
				game->penguin->facing, game->penguin->x, game->penguin->y);
	show_penguin(game);
	my_cursor_hook(0, 0, game);
	if (id_cell == -1)
		return ;
	if (id_cell >= 0)
		collect_fish(game, id_cell);
	if (id_cell == -HOME)
		enter_home(game);
	if (id_cell == -SEAL)
		enemy(game);
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

//TODO doc
/**
 * @brief .
 * 
 * @param game All game information.
 */
static void	enemy(t_game *game)
{
	exit_game(game, SL_OK);
}
