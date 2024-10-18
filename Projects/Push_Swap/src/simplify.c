/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplify.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:15:18 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/18 16:13:17 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
If the given half is at the bottom of a node and there is nothing over it,
	it changes the location to be on the top.
*/
void	bottom_to_top(t_data *data, t_half *half)
{
	if (half->location == BOT_A && half->size == data->size_a)
		half->location = TOP_A;
	else if (half->location == BOT_B && half->size == data->size_b)
		half->location = TOP_B;
}

/*
Moves all nodes that can be directly sorted to top_a.
These nodes don't continue in the recursion.
The size of the half is diminished.
*/
bool	simplify_max(t_data *data, t_half *half)
{
	bool	ok;
	t_node	*iter;

	ok = true;
	iter = get_first_node(data, half);
	if (half->location == TOP_A)
		while (node_forward(&iter, data, half))
			;
	while (iter && half->size > 0 && iter->index == half->max_num && ok)
	{
		if (half->location == TOP_A)
			node_backward(&iter, half);
		else
			node_forward(&iter, data, half);
		half->max_num--;
		half->size--;
		if (half->location != TOP_A)
			ok = move_from_to(data, half->location, false);
	}
	return (!data->error_code);
}

/*
Calculates how many nodes can be left out of the recursion.
	and then be directly sorted.
The size of the half is diminished.
*/
bool	simplify_min_before(t_data *data, t_half *half, __u_int	*n_mins)
{
	bool	ok;
	t_node	*iter;

	ok = true;
	*n_mins = 0;
	iter = get_first_node(data, half);
	if (half->location != TOP_A)
		while (node_forward(&iter, data, half))
			;
	while (iter && half->size > 0 && iter->index == half->min_num && ok)
	{
		if (half->location != TOP_A)
			node_backward(&iter, half);
		else
			node_forward(&iter, data, half);
		half->min_num++;
		half->size--;
		(*n_mins)++;
		if (half->location == TOP_A)
			ok = move(data, PB);
	}
	return (!data->error_code);
}

/*
Moves the given number of nodes from the given half to top_a.
*/
bool	simplify_min_after(t_data *data, t_half *half, __u_int n_mins)
{
	bool	ok;

	ok = true;
	while (n_mins && ok)
	{
		if (half->location == TOP_A)
			half->location = TOP_B;
		ok = move_from_to(data, half->location, false);
		n_mins--;
	}
	return (!data->error_code);
}
