/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_id_fish_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:28:20 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/18 16:13:24 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	get_id_fish(t_game *game, int row, int col)
{
	int	iter;

	iter = 0;
	while (game->fishes[iter])
	{
		if (game->fishes[iter]->row == row && game->fishes[iter]->col == col)
			return (game->fishes[iter]->id);
		iter++;
	}
	return (-1);
}
