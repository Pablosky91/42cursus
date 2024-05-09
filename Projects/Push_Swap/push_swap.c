/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:10:05 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/05/09 19:12:38 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO: check leaks

#include "push_swap.h"

static void		free_stack(t_stack **stack);
static void		error(t_stack **stack);

//TODO delete
/* int	create_mockup_stack(t_stack **stack, int num1, int num2, int num3)
{
	if (!ps_add_back(stack, num1))
		return (0);
	if (!ps_add_back(stack, num2))
		return (0);
	if (!ps_add_back(stack, num3))
		return (0);
	return (1);
} */

//TODO delete
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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = 0;
	stack_b = 0;
	if (!read_data(&stack_a, argc, argv))
		error(&stack_a);




	show_stacks(stack_a, stack_b);
	/* moves(&stack_a, &stack_b, sa);
	show_stacks(stack_a, stack_b);
	moves(&stack_a, &stack_b, sa);
	show_stacks(stack_a, stack_b);
	moves(&stack_a, &stack_b, sa);
	show_stacks(stack_a, stack_b);
	moves(&stack_a, &stack_b, sa);




	free_stack(&stack_a); */
	return (0);
}

static void	free_stack(t_stack **stack)
{
	t_stack	*aux;
	t_stack	*copy;

	aux = *stack;
	while (aux)
	{
		copy = aux;
		aux = aux->next;
		free(copy);
	}
}

static void	error(t_stack **stack)
{
	free_stack(stack);
	write(2, "Error\n", 6);
	exit(42);
}
