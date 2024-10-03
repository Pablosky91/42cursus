/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_node_repeated.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:03:13 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/03 11:03:31 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
