/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:40:26 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/05/06 21:56:47 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_swap(t_list **stack);
static void	move_push(t_list *from, t_list *to);
static void	move_rotate(t_list *stack);
static void	move_reverse_rotate(t_list *stack);

void	moves(t_stacks stacks, t_move move)
{
//	ft_printf ("mov: %i\n", stacks.stack_a->content);

	if(move == sa)
		move_swap(stacks.stack_a);
	/*else if(move == sb)
		move_swap(stacks.stack_b);
	else if(move == ss)
	{
		move_swap(stacks.stack_a);
		move_swap(stacks.stack_b);
	}*/
	else if(move == pa)
		move_push(stacks.stack_b, stacks.stack_a);
	else if(move == pb)
		move_push(stacks.stack_a, stacks.stack_b);
	else if(move == ra)
		move_rotate(stacks.stack_a);
	else if(move == rb)
		move_rotate(stacks.stack_b);
	else if(move == rr)
	{
		move_rotate(stacks.stack_a);
		move_rotate(stacks.stack_b);
	}
	else if(move == rra)
		move_reverse_rotate(stacks.stack_a);
	else if(move == rrb)
		move_reverse_rotate(stacks.stack_b);
	else if(move == rrr)
	{
		move_reverse_rotate(stacks.stack_a);
		move_reverse_rotate(stacks.stack_b);
	}
}

static void	move_swap(t_list **stack)
{
	t_list	*aux;

	aux = ft_lstnew((*stack)->next);
	ft_printf("aux: %i\n", (aux)->content);
	aux->next = *stack;
	(*stack)->next = aux;
}

static void	move_push(t_list *from, t_list *to)
{
//	ft_printf ("to: %i\n", (int)(to->content));
//	ft_lstadd_front(to, ft_lstnew(from->content));
//	*from = *from->next;
	//to->content = (void *)9;
	/* t_stacks stacks;
	stacks.stack_a = to;
	stacks.stack_b = from;
	show_stacks(stacks); */


//F T
//g h

//g F
//  T
//  h

	ft_printf("pa:\n");
	t_list *aux = from;
	ft_printf("aux: %i\n", (aux)->content);
	ft_printf("to: %i\n", to->content);
	*from = *from->next;
	ft_printf("aux: %i\n", (aux)->content);
  	(aux)->next = to;
	to = aux; 
//	ft_lstadd_front(&to, aux);
}

static void	move_rotate(t_list *stack)
{
	
}

static void	move_reverse_rotate(t_list *stack)
{
	
}