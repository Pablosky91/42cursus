/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:10:05 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/07/24 15:49:50 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	initialize(t_data *data);
static void	free_data(t_data *data);

//TODO delete
void	show_stacks(t_data *data)
{
	t_node	*aux_a;
	t_node	*aux_b;

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

/*
Initializes the data structure.
*/
static void	initialize(t_data *data)
{
	data->top_a = 0;
	data->bot_a = 0;
	data->top_b = 0;
	data->bot_b = 0;
	data->size_a = 0;
	data->size_b = 0;
	data->move_list_first = 0;
	data->move_list_last = 0;
	move(data, no);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof (t_data));
	if (!data)
		error(data);
	initialize(data);
	if (!read_data(data, argc, argv))
		error(data);
	if (!sort(data))
		error(data);
	cut_moves(data);
	print_moves(data);
	free_data(data);
	return (0);
}

/*
Frees all allocated memory.
*/
static void	free_data(t_data *data)
{
	t_node		*aux_node;
	t_node		*copy_node;
	t_move_list	*aux_move;
	t_move_list	*copy_move;

	if (!data)
		return ;
	aux_node = data->top_a;
	while (aux_node)
	{
		copy_node = aux_node;
		aux_node = aux_node->next;
		free(copy_node);
	}
	aux_node = data->top_b;
	while (aux_node)
	{
		copy_node = aux_node;
		aux_node = aux_node->next;
		free(copy_node);
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

/*
Prints "Error" to the standard error.
*/
void	error(t_data *data)
{
	free_data(data);
	write(2, "Error\n", 6);
	exit(1);
}
