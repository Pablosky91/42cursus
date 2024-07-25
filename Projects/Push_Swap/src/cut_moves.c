/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 08:41:51 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/07/25 21:50:53 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool			are_neutral(t_move_list *node, int lower);
static bool			are_combinable(t_move_list *node, int lower);
static t_move_list	*try_delete_node(t_move_list *node);
static int			get_lower(int a, int b);

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
		if ((iter->move == sa || iter->move == sb || iter->move == ss)
			&& iter->quantity > 1)
		{
			go_back = true;
			iter->quantity = iter->quantity % 2;
		}
		if (iter->next)
		{
			lower = get_lower(iter->quantity, iter->next->quantity);
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
	if (node->next && ((first == ra && second == rra)
			|| (first == rra && second == ra)
			|| (first == rb && second == rrb)
			|| (first == rrb && second == rb)
			|| (first == rr && second == rrr)
			|| (first == rrr && second == rr)
			|| (first == pa && second == pb)
			|| (first == pb && second == pa)))
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

	combo = no;
	if ((node->move == ra && node->next->move == rb)
		|| (node->move == rb && node->next->move == ra))
		combo = rr;
	if ((node->move == rra && node->next->move == rrb)
		|| (node->move == rrb && node->next->move == rra))
		combo = rrr;
	if ((node->move == sa && node->next->move == sb)
		|| (node->move == sb && node->next->move == sa))
		combo = ss;
	if (combo != no && node->quantity == lower)
	{
		node->move = combo;
		node->next->quantity -= lower;
		try_delete_node(node->next);
	}
	else if (combo != no)
	{
		node->quantity -= lower;
		node->next->move = combo;
	}
	return (combo != no);
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
	if (node->quantity <= 0)
	{
		prev->next = node->next;
		if (node->next)
			node->next->prev = prev;
		free(node);
	}
	return (prev);
}

/*
Returns the lower of the two given numbers.
*/
static int	get_lower(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
