/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:23:12 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/03 09:46:41 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	printf_repeat(char *string, int repeat);
static char	*get_string_move(t_move move);

/*
Saves the move as an instruction of the solution.
*/
bool	save_move(t_data *data, t_move move)
{
	t_move_list	*node;

	if (data->move_list_last && data->move_list_last->move == move)
		data->move_list_last->quantity++;
	else
	{
		node = malloc(sizeof(t_move_list));
		if (!node)
			return (provoke_error(data, MALLOC_ERROR));
		node->move = move;
		node->quantity = 1;
		node->next = NULL;
		if (!data->move_list_last)
		{
			node->prev = NULL;
			data->move_list_first = node;
		}
		else
		{
			node->prev = data->move_list_last;
			data->move_list_last->next = node;
		}
		data->move_list_last = node;
	}
	return (!data->error_code);
}

/*
Prints the whole list of instructions to the standard output.
*/
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

/*
Prints to the standard output the given string the given times.
*/
static void	printf_repeat(char *string, int times)
{
	while (times)
	{
		ft_printf("%s", string);
		times--;
	}
}

/*
Returns the given t_move as a string.
*/
static char	*get_string_move(t_move move)
{
	if (move == SA)
		return ("sa\n");
	else if (move == SB)
		return ("sb\n");
	else if (move == SS)
		return ("ss\n");
	else if (move == PA)
		return ("pa\n");
	else if (move == PB)
		return ("pb\n");
	else if (move == RA)
		return ("ra\n");
	else if (move == RB)
		return ("rb\n");
	else if (move == RR)
		return ("rr\n");
	else if (move == RRA)
		return ("rra\n");
	else if (move == RRB)
		return ("rrb\n");
	else if (move == RRR)
		return ("rrr\n");
	return ("");
}
