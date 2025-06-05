/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_id_seal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:52:37 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/11/15 17:53:02 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	get_id_seal(t_game *game, int row, int col)
{
	int	iter;

	iter = 0;
	while (game->seals[iter])
	{
		if (game->seals[iter]->row == row && game->seals[iter]->col == col)
			return (game->seals[iter]->id);
		iter++;
	}
	return (-1);
}
