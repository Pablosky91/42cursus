/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:06:30 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/18 16:13:24 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_status_node	*create_node(t_game *game, int row, int col)
{
	t_status_node	*node;

	node = ft_calloc(1, sizeof(t_status_node));
	if (!node)
		exit_game(game, SL_NO_ALLOCATION);
	node->row = row;
	node->col = col;
	node->fishes = ft_calloc(game->quantity_fishes, sizeof(bool));
	if (!node->fishes)
	{
		free(node);
		exit_game(game, SL_NO_ALLOCATION);
	}
	return (node);
}
