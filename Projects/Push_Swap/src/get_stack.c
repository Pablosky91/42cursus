/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:18:30 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/07/19 19:34:54 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Returns the first stack of the given half->location
*/
t_stack	*get_first_stack(t_data *data, t_half *half)
{
	t_stack	*stack;

	if (half->location == top_a)
		stack = data->top_a;
	else if (half->location == bot_a)
		stack = data->bot_a;
	else if (half->location == top_b)
		stack = data->top_b;
	else if (half->location == bot_b)
		stack = data->bot_b;
	return (stack);
}

/*
Iterates the stack to the next if the half is located at top.
Iterates the stack to the prev if the half is located at bot.
If the stack is null, it initialises to the first stack.
If the stack were to exit the half, the stack is replaced by null.
Returns true if the next/prev stack still is the same half.
*/
bool	stack_forward(t_stack **stack, t_data *data, t_half *half)
{
	t_stack	*aux;

	aux = 0;
	if (!(*stack))
		*stack = get_first_stack(data, half);
	else if (half->location == top_a || half->location == top_b)
		*stack = (*stack)->next;
	else
		*stack = (*stack)->prev;
	if (*stack
		&& ((*stack)->index < half->min_num || (*stack)->index > half->max_num))
		*stack = 0;
	if (*stack && (half->location == top_a || half->location == top_b))
		aux = (*stack)->next;
	else if (*stack)
		aux = (*stack)->prev;
	return (aux && aux->index >= half->min_num && aux->index <= half->max_num);
}

/*
Iterates the stack to the prev if the half is located at top.
Iterates the stack to the next if the half is located at bot.
Returns true if it is the first stack of the half.
*/
bool	stack_backward(t_stack **stack, t_half *half)
{
	t_stack	*aux;

	aux = 0;
	if (half->location == top_a || half->location == top_b)
		*stack = (*stack)->prev;
	else
		*stack = (*stack)->next;
	if (*stack && (half->location == top_a || half->location == top_b))
		aux = (*stack)->prev;
	else if (*stack)
		aux = (*stack)->next;
	return (aux);
}
