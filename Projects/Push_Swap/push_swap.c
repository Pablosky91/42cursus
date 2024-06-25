/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:10:05 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/06/25 23:05:56 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO: check leaks

#include "push_swap.h"

static void		free_data(t_data *data);
static void		error(t_data *data);

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
void	show_stacks(t_data *data)
{
	t_stack	*aux1 = data->top_a;
	t_stack	*aux2 = data->bot_a;
	t_stack	*aux3 = data->top_b;
	t_stack	*aux4 = data->bot_b;

	ft_printf("._______________________________.\n| top a\t| bot a\t| top b\t| bot b\t|\n|-------+-------++------+-------|\n");
	while (aux1 || aux2 || aux3 || aux4)
	{
		if (aux1)
		{
			ft_printf("| %i\t|", aux1->index);
			aux1 = aux1->next;
		}
		else
			ft_printf("|\t|");
		if (aux2)
		{
			ft_printf(" %i\t||", aux2->index);
			aux2 = aux2->prev;
		}
		else
			ft_printf("\t||");
		if (aux3)
		{
			ft_printf(" %i\t|", aux3->index);
			aux3 = aux3->next;
		}
		else
			ft_printf("\t|");
		if (aux4)
		{
			ft_printf(" %i\t|\n", aux4->index);
			aux4 = aux4->prev;
		}
		else
			ft_printf("\t|\n");
	}
	ft_printf("\\-------------------------------/\n\n");
}

//TODO delete
void	move_3WQS(t_stack **stack_a, t_stack **stack_b, int kase)
{
/* 	switch (kase)
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
	} */
	//printf("\n");
	//show_stacks(*stack_a, *stack_b);
}

//TODO delete
void	test_3WQS()
{
//high 4, mid 5, low 6
//high 1, mid 2, low 3
	/* move_3WQS(&stack_a, &stack_b, 2);
	move_3WQS(&stack_a, &stack_b, 2);
	move_3WQS(&stack_a, &stack_b, 3);
	move_3WQS(&stack_a, &stack_b, 3);
	move_3WQS(&stack_a, &stack_b, 2);
	move_3WQS(&stack_a, &stack_b, 3);
	move_3WQS(&stack_a, &stack_b, 1);
	move_3WQS(&stack_a, &stack_b, 3);
	move_3WQS(&stack_a, &stack_b, 1);
	move_3WQS(&stack_a, &stack_b, 1);
	move_3WQS(&stack_a, &stack_b, 3);
	move_3WQS(&stack_a, &stack_b, 1);
	move_3WQS(&stack_a, &stack_b, 2);
	move_3WQS(&stack_a, &stack_b, 2);
	move_3WQS(&stack_a, &stack_b, 1);
	move_3WQS(&stack_a, &stack_b, 1);
	move_3WQS(&stack_a, &stack_b, 2);
	move_3WQS(&stack_a, &stack_b, 3);
	move_3WQS(&stack_a, &stack_b, 2);
	move_3WQS(&stack_a, &stack_b, 1);
	move_3WQS(&stack_a, &stack_b, 2);
	move_3WQS(&stack_a, &stack_b, 3);
	move_3WQS(&stack_a, &stack_b, 1);
	move_3WQS(&stack_a, &stack_b, 2);
	move_3WQS(&stack_a, &stack_b, 3);
	move_3WQS(&stack_a, &stack_b, 1);
	move_3WQS(&stack_a, &stack_b, 3);
	show_stacks(stack_a, stack_b);
//group 1
	move_3WQS(&stack_a, &stack_b, 3);
	move_3WQS(&stack_a, &stack_b, 1);
	move_3WQS(&stack_a, &stack_b, 2);
	move_3WQS(&stack_a, &stack_b, 2);
	move_3WQS(&stack_a, &stack_b, 3);
	move_3WQS(&stack_a, &stack_b, 2);
	move_3WQS(&stack_a, &stack_b, 3);
	move_3WQS(&stack_a, &stack_b, 1);
	move_3WQS(&stack_a, &stack_b, 1);
	show_stacks(stack_a, stack_b);
//group 1-1 (25 26 27)
	move_3WQS(&stack_a, &stack_b, 1);
	move_3WQS(&stack_a, &stack_b, 2);
	move_3WQS(&stack_a, &stack_b, 3);
	show_stacks(stack_a, stack_b);
//retrieve group 1-1
	move_3WQS(&stack_a, &stack_b, 8);//nada
	move_3WQS(&stack_a, &stack_b, 4);
	move_3WQS(&stack_a, &stack_b, 7);
	move_3WQS(&stack_a, &stack_b, 4);
	show_stacks(stack_a, stack_b);
//group 1-2 (22 23 24)
	move_3WQS(&stack_a, &stack_b, 6);
	move_3WQS(&stack_a, &stack_b, 4);
	move_3WQS(&stack_a, &stack_b, 5);
	show_stacks(stack_a, stack_b);
//retrieve group 1-2
	move_3WQS(&stack_a, &stack_b, 8);
	move_3WQS(&stack_a, &stack_b, 7);
	move_3WQS(&stack_a, &stack_b, 4);
	show_stacks(stack_a, stack_b);
//group 1-3 (19 20 21)
	move_3WQS(&stack_a, &stack_b, 7);
	move_3WQS(&stack_a, &stack_b, 7);
	move_3WQS(&stack_a, &stack_b, 4);
	move_3WQS(&stack_a, &stack_b, 7);
	move_3WQS(&stack_a, &stack_b, 5);
	show_stacks(stack_a, stack_b);
//retrieve group 1-3
	move_3WQS(&stack_a, &stack_b, 8);
	move_3WQS(&stack_a, &stack_b, 4);
	show_stacks(stack_a, stack_b);

//group 2
	move_3WQS(&stack_a, &stack_b, 5);
	move_3WQS(&stack_a, &stack_b, 6);
	move_3WQS(&stack_a, &stack_b, 4);
	move_3WQS(&stack_a, &stack_b, 6);
	move_3WQS(&stack_a, &stack_b, 6);
	move_3WQS(&stack_a, &stack_b, 5);
	move_3WQS(&stack_a, &stack_b, 4);
	move_3WQS(&stack_a, &stack_b, 5);
	move_3WQS(&stack_a, &stack_b, 4);
	show_stacks(stack_a, stack_b); */
}

int	main(int argc, char **argv)
{
	t_data	*data = malloc(sizeof(t_data));
	data->top_a = 0;
	data->bot_a = 0;
	data->top_b = 0;
	data->bot_b = 0;
	data->size = 0;
	if (!read_data(data, argc, argv))
		error(data);




	show_stacks(data);
	sort(data);
	show_stacks(data);



	free_data(data);
	return (0);
}


static void	free_data(t_data *data)
{
	t_stack	*aux;
	t_stack	*copy;

	aux = data->top_a;
	while (aux)
	{
		copy = aux;
		aux = aux->next;
		free(copy);
	}
	free(data);
}

static void	error(t_data *data)
{
	free_data(data);
	write(2, "Error\n", 6);
	exit(1);
}
