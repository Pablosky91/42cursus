/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_loop_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:03:25 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/03 15:10:27 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_loop_hook(void *param)
{
	t_game	*game;

	game = param;
	move_penguin(game);
	collect_fish(game);
	enter_home(game);
}