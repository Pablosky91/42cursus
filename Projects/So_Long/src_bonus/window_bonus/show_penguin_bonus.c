/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_penguin_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:29:33 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/30 11:06:40 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	show_sprite(t_game *game, mlx_image_t *image);

void	show_penguin(t_game *game)
{
	game->penguin->still_a->enabled = false;
	game->penguin->still_b->enabled = false;
	game->penguin->north_a->enabled = false;
	game->penguin->north_b->enabled = false;
	game->penguin->west_a->enabled = false;
	game->penguin->west_b->enabled = false;
	game->penguin->south_a->enabled = false;
	game->penguin->south_b->enabled = false;
	game->penguin->east_a->enabled = false;
	game->penguin->east_b->enabled = false;
	if (game->penguin->facing == STILL && game->frame % (FRAMES_PENGUIN_STILL * 2) < FRAMES_PENGUIN_STILL)
		show_sprite(game, game->penguin->still_a);
	else if (game->penguin->facing == STILL)
		show_sprite(game, game->penguin->still_b);
	else if (game->penguin->facing == NORTH && game->frame % (FRAMES_PENGUIN_MOVING * 2) < FRAMES_PENGUIN_MOVING)
		show_sprite(game, game->penguin->north_a);
	else if (game->penguin->facing == NORTH)
		show_sprite(game, game->penguin->north_b);
	else if (game->penguin->facing == WEST && game->frame % (FRAMES_PENGUIN_MOVING * 2) < FRAMES_PENGUIN_MOVING)
		show_sprite(game, game->penguin->west_a);
	else if (game->penguin->facing == WEST)
		show_sprite(game, game->penguin->west_b);
	else if (game->penguin->facing == SOUTH && game->frame % (FRAMES_PENGUIN_MOVING * 2) < FRAMES_PENGUIN_MOVING)
		show_sprite(game, game->penguin->south_a);
	else if (game->penguin->facing == SOUTH)
		show_sprite(game, game->penguin->south_b);
	else if (game->penguin->facing == EAST && game->frame % (FRAMES_PENGUIN_MOVING * 2) < FRAMES_PENGUIN_MOVING)
		show_sprite(game, game->penguin->east_a);
	else if (game->penguin->facing == EAST)
		show_sprite(game, game->penguin->east_b);
}

/**
 * @brief Moves to the actual position and enables the given image.
 * 
 * @param game All game information.
 * @param image The image to show.
 */
static void	show_sprite(t_game *game, mlx_image_t *image)
{
	image->instances[0].x = game->penguin->x;
	image->instances[0].y = game->penguin->y;
	image->enabled = true;
}
