/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mouse_hook_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:59:31 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/24 18:03:17 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	my_mouse_hook(mouse_key_t button,
			action_t action, modifier_key_t mods, void *param)
{
	t_game	*game;

	game = param;
	(void) mods;
	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS)
		start_movement(game, direction_to_mouse(game));
}
