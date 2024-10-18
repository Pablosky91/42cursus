/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 08:41:51 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/18 16:13:17 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool			are_neutral(t_move_list *node, int lower);
static bool			are_combinable(t_move_list *node, int lower);
static t_move_list	*try_delete_node(t_move_list *node);

/*
Checks for optimizations or redundant instructions in the solution.
*/
void	cut_moves(t_data *data)
{
	t_move_list	*iter;
	bool		go_back;
	int			lower;

	iter = data->move_list_first;
	while (iter)
	{
		go_back = false;
		if ((iter->move == SA || iter->move == SB || iter->move == SS)
			&& iter->quantity > 1)
		{
			go_back = true;
			iter->quantity = iter->quantity % 2;
		}
		if (iter->next)
		{
			lower = ft_get_min(iter->quantity, iter->next->quantity);
			go_back = are_neutral(iter, lower);
			go_back = go_back || are_combinable(iter, lower);
		}
		if (go_back)
			iter = try_delete_node(iter);
		else
			iter = iter->next;
	}
}

/*
Checks if an instruction and the next one cancel each other.
If so, it erases them and returns true.
*/
static bool	are_neutral(t_move_list *node, int lower)
{
	t_move	first;
	t_move	second;

	first = node->move;
	second = node->next->move;
	if (node->next && ((first == RA && second == RRA)
			|| (first == RRA && second == RA)
			|| (first == RB && second == RRB)
			|| (first == RRB && second == RB)
			|| (first == RR && second == RRR)
			|| (first == RRR && second == RR)
			|| (first == PA && second == PB)
			|| (first == PB && second == PA)))
	{
		node->quantity -= lower;
		node->next->quantity -= lower;
		try_delete_node(node->next);
		return (true);
	}
	return (false);
}

/*
Checks if an instruction and the next one can be simplified.
If so, it changes them for the simplified one and returns true.
*/
static bool	are_combinable(t_move_list *node, int lower)
{
	t_move	combo;

	combo = NO;
	if ((node->move == RA && node->next->move == RB)
		|| (node->move == RB && node->next->move == RA))
		combo = RR;
	if ((node->move == RRA && node->next->move == RRB)
		|| (node->move == RRB && node->next->move == RRA))
		combo = RRR;
	if ((node->move == SA && node->next->move == SB)
		|| (node->move == SB && node->next->move == SA))
		combo = SS;
	if (combo && node->quantity == lower)
	{
		node->move = combo;
		node->next->quantity -= lower;
		try_delete_node(node->next);
	}
	else if (combo)
	{
		node->quantity -= lower;
		node->next->move = combo;
	}
	return (combo);
}

/*
If a node doesn't have a quantity, it deletes and frees the node.
Updates the connections of the next and previous nodes.
Returns the previous node.
*/
static t_move_list	*try_delete_node(t_move_list *node)
{
	t_move_list	*prev;

	prev = node->prev;
	if (!node->quantity)
	{
		prev->next = node->next;
		if (node->next)
			node->next->prev = prev;
		free(node);
	}
	return (prev);
}
