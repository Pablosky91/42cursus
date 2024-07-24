/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplify.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:15:18 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/07/24 19:07:00 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
If the given half is at the bottom of a node and there is nothing over it,
	it changes the location to be on the top.
*/
void	bottom_to_top(t_data *data, t_half *half)
{
	if (half->location == bot_a && half->size == data->size_a)
		half->location = top_a;
	else if (half->location == bot_b && half->size == data->size_b)
		half->location = top_b;
}

/*
Moves all nodes that can be directly sorted to top_a.
These nodes don't continue in the recursion.
The size of the half is diminished.
*/
t_error	simplify_max(t_data *data, t_half *half)
{
	t_node	*aux;
	t_error	error_code;

	error_code = success;
	aux = get_first_node(data, half);
	if (half->location == top_a)
		while (node_forward(&aux, data, half))
			;
	while (aux && half->size > 0 && aux->index == half->max_num)
	{
		if (half->location == top_a)
			node_backward(&aux, half);
		else
			node_forward(&aux, data, half);
		half->max_num--;
		half->size--;
		if (half->location != top_a)
			error_code = move_from_to(data, half->location, false);
	}
	return (error_code);
}

/*
Calculates how many nodes can be left out of the recursion.
	and then be directly sorted.
The size of the half is diminished.
*/
t_error	simplify_min_before(t_data *data, t_half *half, unsigned int	*n_mins)
{
	t_node	*aux;
	t_error	error_code;

	*n_mins = 0;
	error_code = success;
	aux = get_first_node(data, half);
	if (half->location != top_a)
		while (node_forward(&aux, data, half))
			;
	while (aux && half->size > 0 && aux->index == half->min_num && !error_code)
	{
		if (half->location != top_a)
			node_backward(&aux, half);
		else
			node_forward(&aux, data, half);
		half->min_num++;
		half->size--;
		(*n_mins)++;
		if (half->location == top_a)
			error_code = move(data, pb);
	}
	return (error_code);
}

/*
Moves the given number of nodes from the given half to top_a.
*/
t_error	simplify_min_after(t_data *data, t_half *half, unsigned int n_mins)
{
	t_error	error_code;

	error_code = success;
	while (n_mins > 0 && !error_code)
	{
		if (half->location == top_a)
			half->location = top_b;
		error_code = move_from_to(data, half->location, false);
		n_mins--;
	}
	return (error_code);
}
