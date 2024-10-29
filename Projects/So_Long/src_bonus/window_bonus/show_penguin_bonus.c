/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_penguin_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:29:33 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/29 20:11:16 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	show_sprite(t_game *game, mlx_image_t *image);

void	show_penguin(t_game *game)
{
	game->penguin->still->enabled = false;
	game->penguin->still_1->enabled = false;
	game->penguin->north->enabled = false;
	game->penguin->north_1->enabled = false;
	game->penguin->west->enabled = false;
	game->penguin->west_1->enabled = false;
	game->penguin->south->enabled = false;
	game->penguin->south_1->enabled = false;
	game->penguin->east->enabled = false;
	game->penguin->east_1->enabled = false;
	if (game->penguin->facing == STILL && game->frame % 60 < 30)
		show_sprite(game, game->penguin->still);
	else if (game->penguin->facing == STILL)
		show_sprite(game, game->penguin->still_1);
	else if (game->penguin->facing == NORTH && game->frame % 20 < 10)
		show_sprite(game, game->penguin->north);
	else if (game->penguin->facing == NORTH)
		show_sprite(game, game->penguin->north_1);
	else if (game->penguin->facing == WEST && game->frame % 20 < 10)
		show_sprite(game, game->penguin->west);
	else if (game->penguin->facing == WEST)
		show_sprite(game, game->penguin->west_1);
	else if (game->penguin->facing == SOUTH && game->frame % 20 < 10)
		show_sprite(game, game->penguin->south);
	else if (game->penguin->facing == SOUTH)
		show_sprite(game, game->penguin->south_1);
	else if (game->penguin->facing == EAST && game->frame % 20 < 10)
		show_sprite(game, game->penguin->east);
	else if (game->penguin->facing == EAST)
		show_sprite(game, game->penguin->east_1);
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
