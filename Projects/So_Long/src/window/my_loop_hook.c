/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_loop_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:03:25 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/09/13 21:03:34 by pdel-olm         ###   ########.fr       */
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
	//static int frame = 0;
	//ft_printf("Frame: %i\n", frame++);
	//mlx_put_string(game->mlx, ft_strjoin("Frame: ", ft_itoa(frame)), 50, 50);
}
