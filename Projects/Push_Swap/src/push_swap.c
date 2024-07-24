/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:10:05 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/07/24 21:19:51 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	initialize(t_data *data);

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

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof (t_data));
	if (!data)
		error(data);
	if (!initialize(data))
		error(data);
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
Initializes the data structure.
*/
static bool	initialize(t_data *data)
{
	data->top_a = 0;
	data->bot_a = 0;
	data->top_b = 0;
	data->bot_b = 0;
	data->size_a = 0;
	data->size_b = 0;
	data->move_list_first = 0;
	data->move_list_last = 0;
	data->error_code = success;
	return (move(data, no));
}
