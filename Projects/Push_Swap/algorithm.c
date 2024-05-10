/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:08:21 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/05/10 15:38:02 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!(*stack) || !(*stack)->next || !(*stack)->next->next
		|| (*stack)->next->next->next)
		return ;
	first = *stack;
	second = first->next;
	third = second->next;
	if (first->content < second->content && second->content > third->content
		&& first->content < third->content)
		return (moves(stack, 0, sa), moves(stack, 0, ra));
	if (first->content > second->content && second->content < third->content
		&& first->content < third->content)
		return (moves(stack, 0, sa));
	if (first->content < second->content && second->content > third->content
		&& first->content > third->content)
		return (moves(stack, 0, rra));
	if (first->content > second->content && second->content < third->content
		&& first->content > third->content)
		return (moves(stack, 0, ra));
	if (first->content > second->content && second->content > third->content)
		return (moves(stack, 0, sa), moves(stack, 0, rra));
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	(void) stack_b;
	sort_three(stack_a);
}
// 1 2 3 -> done
// 1 3 2 -> sa ra
// 2 1 3 -> sa
// 2 3 1 -> rra
// 3 1 2 -> ra
// 3 2 1 -> sa rra