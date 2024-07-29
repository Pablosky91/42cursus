/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:10:05 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/07/29 22:05:30 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	initialize(t_data **data);

//TODO delete
void	show_stacks(t_data *data)
{
	t_node	*node_a;
	t_node	*node_b;

	node_a = data->top_a;
	node_b = data->top_b;
	ft_printf("╭───────╥───────╮\n│   a\t║   b\t│\n╞═══════╬═══════╡\n");
	while (node_a || node_b)
	{
		if (node_a)
		{
			ft_printf("│ %i\t║", node_a->index);
			node_a = node_a->next;
		}
		else
			ft_printf("│\t║");
		if (node_b)
		{
			ft_printf(" %i\t│\n", node_b->index);
			node_b = node_b->next;
		}
		else
			ft_printf("\t│\n");
	}
	ft_printf("╰───────╨───────╯\n");
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (!initialize(&data))
		error(data);
	if (!read_data(data, argc, argv))
		error(data);
	if (!sort(data))
		error(data);
	cut_moves(data);
	print_moves(data);
	free_data(data);
	return (success);
}

/*
Initializes the data structure.
*/
static bool	initialize(t_data **data)
{
	*data = malloc(sizeof (t_data));
	if (!*data)
		return (false);
	(*data)->top_a = NULL;
	(*data)->bot_a = NULL;
	(*data)->top_b = NULL;
	(*data)->bot_b = NULL;
	(*data)->size_a = 0;
	(*data)->size_b = 0;
	(*data)->move_list_first = NULL;
	(*data)->move_list_last = NULL;
	(*data)->error_code = success;
	return (move(*data, no));
}
