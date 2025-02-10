/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:24:49 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/02/06 21:37:21 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Returns the first node of the given half.
*/
t_node	*get_first_node(t_data *data, t_half *half)
{
	t_node	*node;

	if (half->location == TOP_A)
		node = data->top_a;
	else if (half->location == BOT_A)
		node = data->bot_a;
	else if (half->location == TOP_B)
		node = data->top_b;
	else
		node = data->bot_b;
	return (node);
}

/*
Iterates the node to the next if the half is located at top.
Iterates the node to the prev if the half is located at bot.
If the node is null, it initialises to the first node.
If the node were to exit the half, the node is replaced by null.
Returns true if the next/prev node still is the same half.
*/
bool	node_forward(t_node **node, t_data *data, t_half *half)
{
	t_node	*aux;

	aux = NULL;
	if (!*node)
		*node = get_first_node(data, half);
	else if (half->location == TOP_A || half->location == TOP_B)
		*node = (*node)->next;
	else
		*node = (*node)->prev;
	if (*node
		&& ((*node)->index < half->min_num || (*node)->index > half->max_num))
		*node = NULL;
	if (*node && (half->location == TOP_A || half->location == TOP_B))
		aux = (*node)->next;
	else if (*node)
		aux = (*node)->prev;
	return (aux && aux->index >= half->min_num && aux->index <= half->max_num);
}

/*
Iterates the node to the prev if the half is located at top.
Iterates the node to the next if the half is located at bot.
Returns true if it is the first node of the half.
*/
bool	node_backward(t_node **node, t_half *half)
{
	t_node	*aux;

	aux = NULL;
	if (half->location == TOP_A || half->location == TOP_B)
		*node = (*node)->prev;
	else
		*node = (*node)->next;
	if (*node && (half->location == TOP_A || half->location == TOP_B))
		aux = (*node)->prev;
	else if (*node)
		aux = (*node)->next;
	return (aux);
}
