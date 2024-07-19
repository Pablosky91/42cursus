/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 08:41:51 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/07/19 14:45:13 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
Returns the next node to the deleted one
*/
void	delete_node(t_move_list *node)
{
	if (node->quantity <= 0)
	{
		node->prev->next = node->next;
		if (node->next)
			node->next->prev = node->prev;
		free(node);
	}
}

int	get_lower(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

bool	are_neutral(t_move first, t_move second)
{
	return ((first == ra && second == rra)
		|| (first == rra && second == ra)
		|| (first == rb && second == rrb)
		|| (first == rrb && second == rb)
		|| (first == rr && second == rrr)
		|| (first == rrr && second == rr)
		|| (first == pa && second == pb)
		|| (first == pb && second == pa));
}

t_move	are_combinable(t_move first, t_move second)
{
	if ((first == ra && second == rb)
		|| (first == rb && second == ra))
		return (rr);
	if ((first == rra && second == rrb)
		|| (first == rrb && second == rra))
		return (rrr);
	if ((first == sa && second == sb)
		|| (first == sb && second == sa))
		return (ss);
	return (no);
}

void	cut_moves(t_data *data)
{
	t_move_list	*aux;
	t_move		combo;
	bool		go_back;
	int			lower;

	aux = data->move_list_first;
	while (aux)
	{
		go_back = false;
		if ((aux->move == sa || aux->move == sb || aux->move == ss) && aux->quantity > 1)
		{
			aux->quantity = aux->quantity % 2;
			go_back = true;
		}
		if (aux->next)
		{
			lower = get_lower(aux->quantity, aux->next->quantity);
			combo = are_combinable(aux->move, aux->next->move);
			if (are_neutral(aux->move, aux->next->move))
			{
				aux->quantity -= lower;
				aux->next->quantity -= lower;
				delete_node(aux->next);
				go_back = true;
			}
			if (combo != no)
			{
				if (aux->quantity == lower)
				{
					aux->move = combo;
					aux->next->quantity -= lower;
					delete_node(aux->next);
				}
				else
				{
					aux->quantity -= lower;
					aux->next->move = combo;
				}
				go_back = true;
			}
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
