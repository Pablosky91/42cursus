/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:40:26 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/05/07 22:03:28 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack);
static void	push(t_stack **from, t_stack **to);
static void	rotate(t_stack **stack);
static void	rev_rotate(t_stack **stack);

void	moves(t_stack **stack_a, t_stack **stack_b, t_move move)
{
	if (move == sa)
		return (ft_printf("sa\n"), swap(stack_a));
	else if (move == sb)
		return (ft_printf("sb\n"), swap(stack_b));
	else if (move == ss)
		return (ft_printf("ss\n"), swap(stack_a), swap(stack_b));
	else if (move == pa)
		return (ft_printf("pa\n"), push(stack_b, stack_a));
	else if (move == pb)
		return (ft_printf("pb\n"), push(stack_a, stack_b));
	else if (move == ra)
		return (ft_printf("ra\n"), rotate(stack_a));
	else if (move == rb)
		return (ft_printf("rb\n"), rotate(stack_b));
	else if (move == rr)
		return (ft_printf("rr\n"), rotate(stack_a), rotate(stack_b));
	else if (move == rra)
		return (ft_printf("rra\n"), rev_rotate(stack_a));
	else if (move == rrb)
		return (ft_printf("rrb\n"), rev_rotate(stack_b));
	else if (move == rrr)
		return (ft_printf("rrr\n"), rev_rotate(stack_a), rev_rotate(stack_b));
}

//TODO protect maybe
static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

//TODO protect maybe
static void	push(t_stack **from, t_stack **to)
{
	t_stack	*from_first;
	t_stack	*from_second;
	t_stack	*to_first;

	from_first = *from;
	from_second = from_first->next;
	to_first = *to;
	from_first->next = to_first;
	*from = from_second;
	*to = from_first;
}

//TODO protect maybe
static void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	first = *stack;
	second = first->next;
	last = first;
	while (last->next)
		last = last->next;
	first->next = last->next;
	last->next = first;
	*stack = second;
}

//TODO protect maybe
static void	rev_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*penultimate;
	t_stack	*last;

	first = *stack;
	last = first;
	while (last->next)
	{
		penultimate = last;
		last = last->next;
	}
	penultimate->next = last->next;
	last->next = first;
	*stack = last;
}