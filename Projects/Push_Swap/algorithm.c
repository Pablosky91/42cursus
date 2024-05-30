/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:08:21 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/05/30 20:20:32 by pdel-olm         ###   ########.fr       */
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
void	sort_three(t_stack **stk_a, t_stack **stk_b, int is_b)
{
	t_stack	**stack;
	int		first;
	int		second;
	int		third;

	stack = stk_a;
	if (is_b)
		stack = stk_b;
	if (!(*stack) || !(*stack)->next || !(*stack)->next->next
		|| (*stack)->next->next->next)
		return ;
	first = (*stack)->content;
	second = (*stack)->next->content;
	third = (*stack)->next->next->content;
	if (first < second && second > third && first < third)
		return (moves(stk_a, stk_b, sa + is_b), moves(stk_a, stk_b, ra + is_b));
	if (first > second && second < third && first < third)
		return (moves(stk_a, stk_b, sa + is_b));
	if (first < second && second > third && first > third)
		return (moves(stk_a, stk_b, rra + is_b));
	if (first > second && second < third && first > third)
		return (moves(stk_a, stk_b, ra + is_b));
	if (first > second && second > third)
		return (moves(stk_a, stk_b, sa + is_b),
			moves(stk_a, stk_b, rra + is_b));
}

void	sort_two(t_stack **stk_a, t_stack **stk_b, int is_b)
{
	t_stack	**stack;
	int		first;
	int		second;

	stack = stk_a;
	if (is_b)
		stack = stk_b;
	if (!(*stack) || !(*stack)->next || (*stack)->next->next)
		return ;
	first = (*stack)->content;
	second = (*stack)->next->content;
	if (first > second)
		moves(stk_a, stk_b, sa + is_b);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	sort_two(stack_a, stack_b, 0);
	sort_three(stack_a, stack_b, 0);
}
