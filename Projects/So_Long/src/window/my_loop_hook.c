/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_loop_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:03:25 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/04 20:56:06 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_loop_hook(void *param)
{
	t_game	*game;
	int		id_fish_home;

	game = param;
	show_penguin(game);
	if (game->penguin->facing == STILL)
		return ;
	id_fish_home = move_penguin(game,
			game->penguin->facing, game->penguin->x, game->penguin->y);
	if (id_fish_home >= 0)
		collect_fish(game, id_fish_home);
	if (id_fish_home == -HOME)
		enter_home(game);
}
