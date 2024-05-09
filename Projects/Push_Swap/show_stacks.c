/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:53:27 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/05/09 11:12:02 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_stacks(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("a b\n---\n");
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			ft_printf("%i ", stack_a->content);
			stack_a = stack_a->next;
		}
		else
			ft_printf("  ");
		if (stack_b)
		{
			ft_printf("%i\n", stack_b->content);
			stack_b = stack_b->next;
		}
		else
			ft_printf("\n");
	}
	ft_printf("---\n\n");
}
