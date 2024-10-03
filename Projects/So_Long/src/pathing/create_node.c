/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:06:30 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/03 11:06:43 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_status_node	*create_node(t_game *game, int row, int col)
{
	t_status_node	*node;

	node = ft_calloc(1, sizeof(t_status_node));
	if (!node)
		exit_game(game, NO_ALLOCATION);
	node->row = row;
	node->col = col;
	node->fishes = ft_calloc(game->quantity_fishes, sizeof(bool));
	if (!node->fishes)
		exit_game(game, NO_ALLOCATION);
	return (node);
}