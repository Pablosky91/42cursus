/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_id_fish.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:17:45 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/03 11:18:05 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
