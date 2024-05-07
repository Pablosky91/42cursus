/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:10:05 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/05/07 22:01:39 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO: avoid relink

#include "push_swap.h"

//static t_stacks	*create_mockup_stacks(t_stacks	*stacks);

t_stack	*ft_ps_new(int content)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (0);
	node->content = content;
	node->next = 0;
	return (node);
}

static t_stack	*ft_ps_last(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	ft_ps_add_back(t_stack **lst, t_stack *new)
{
	t_stack *aux;
	
	aux = *lst;
	if (!lst || !new)
		return ;
	while (aux->next)
		aux = aux->next;
	aux->next = new;
}





void	create_mockup_stack(t_stack	**stack, int num1, int num2, int num3, int num4)
{
	t_stack	*aux;
	
	aux = *stack;
	//int num = 1, num1 = 2, num2 = 3;
	aux = ft_ps_new(num1);
	//printf("sd");
	//printf("%d", *(int *)aux->content);
	ft_ps_add_back(&aux, ft_ps_new(num2));
	//printf("%d", *(int *)aux->next->content);
	ft_ps_add_back(&aux, ft_ps_new(num3));
	ft_ps_add_back(&aux, ft_ps_new(num4));
	/*ft_lstadd_back(&(stacks)->stack_a, ft_lstnew((void *)3));
	(stacks)->stack_b = ft_lstnew((void *)5);
	ft_lstadd_back(&(stacks)->stack_b, ft_lstnew((void *)8));
	ft_lstadd_back(&(stacks)->stack_b, ft_lstnew((void *)7));
	ft_lstadd_back(&(stacks)->stack_b, ft_lstnew((void *)6)); */
	*stack = aux;
	//show_stacks(*stacks);
//	return (&stacks);
}
int	main(void)
{
	//t_stacks	*stacks;
	t_stack	*stack_a;
	t_stack	*stack_b;

	create_mockup_stack(&stack_a, 1, 2, 3, 4);
	create_mockup_stack(&stack_b, 4, 5, 6, 7);
	
	show_stacks(stack_a, stack_b);
	moves(&stack_a, &stack_b, pb);
	/* if (!stacks.stack_a)
		ft_printf("ERROR");
	ft_printf("main: %i\n", stacks.stack_a->content); */
	show_stacks(stack_a, stack_b);
	/* char *sentence = "  f    g  ";
	char delimiter = ' ';	
	char **array = ft_split(sentence, delimiter);
	int i = 0;
	while (array[i])
	{
		ft_printf("%i: >%s<\n", i, array[i]);
		i++;
	} */
	return (0);
}