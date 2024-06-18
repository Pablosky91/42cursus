/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:10:05 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/06/18 18:55:02 by pdel-olm         ###   ########.fr       */
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
	ft_printf("a b\n----\n");
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			ft_printf("%i ", stack_a->index);
			stack_a = stack_a->next;
		}
		else
			ft_printf("  ");
		if (stack_b)
		{
			ft_printf("%i\n", stack_b->index);
			stack_b = stack_b->next;
		}
		else
			ft_printf("\n");
	}
	ft_printf("----\n\n");
}

//TODO delete
void move(t_stack **stack_a, t_stack **stack_b, int kase)
{
	switch (kase)
	{
	case 1:
		moves(stack_a, stack_b, ra);
		break;
	case 2:
		moves(stack_a, stack_b, pb);
		break;
	case 3:
		moves(stack_a, stack_b, pb);
		moves(stack_a, stack_b, rb);
		break;
	case 4:
		moves(stack_a, stack_b, pa);
		break;
	case 5:
		moves(stack_a, stack_b, pa);
		moves(stack_a, stack_b, ra);
		break;
	case 6:
		moves(stack_a, stack_b, rb);
		break;
	case 7:
		moves(stack_a, stack_b, rrb);
		break;
	case 8:
		moves(stack_a, stack_b, rra);
		break;
	}
	//printf("\n");
	//show_stacks(*stack_a, *stack_b);
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
	sort(&stack_a, &stack_b);
	//show_stacks(stack_a, stack_b);
	/* moves(&stack_a, &stack_b, sa);
	show_stacks(stack_a, stack_b);
	moves(&stack_a, &stack_b, sa);
	show_stacks(stack_a, stack_b);
	moves(&stack_a, &stack_b, sa);
	show_stacks(stack_a, stack_b);
	moves(&stack_a, &stack_b, sa); */

//high 4, mid 5, low 6
//high 1, mid 2, low 3
	/* move(&stack_a, &stack_b, 2);
	move(&stack_a, &stack_b, 2);
	move(&stack_a, &stack_b, 3);
	move(&stack_a, &stack_b, 3);
	move(&stack_a, &stack_b, 2);
	move(&stack_a, &stack_b, 3);
	move(&stack_a, &stack_b, 1);
	move(&stack_a, &stack_b, 3);
	move(&stack_a, &stack_b, 1);
	move(&stack_a, &stack_b, 1);
	move(&stack_a, &stack_b, 3);
	move(&stack_a, &stack_b, 1);
	move(&stack_a, &stack_b, 2);
	move(&stack_a, &stack_b, 2);
	move(&stack_a, &stack_b, 1);
	move(&stack_a, &stack_b, 1);
	move(&stack_a, &stack_b, 2);
	move(&stack_a, &stack_b, 3);
	move(&stack_a, &stack_b, 2);
	move(&stack_a, &stack_b, 1);
	move(&stack_a, &stack_b, 2);
	move(&stack_a, &stack_b, 3);
	move(&stack_a, &stack_b, 1);
	move(&stack_a, &stack_b, 2);
	move(&stack_a, &stack_b, 3);
	move(&stack_a, &stack_b, 1);
	move(&stack_a, &stack_b, 3);
	show_stacks(stack_a, stack_b);
//group 1
	move(&stack_a, &stack_b, 3);
	move(&stack_a, &stack_b, 1);
	move(&stack_a, &stack_b, 2);
	move(&stack_a, &stack_b, 2);
	move(&stack_a, &stack_b, 3);
	move(&stack_a, &stack_b, 2);
	move(&stack_a, &stack_b, 3);
	move(&stack_a, &stack_b, 1);
	move(&stack_a, &stack_b, 1);
	show_stacks(stack_a, stack_b);
//group 1-1 (25 26 27)
	move(&stack_a, &stack_b, 1);
	move(&stack_a, &stack_b, 2);
	move(&stack_a, &stack_b, 3);
	show_stacks(stack_a, stack_b);
//retrieve group 1-1
	move(&stack_a, &stack_b, 8);//nada
	move(&stack_a, &stack_b, 4);
	move(&stack_a, &stack_b, 7);
	move(&stack_a, &stack_b, 4);
	show_stacks(stack_a, stack_b);
//group 1-2 (22 23 24)
	move(&stack_a, &stack_b, 6);
	move(&stack_a, &stack_b, 4);
	move(&stack_a, &stack_b, 5);
	show_stacks(stack_a, stack_b);
//retrieve group 1-2
	move(&stack_a, &stack_b, 8);
	move(&stack_a, &stack_b, 7);
	move(&stack_a, &stack_b, 4);
	show_stacks(stack_a, stack_b);
//group 1-3 (19 20 21)
	move(&stack_a, &stack_b, 7);
	move(&stack_a, &stack_b, 7);
	move(&stack_a, &stack_b, 4);
	move(&stack_a, &stack_b, 7);
	move(&stack_a, &stack_b, 5);
	show_stacks(stack_a, stack_b);
//retrieve group 1-3
	move(&stack_a, &stack_b, 8);
	move(&stack_a, &stack_b, 4);
	show_stacks(stack_a, stack_b);

//group 2
	move(&stack_a, &stack_b, 5);
	move(&stack_a, &stack_b, 6);
	move(&stack_a, &stack_b, 4);
	move(&stack_a, &stack_b, 6);
	move(&stack_a, &stack_b, 6);
	move(&stack_a, &stack_b, 5);
	move(&stack_a, &stack_b, 4);
	move(&stack_a, &stack_b, 5);
	move(&stack_a, &stack_b, 4);
	show_stacks(stack_a, stack_b); */





	free_stack(&stack_a);
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
	exit(1);
}
