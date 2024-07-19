/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:23:12 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/07/19 09:14:59 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	printf_repeat(char *string, int repeat);
static char	*get_string_move(t_move move);

void	save_move(t_data *data, t_move move)
{
	t_move_list	*node;

	if (data->move_list_last && data->move_list_last->move == move)
		data->move_list_last->quantity++;
	else
	{
		node = malloc(sizeof(t_move_list));
		if (!node)
			return ;
		node->move = move;
		node->quantity = 1;
		node->next = 0;
		if (!data->move_list_last)
		{
			node->prev = 0;
			data->move_list_first = node;
			data->move_list_last = node;
		}
		else
		{
			node->prev = data->move_list_last;
			data->move_list_last->next = node;
			data->move_list_last = node;
		}
	}
}

void	print_moves(t_data *data)
{
	t_move_list	*list;

	list = data->move_list_first;
	while (list)
	{
		printf_repeat(get_string_move(list->move), list->quantity);
		list = list->next;
	}
}

static void	printf_repeat(char *string, int repeat)
{
	while (repeat > 0)
	{
		ft_printf("%s", string);
		repeat--;
	}
}

static char	*get_string_move(t_move move)
{
	if (move == sa)
		return ("sa\n");
	else if (move == sb)
		return ("sb\n");
	else if (move == ss)
		return ("ss\n");
	else if (move == pa)
		return ("pa\n");
	else if (move == pb)
		return ("pb\n");
	else if (move == ra)
		return ("ra\n");
	else if (move == rb)
		return ("rb\n");
	else if (move == rr)
		return ("rr\n");
	else if (move == rra)
		return ("rra\n");
	else if (move == rrb)
		return ("rrb\n");
	else if (move == rrr)
		return ("rrr\n");
	return ("");
}
