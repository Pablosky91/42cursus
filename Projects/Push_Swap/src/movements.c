/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:40:26 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/07/16 23:11:02 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack, t_stack **bot);
static void	push(t_stack **from, t_stack **from_bottom, t_stack **to, t_stack **to_bottom);
static void	rotate(t_stack **top, t_stack **bot);
static void	rev_rotate(t_stack **top, t_stack **bot);

void	execute_move(t_data *data, t_move move)
{
	if (move == sa)
		return (swap(&data->top_a, &data->bot_a));
	else if (move == sb)
		return (swap(&data->top_b, &data->bot_b));
	else if (move == ss)
		return (swap(&data->top_a, &data->bot_a), swap(&data->top_b, &data->bot_b));
	else if (move == pa)
		return (push(&data->top_b, &data->bot_b, &data->top_a, &data->bot_a));
	else if (move == pb)
		return (push(&data->top_a, &data->bot_a, &data->top_b, &data->bot_b));
	else if (move == ra)
		return (rotate(&data->top_a, &data->bot_a));
	else if (move == rb)
		return (rotate(&data->top_b, &data->bot_b));
	else if (move == rr)
		return (rotate(&data->top_a, &data->bot_a), rotate(&data->top_b, &data->bot_b));
	else if (move == rra)
		return (rev_rotate(&data->top_a, &data->bot_a));
	else if (move == rrb)
		return (rev_rotate(&data->top_b, &data->bot_b));
	else if (move == rrr)
		return (rev_rotate(&data->top_a, &data->bot_a), rev_rotate(&data->top_b, &data->bot_b));
}

void	move(t_data *data, t_move move)
{
	if (move == pa && data->size_b > 0)
	{
		data->size_a++;
		data->size_b--;
	}
	else if (move == pb && data->size_a > 0)
	{
		data->size_a--;
		data->size_b++;
	}
	execute_move(data, move);
	save_move(data, move);
}

static void	swap(t_stack **top, t_stack **bot)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!(*top) || !(*top)->next)
		return ;
	first = *top;
	second = first->next;
	third = second->next;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = 0;
	if (third)
		third->prev = first;
	else
		*bot = first;
	*top = second;
}

static void	push(t_stack **from, t_stack **from_bottom, t_stack **to, t_stack **to_bottom)
{
	t_stack	*from_first;
	t_stack	*from_second;
	t_stack	*to_first;

	if (!*from)
		return ;
	from_first = *from;
	from_second = from_first->next;
	to_first = *to;
	from_first->next = to_first;
	if (from_second)
		from_second->prev = 0;
	else
		*from_bottom = 0;
	if (to_first)
		to_first->prev = from_first;
	else
		*to_bottom = from_first;
	*from = from_second;
	*to = from_first;
}

static void	rotate(t_stack **top, t_stack **bot)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (!(*top) || !(*top)->next)
		return ;
	first = *top;
	second = first->next;
	last = *bot;
	first->next = 0;
	first->prev = last;
	second->prev = 0;
	last->next = first;
	*top = second;
	*bot = first;
}

static void	rev_rotate(t_stack **top, t_stack **bot)
{
	t_stack	*first;
	t_stack	*penultimate;
	t_stack	*last;

	if (!(*top) || !(*top)->next)
		return ;
	first = *top;
	last = *bot;
	penultimate = last->prev;
	first->prev = last;
	penultimate->next = 0;
	last->next = first;
	last->prev = 0;
	*top = last;
	*bot = penultimate;
}
