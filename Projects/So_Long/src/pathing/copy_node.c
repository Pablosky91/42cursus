/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:08:21 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/03 11:08:31 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_status_node	*copy_node(t_game *game, t_status_node *node)
{
	t_status_node	*copy;
	int				iter;

	iter = 0;
	copy = create_node(game, node->row, node->col);
	while (iter < game->quantity_fishes)
	{
		copy->fishes[iter] = node->fishes[iter];
		iter++;
	}
	return (copy);
}
