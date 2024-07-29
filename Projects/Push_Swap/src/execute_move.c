/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:40:26 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/07/29 22:03:37 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_node **node, t_node **bot);
static void	push(t_node **from, t_node **from_bottom,
				t_node **to, t_node **to_bottom);
static void	rotate(t_node **top, t_node **bot);
static void	reverse_rotate(t_node **top, t_node **bot);

/*
Updates the placement of the nodes executing the given move.
*/
void	execute_move(t_data *data, t_move move)
{
	if (move == sa)
		return (swap(&data->top_a, &data->bot_a));
	else if (move == sb)
		return (swap(&data->top_b, &data->bot_b));
	else if (move == ss)
		return (swap(&data->top_a, &data->bot_a),
			swap(&data->top_b, &data->bot_b));
	else if (move == pa)
		return (push(&data->top_b, &data->bot_b, &data->top_a, &data->bot_a));
	else if (move == pb)
		return (push(&data->top_a, &data->bot_a, &data->top_b, &data->bot_b));
	else if (move == ra)
		return (rotate(&data->top_a, &data->bot_a));
	else if (move == rb)
		return (rotate(&data->top_b, &data->bot_b));
	else if (move == rr)
		return (rotate(&data->top_a, &data->bot_a),
			rotate(&data->top_b, &data->bot_b));
	else if (move == rra)
		return (reverse_rotate(&data->top_a, &data->bot_a));
	else if (move == rrb)
		return (reverse_rotate(&data->top_b, &data->bot_b));
	else if (move == rrr)
		return (reverse_rotate(&data->top_a, &data->bot_a),
			reverse_rotate(&data->top_b, &data->bot_b));
}

/*
Executes the swap move.
*/
static void	swap(t_node **top, t_node **bot)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (!(*top) || !(*top)->next)
		return ;
	first = *top;
	second = first->next;
	third = second->next;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	if (third)
		third->prev = first;
	else
		*bot = first;
	*top = second;
}

/*
Executes the push move.
*/
static void	push(t_node **from, t_node **from_bottom,
				t_node **to, t_node **to_bottom)
{
	t_node	*from_first;
	t_node	*from_second;
	t_node	*to_first;

	if (!*from)
		return ;
	from_first = *from;
	from_second = from_first->next;
	to_first = *to;
	from_first->next = to_first;
	if (from_second)
		from_second->prev = NULL;
	else
		*from_bottom = NULL;
	if (to_first)
		to_first->prev = from_first;
	else
		*to_bottom = from_first;
	*from = from_second;
	*to = from_first;
}

/*
Executes the rotate move.
*/
static void	rotate(t_node **top, t_node **bot)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (!(*top) || !(*top)->next)
		return ;
	first = *top;
	second = first->next;
	last = *bot;
	first->next = NULL;
	first->prev = last;
	second->prev = NULL;
	last->next = first;
	*top = second;
	*bot = first;
}

/*
Executes the reverse_rotate move.
*/
static void	reverse_rotate(t_node **top, t_node **bot)
{
	t_node	*first;
	t_node	*penultimate;
	t_node	*last;

	if (!(*top) || !(*top)->next)
		return ;
	first = *top;
	last = *bot;
	penultimate = last->prev;
	first->prev = last;
	penultimate->next = NULL;
	last->next = first;
	last->prev = NULL;
	*top = last;
	*bot = penultimate;
}
