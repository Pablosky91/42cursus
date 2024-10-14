/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_node_repeated_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:28:28 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/14 21:19:40 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

bool	is_node_repeated(t_game *game, t_status_node *node)
{
	t_status_node	*iter;

	iter = game->checker->head;
	while (iter)
	{
		if (is_same_status(game, iter, node))
			return (true);
		iter = iter->next;
	}
	return (false);
}
