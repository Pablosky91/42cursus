/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:09:03 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/03 11:09:40 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_node(t_game *game, t_status_node	*node)
{
	if (!game->checker->head)
		game->checker->head = node;
	if (game->checker->tail)
		game->checker->tail->next = node;
	game->checker->tail = node;
}
