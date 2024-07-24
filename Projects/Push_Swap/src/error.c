/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 21:13:05 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/07/24 21:42:35 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stack(t_node *node);

/*
Prints "Error" to the standard error.
*/
void	error(t_data *data)
{
	t_error	error_code;

	error_code = malloc_error;
	if (data)
	{
		error_code = data->error_code;
		free_data(data);
	}
	write(2, "Error\n", 6);
	exit(error_code);
}

/*
Marks the type of error
*/
bool	provoke_error(t_data *data, t_error error_code)
{
	data->error_code = error_code;
	return (!error_code);
}

/*
Frees all allocated memory.
*/
void	free_data(t_data *data)
{
	t_move_list	*aux_move;
	t_move_list	*copy_move;

	free_stack(data->top_a);
	free_stack(data->top_b);
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
Frees the stack starting with the given node.
*/
static void	free_stack(t_node *node)
{
	t_node		*copy_node;

	while (node)
	{
		copy_node = node;
		node = node->next;
		free(copy_node);
	}
}
