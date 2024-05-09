/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:10:05 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/05/09 11:23:00 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
//if !lst, lst = 0
int	ps_add_back(t_stack **lst, int content)
{
	t_stack	*aux;
	t_stack	*new_node;

	new_node = ps_new(content);
	if (!lst || !new_node)
		return (0);
	aux = *lst;
	if (!*lst)
		*lst = new_node;
	else
	{
		while (aux->next)
		{
			if (aux->content == content)
				return (0);
			aux = aux->next;
		}
		if (aux->content == content)
			return (0);
		aux->next = new_node;
	}
	return (1);
}





int	create_mockup_stack(t_stack **stack, int num1, int num2, int num3, int num4)
{
	if (!ps_add_back(stack, num1))
		return (0);
	if (!ps_add_back(stack, num2))
		return (0);
	if (!ps_add_back(stack, num3))
		return (0);
	if (!ps_add_back(stack, num4))
		return (0);
	return (1);
}

//TODO better atoi
int	read_data(t_stack **stack, int argc, char **argv)
{
	int		i;
	int		j;
	char	**split;

	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		j = 0;
		while (split[j])
		{
			if(!ps_add_back(stack, ft_atoi(split[j])))
				return (free(split[j]), free(split), 0);
			free(split[j]);
			j++;
		}
		free(split);
		i++;
	}
	return (1);
}

void error(t_stack **stack_a)
{
	t_stack	*aux;
	t_stack	*copy;

	aux = *stack_a;
	while (aux->next)
	{
		copy = aux;
		aux = aux->next;
		free(copy);
	}
	free(aux);
	write(2, "Error\n", 6);
	exit(42);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = 0;
	stack_b = 0;
	if(!read_data(&stack_a, argc, argv))
		error(&stack_a);
	//show_stacks(stack_a, stack_b);








	// if (!create_mockup_stack(&stack_a, 1, 2, 3, 4))
	//	return (ft_printf("Error\n"), 42);
	//if (!create_mockup_stack(&stack_b, 5, 6, 7, 8))
	//	return (ft_printf("Error\n"), 42);
	show_stacks(stack_a, stack_b);
	moves(&stack_a, &stack_b, pb);
	show_stacks(stack_a, stack_b);
	moves(&stack_a, &stack_b, pa);
	show_stacks(stack_a, stack_b);
	error(&stack_a);
	/* moves(&stack_a, &stack_b, pb);
	show_stacks(stack_a, stack_b);

	moves(&stack_a, &stack_b, pb);
	show_stacks(stack_a, stack_b);
	
	moves(&stack_a, &stack_b, pa);
	show_stacks(stack_a, stack_b);
	
	moves(&stack_a, &stack_b, rr);
	show_stacks(stack_a, stack_b);

	moves(&stack_a, &stack_b, sa);
	show_stacks(stack_a, stack_b);

	moves(&stack_a, &stack_b, rrb);
	show_stacks(stack_a, stack_b); */

	return (0);
}
