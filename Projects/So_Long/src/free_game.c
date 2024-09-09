/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:41:01 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/09/09 22:27:18 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_game(t_game *game)
{
	int	i;

	if (!game)
		return ;
	i = 0;
	if (game->fishes)
	{
		while (game->fishes[i])
			free(game->fishes[i++]->position);
		ft_free_double_pointer((void **) game->fishes);
	}
	if (game->map && game->map->cells)
		ft_free_double_pointer((void **) game->map->cells);
	free(game->map);
	free(game->penguin);
	free(game->home);
	free(game->initial_pos);
	if (game->mlx)
		mlx_terminate(game->mlx);
	free(game);
}

