/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_loop_hook_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:29:26 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/11/18 19:14:33 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	collect_fish(t_game *game, int id_fish);
static void	enter_home(t_game *game);
static void	enemy(t_game *game, int id_seal);

//TODO doc, macro frames, static/new file
void	show_seals(t_game *game)
{
	int	id_seal;

	id_seal = 0;
	while (id_seal < game->quantity_seals)
	{
		if (game->frame % 150 < 75)
		{
			game->seals[id_seal]->left->enabled = true;
			game->seals[id_seal]->right->enabled = false;
		}
		else
		{
			game->seals[id_seal]->left->enabled = false;
			game->seals[id_seal]->right->enabled = true;
		}
		id_seal++;
	}
}

void	my_loop_hook(void *param)
{
	t_game		*game;
	t_id_cell	id_cell;

	game = param;
	if (game->penguin->facing != STILL)
		id_cell = move_penguin(game,
				game->penguin->facing, game->penguin->x, game->penguin->y);
	show_penguin(game);
	show_seals(game);
	game->frame++;
	my_cursor_hook(0, 0, game);
	if (id_cell.type == HOME)
		enter_home(game);
	else if (id_cell.type == FISH)
		collect_fish(game, id_cell.id);
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
static void	enemy(t_game *game, int id_seal)
{
	//retry(game);
	ft_printf("killer: %i\n", id_seal);
	exit_game(game, SL_DEATH);
}
