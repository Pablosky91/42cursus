/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_loop_hook_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:29:26 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/11/23 22:17:34 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	collect_fish(t_game *game, int id_fish);
static void	enter_home(t_game *game);
static void	enemy(t_game *game, int id_seal);
static void	ending(t_game *game);

void	my_loop_hook(void *param)
{
	t_game		*game;
	t_id_cell	id_cell;

	game = param;
	id_cell.type = ICE;
	if (game->ending->id_ending != -2)
		return (ending(game));
	if (game->penguin->facing != STILL)
	{
		id_cell = move_penguin(game,
				game->penguin->facing, game->penguin->x, game->penguin->y);
		my_cursor_hook(0, 0, game);
	}
	animations(game);
	if (id_cell.type == FISH)
		collect_fish(game, id_cell.id);
	else if (id_cell.type == HOME)
		enter_home(game);
	else if (id_cell.type == SEAL)
		enemy(game, id_cell.id);
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
	if (game->fishes[id_fish]->collected)
		return ;
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

/**
 * @brief If all fishes are collected, it unleashes the victory ending.
 * 
 * @param game All game information.
 */
static void	enter_home(t_game *game)
{
	if (game->collected_fishes != game->quantity_fishes)
		return ;
	game->ending->frame = game->frame;
	game->ending->time = mlx_get_time();
	game->ending->id_ending = -1;
}

/**
 * @brief Unleashes the death ending
 * 
 * @param game All game information.
 * @param id_seal The seal id of the killer.
 */
static void	enemy(t_game *game, int id_seal)
{
	game->ending->frame = game->frame;
	game->ending->time = mlx_get_time();
	game->ending->id_ending = id_seal;
}

/**
 * @brief If enough frames have elapsed, it exits the game in a clean way.
 * 
 * @param game 
 */
static void	ending(t_game *game)
{
	if (game->frame - game->ending->frame >= FRAMES_EXIT_GAME)
	{
		if (game->ending->id_ending == -1)
			exit_game(game, SL_OK);
		exit_game(game, SL_DEATH);
	}
	animations(game);
}
