/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:10:05 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/07/19 19:40:12 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		free_data(t_data *data);
static void		error(t_data *data);

//TODO make static functions

//TODO delete
void	show_stacks(t_data *data)
{
	t_stack	*aux_a;
	t_stack	*aux_b;

	aux_a = ((aux_b = data->top_b), data->top_a);
	ft_printf("╭───────╥───────╮\n│   a\t║   b\t│\n╞═══════╬═══════╡\n");
	while (aux_a || aux_b)
	{
		if (aux_a)
		{
			ft_printf("│ %i\t║", aux_a->index);
			aux_a = aux_a->next;
		}
		else
			ft_printf("│\t║");
		if (aux_b)
		{
			ft_printf(" %i\t│\n", aux_b->index);
			aux_b = aux_b->next;
		}
		else
			ft_printf("\t│\n");
	}
	ft_printf("╰───────╨───────╯\n");
}

int	main(int argc, char **argv)
{
	t_data	*data = malloc(sizeof(t_data));

	data->top_a = 0;
	data->bot_a = 0;
	data->top_b = 0;
	data->bot_b = 0;
	data->size_a = 0;
	data->size_b = 0;
	data->move_list_first = 0;
	data->move_list_last = 0;
	move(data, no);
	if (!read_data(data, argc, argv))
		error(data);


	//show_stacks(data);
	sort(data);
	//show_stacks(data);

/* 	move(data, pb);
	move(data, ra);
	move(data, rb);
	move(data, rrb);
	move(data, rra);
	move(data, pa);

	print_moves(data);
	ft_printf("___\n"); */
	cut_moves(data);
	print_moves(data);


	free_data(data);
	return (0);
}


static void	free_data(t_data *data)
{
	t_stack		*aux_stack;
	t_stack		*copy_stack;
	t_move_list	*aux_move;
	t_move_list	*copy_move;

	aux_stack = data->top_a;
	while (aux_stack)
	{
		copy_stack = aux_stack;
		aux_stack = aux_stack->next;
		free(copy_stack);
	}
	aux_move = data->move_list_first;
	while (aux_move)
	{
		copy_move = aux_move;
		aux_move = aux_move->next;
		free(copy_move);
	}
	free(data);
}

static void	error(t_data *data)
{
	free_data(data);
	write(2, "Error\n", 6);
	exit(1);
}
