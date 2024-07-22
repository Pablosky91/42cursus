/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 08:41:51 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/07/22 18:08:36 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	are_neutral(t_move_list *node, int lower);
static bool	are_combinable(t_move_list *node, int lower);
static void	delete_node(t_move_list *node);
static int	get_lower(int a, int b);

/*
Checks for optimizations or redundant instructions in the solution.
*/
void	cut_moves(t_data *data)
{
	t_move_list	*aux;
	bool		go_back;
	int			lower;

	aux = data->move_list_first;
	while (aux)
	{
		go_back = false;
		if ((aux->move == sa || aux->move == sb || aux->move == ss)
			&& aux->quantity > 1)
			aux->quantity = ((go_back = true), aux->quantity % 2);
		if (aux->next)
		{
			lower = get_lower(aux->quantity, aux->next->quantity);
			go_back = are_neutral(aux, lower);
			go_back = go_back || are_combinable(aux, lower);
		}
		if (go_back)
		{
			aux = aux->prev;
			delete_node(aux->next);
		}
		else
			aux = aux->next;
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
		delete_node(node->next);
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
		delete_node(node->next);
	}
	else if (combo != no)
	{
		node->quantity -= lower;
		node->next->move = combo;
	}
	return (combo != no);
}

/*
Deletes and frees a node.
Updates the connections of the next and previous nodes.
*/
static void	delete_node(t_move_list *node)
{
	if (node->quantity <= 0)
	{
		node->prev->next = node->next;
		if (node->next)
			node->next->prev = node->prev;
		free(node);
	}
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
