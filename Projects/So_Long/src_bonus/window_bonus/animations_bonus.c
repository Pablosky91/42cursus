/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:29:33 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/11/19 16:16:51 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	show_sprite(t_game *game, mlx_image_t *image);

//TODO static
/**
 * @brief Updates the position and sprite of the penguin in the window.
 * 
 * @param game All game information.
 */
void	show_penguin(t_game *game)
{
	if (game->penguin->facing == STILL
		&& game->frame % (FRAMES_PENGUIN_STILL * 2) < FRAMES_PENGUIN_STILL)
		show_sprite(game, game->penguin->still_a);
	else if (game->penguin->facing == STILL)
		show_sprite(game, game->penguin->still_b);
	else if (game->penguin->facing == NORTH
		&& game->frame % (FRAMES_PENGUIN_MOVING * 2) < FRAMES_PENGUIN_MOVING)
		show_sprite(game, game->penguin->north_a);
	else if (game->penguin->facing == NORTH)
		show_sprite(game, game->penguin->north_b);
	else if (game->penguin->facing == WEST
		&& game->frame % (FRAMES_PENGUIN_MOVING * 2) < FRAMES_PENGUIN_MOVING)
		show_sprite(game, game->penguin->west_a);
	else if (game->penguin->facing == WEST)
		show_sprite(game, game->penguin->west_b);
	else if (game->penguin->facing == SOUTH
		&& game->frame % (FRAMES_PENGUIN_MOVING * 2) < FRAMES_PENGUIN_MOVING)
		show_sprite(game, game->penguin->south_a);
	else if (game->penguin->facing == SOUTH)
		show_sprite(game, game->penguin->south_b);
	else if (game->penguin->facing == EAST
		&& game->frame % (FRAMES_PENGUIN_MOVING * 2) < FRAMES_PENGUIN_MOVING)
		show_sprite(game, game->penguin->east_a);
	else if (game->penguin->facing == EAST)
		show_sprite(game, game->penguin->east_b);
}

//TODO doc, macro frames, static
void	show_seals(t_game *game)
{
	int		id_seal;
	bool	first;

	id_seal = 0;
	while (id_seal < game->quantity_seals)
	{
		first = game->frame % 150 < 75;
		if (id_seal == game->ending->id_ending)
		{
			first = game->frame % 60 < 30;
			game->penguin->showing->enabled = false;
			game->seals[id_seal]->left->enabled = false;
			game->seals[id_seal]->right->enabled = false;
			game->seals[id_seal]->eating_a->enabled = first;
			game->seals[id_seal]->eating_b->enabled = !first;
		}
		else
		{
			game->seals[id_seal]->left->enabled = first;
			game->seals[id_seal]->right->enabled = !first;
		}
		id_seal++;
	}
}

void	animations(t_game *game)
{
	bool	first;

	first = game->frame % 60 < 30;
	if (game->ending->id_ending == -1)
	{
		game->penguin->showing->enabled = false;
		game->home->open->enabled = false;
		game->home->penguin_a->enabled = first;
		game->home->penguin_b->enabled = !first;
	}
	else if (game->ending->id_ending == -2)
		show_penguin(game);
	show_seals(game);
	game->frame++;
}

/**
 * @brief Moves to the actual position and enables the given image.
 * 
 * @param game All game information.
 * @param image The image to show.
 */
static void	show_sprite(t_game *game, mlx_image_t *image)
{
	game->penguin->showing->enabled = false;
	image->instances[0].x = game->penguin->x;
	image->instances[0].y = game->penguin->y;
	image->enabled = true;
	game->penguin->showing = image;
}
