/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:08:21 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/03 09:46:35 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	divide(t_data *data, t_half *half);
static bool	conquer(t_data *data, t_half *half);

/*
Sorts all the nodes in stack_a.
Divides the nodes in two halfs and sorts both of them.
*/
bool	sort(t_data *data)
{
	t_half	*half;

	if (data->size_a < 2)
		return (true);
	if (data->size_a == 2)
		return (sort_two(data));
	if (data->size_a == 3)
		return (sort_three(data));
	half = malloc(sizeof(t_half));
	if (!half)
		return (provoke_error(data, MALLOC_ERROR));
	half->location = TOP_A;
	half->size = data->size_a;
	half->min_num = 0;
	half->max_num = data->size_a - 1;
	return (conquer(data, half));
}

/*
Executes the given move and saves it in the list.
Updates the size of the stacks.
*/
bool	move(t_data *data, t_move move)
{
	if (move == PA && data->size_b > 0)
	{
		data->size_a++;
		data->size_b--;
	}
	else if (move == PB && data->size_a > 0)
	{
		data->size_a--;
		data->size_b++;
	}
	execute_move(data, move);
	return (save_move(data, move));
}

/*
Moves a node from the given location to the corresponding location.
*/
bool	move_from_to(t_data *data, t_location from, bool is_min)
{
	if (from == TOP_A && !is_min)
		return (move(data, RA));
	if (from == TOP_A && is_min)
		return (move(data, PB));
	if (from == BOT_A && !is_min)
		return (move(data, RRA));
	if (from == BOT_A && is_min)
		if (move(data, RRA))
			return (move(data, PB));
	if (from == TOP_B && !is_min)
		return (move(data, PA));
	if (from == TOP_B && is_min)
		return (move(data, RB));
	if (from == BOT_B && !is_min)
		if (move(data, RRB))
			return (move(data, PA));
	if (from == BOT_B && is_min)
		return (move(data, RRB));
	return (!data->error_code);
}

/*
Divides the given half in two halfs.
One half is for the lower numbers and the other for the higher ones.
*/
static bool	divide(t_data *data, t_half *half)
{
	__u_int	i;

	half->min_half = malloc(sizeof(t_half));
	if (!half->min_half)
		return (provoke_error(data, MALLOC_ERROR));
	half->max_half = malloc(sizeof(t_half));
	if (!half->max_half)
		return (free(half->min_half), provoke_error(data, MALLOC_ERROR));
	half->max_half->location = BOT_A;
	if (half->location != TOP_A)
		half->max_half->location = TOP_A;
	half->min_half->location = BOT_B;
	if (half->location != TOP_B)
		half->min_half->location = TOP_B;
	half->min_half->size = (half->size + 1) / 2;
	half->min_half->min_num = half->min_num;
	half->min_half->max_num = half->min_num + half->min_half->size - 1;
	half->max_half->size = (half->size) / 2;
	half->max_half->min_num = half->max_num - half->max_half->size + 1;
	half->max_half->max_num = half->max_num;
	i = 0;
	while (i++ < half->size)
		move_from_to(data, half->location, get_first_node(data, half)->index
			<= (half->min_num + half->max_num) / 2);
	return (!data->error_code);
}

/*
Recursive function that divides the half until it is too little.
When the half is size 2 or 3, it sorts them directly to top_a.
*/
static bool	conquer(t_data *data, t_half *half)
{
	__u_int	n_mins;

	bottom_to_top(data, half);
	if (simplify_max(data, half))
		simplify_min_before(data, half, &n_mins);
	if (half->size == 0 || half->size == 1)
		;
	else if (half->size == 2 && !data->error_code)
		base_case_two(data, half, NULL);
	else if (half->size == 3 && !data->error_code)
		base_case_three(data, half);
	else if (!data->error_code)
	{
		if (divide(data, half))
		{
			if (conquer(data, half->max_half))
				conquer(data, half->min_half);
			else
				free(half->min_half);
		}
	}
	if (!data->error_code)
		simplify_min_after(data, half, n_mins);
	free(half);
	return (!data->error_code);
}
