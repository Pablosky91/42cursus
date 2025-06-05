/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_close_hook_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:21:02 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/11/19 14:04:05 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	my_close_hook(void *param)
{
	t_game	*game;

	game = param;
	if (game->ending->id_ending == -2)
		exit_game(game, SL_SURRENDER);
	if (game->ending->id_ending == -1)
		exit_game(game, SL_OK);
	exit_game(game, SL_DEATH);
}
