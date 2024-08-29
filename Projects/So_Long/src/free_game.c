/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:41:01 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/08/29 17:13:59 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_game(t_game *game)
{
	__u_int i = 0;

	while (game->fishes[i])
		free(game->fishes[i++]->position);

	ft_free_double_pointer((void **) game->map->cells);
	ft_free_double_pointer((void **) game->fishes);
	free(game->map);
	free(game->penguin);
	free(game->initial_pos);
	free(game);
}
