/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:10:05 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/05/08 00:19:41 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO: avoid relink
//TODO: protect movements
//TODO: check leaks

#include "push_swap.h"

//static t_stacks	*create_mockup_stacks(t_stacks	*stacks);

t_stack	*ps_new(int content)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (0);
	node->content = content;
	node->next = 0;
	return (node);
}

int	ps_add_back(t_stack **lst, int content)
{
	t_stack *aux;
	t_stack	*new_node;

	new_node = ps_new(content);
	if (!lst || !new_node)
		return (0);
	aux = *lst;
	while (aux->next)
	{
		if (aux->content == content)
			return (0);
		aux = aux->next;
	}
	aux->next = new_node;
	return (1);
}





int	create_mockup_stack(t_stack	**stack, int num1, int num2, int num3, int num4)
{
	*stack = ps_new(num1);
	if (!*stack)
		return (0);
	if (!ps_add_back(stack, num2))
		return (0);
	if (!ps_add_back(stack, num3))
		return (0);
	if (!ps_add_back(stack, num4))
		return (0);
	return (1);
}
int	main(void)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (!create_mockup_stack(&stack_a, 1, 2, 3, 4))
		return (ft_printf("Error\n"), 42);
	if (!create_mockup_stack(&stack_b, 4, 5, 6, 7))
		return (ft_printf("Error\n"), 42);
	show_stacks(stack_a, stack_b);
	
	moves(&stack_a, &stack_b, pb);
	show_stacks(stack_a, stack_b);

	moves(&stack_a, &stack_b, pb);
	show_stacks(stack_a, stack_b);

	moves(&stack_a, &stack_b, pb);
	show_stacks(stack_a, stack_b);

	moves(&stack_a, &stack_b, pb);
	show_stacks(stack_a, stack_b);

	return (0);
}