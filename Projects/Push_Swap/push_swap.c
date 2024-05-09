/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:10:05 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/05/09 18:58:30 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO: check leaks

#include "push_swap.h"

static t_stack	*ps_new(int content);
static int		ps_add_back(t_stack **lst, int content);
static void		free_stack(t_stack **stack);
static void		error(t_stack **stack);

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = 0;
	stack_b = 0;
	if (!read_data(&stack_a, argc, argv))
		error(&stack_a);




	show_stacks(stack_a, stack_b);
	moves(&stack_a, &stack_b, sa);
	show_stacks(stack_a, stack_b);
	moves(&stack_a, &stack_b, sa);
	show_stacks(stack_a, stack_b);
	moves(&stack_a, &stack_b, sa);
	show_stacks(stack_a, stack_b);
	moves(&stack_a, &stack_b, sa);





	free_stack(&stack_a);
	return (0);
}

//static t_stacks	*create_mockup_stacks(t_stacks	*stacks);

static t_stack	*ps_new(int content)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (0);
	node->content = content;
	node->next = 0;
	return (node);
}

//TODO maybe if !lst, lst = 0
static int	ps_add_back(t_stack **lst, int content)
{
	t_stack	*aux;
	t_stack	*new_node;

	if (!lst)
		return (0);
	new_node = ps_new(content);
	if (!new_node)
		return (0);
	aux = *lst;
	if (!*lst)
		*lst = new_node;
	else
	{
		while (aux->next)
		{
			if (aux->content == content)
				return (free(new_node), 0);
			aux = aux->next;
		}
		if (aux->content == content)
			return (free(new_node), 0);
		aux->next = new_node;
	}
	return (1);
}

//TODO delete
int	create_mockup_stack(t_stack **stack, int num1, int num2, int num3)
{
	if (!ps_add_back(stack, num1))
		return (0);
	if (!ps_add_back(stack, num2))
		return (0);
	if (!ps_add_back(stack, num3))
		return (0);
	return (1);
}

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
