/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_penguin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:55:39 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/07 18:23:12 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	show_sprite(t_game *game, mlx_image_t *image);

void	show_penguin(t_game *game)
{
	game->penguin->still->enabled = false;
	game->penguin->north->enabled = false;
	game->penguin->west->enabled = false;
	game->penguin->south->enabled = false;
	game->penguin->east->enabled = false;
	if (game->penguin->facing == STILL)
		show_sprite(game, game->penguin->still);
	else if (game->penguin->facing == NORTH)
		show_sprite(game, game->penguin->north);
	else if (game->penguin->facing == WEST)
		show_sprite(game, game->penguin->west);
	else if (game->penguin->facing == SOUTH)
		show_sprite(game, game->penguin->south);
	else if (game->penguin->facing == EAST)
		show_sprite(game, game->penguin->east);
}

static void	show_sprite(t_game *game, mlx_image_t *image)
{
	image->instances[0].x = game->penguin->x;
	image->instances[0].y = game->penguin->y;
	image->enabled = true;
}
