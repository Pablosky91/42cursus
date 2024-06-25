/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:08:21 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/06/25 22:54:59 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 1 2 3 -> done
// 1 3 2 -> sa ra
// 2 1 3 -> sa
// 2 3 1 -> rra
// 3 1 2 -> ra
// 3 2 1 -> sa rra
//sorts the three items in stack_a
void	sort_three(t_data *data, bool is_b)
{
	t_stack	*stack;
	int		first;
	int		second;
	int		third;

	stack = data->top_a;
	if (is_b)
		stack = data->top_b;
	if (!stack || !stack->next || !stack->next->next
		|| stack->next->next->next)
		return ;
	first = stack->content;
	second = stack->next->content;
	third = stack->next->next->content;
	if (first < second && second > third && first < third)
		return (moves(data, sa + is_b), moves(data, ra + is_b));
	if (first > second && second < third && first < third)
		return (moves(data, sa + is_b));
	if (first < second && second > third && first > third)
		return (moves(data, rra + is_b));
	if (first > second && second < third && first > third)
		return (moves(data, ra + is_b));
	if (first > second && second > third)
		return (moves(data, sa + is_b),
			moves(data, rra + is_b));
}

void	sort_two(t_data *data, bool is_b)
{
	t_stack	*stack;
	int		first;
	int		second;

	stack = data->top_a;
	if (is_b)
		stack = data->top_b;
	if (!stack || !stack->next || stack->next->next)
		return ;
	first = stack->content;
	second = stack->next->content;
	if (first > second)
		moves(data, sa + is_b);
}

void	sort(t_data *data)
{
	sort_two(data, false);
	sort_three(data, false);
}
