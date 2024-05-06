/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:10:05 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/05/06 21:39:24 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO: avoid relink

#include "push_swap.h"

static t_stacks	create_mockup_stacks(void);

int	main(void)
{
	t_stacks	stacks;

	stacks = create_mockup_stacks();
	show_stacks(stacks);
	moves(stacks, sa);
	show_stacks(stacks);
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

static t_stacks	create_mockup_stacks(void)
{
	t_stacks	stacks;

	stacks.stack_a = ft_lstnew((void *)1);
	ft_lstadd_back(&stacks.stack_a, ft_lstnew((void *)2));
	ft_lstadd_back(&stacks.stack_a, ft_lstnew((void *)3));
	stacks.stack_b = ft_lstnew((void *)5);
	ft_lstadd_back(&stacks.stack_b, ft_lstnew((void *)8));
	ft_lstadd_back(&stacks.stack_b, ft_lstnew((void *)7));
	ft_lstadd_back(&stacks.stack_b, ft_lstnew((void *)6));
	return (stacks);
}
