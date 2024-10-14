/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_same_status_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:28:34 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/14 21:19:40 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

bool	is_same_status(t_game *game,
	t_status_node *status_1, t_status_node *status_2)
{
	int	iter;

	iter = 0;
	if (status_1->row != status_2->row)
		return (false);
	if (status_1->col != status_2->col)
		return (false);
	while (iter < game->quantity_fishes)
	{
		if (status_1->fishes[iter] != status_2->fishes[iter])
			return (false);
		iter++;
	}
	return (true);
}
