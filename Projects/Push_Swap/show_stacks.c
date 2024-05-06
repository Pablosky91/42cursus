/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:53:27 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/05/06 19:48:22 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void show_stacks(t_stacks stacks)
{
	while (stacks.stack_a || stacks.stack_b)
	{
		if (stacks.stack_a)
		{
			ft_printf("%i ", stacks.stack_a->content);
			stacks.stack_a = stacks.stack_a->next;
		}
		else
			ft_printf("  ");
		if (stacks.stack_b)
		{
			ft_printf("%i\n", stacks.stack_b->content);
			stacks.stack_b = stacks.stack_b->next;
		}
		else
			ft_printf("\n");
	}
	ft_printf("\n");
}
