/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_close_hook_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:21:02 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/24 18:35:32 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	my_close_hook(void *param)
{
	t_game	*game;

	game = param;
	exit_game(game, SL_SURRENDER);
}
