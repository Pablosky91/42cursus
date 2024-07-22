/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:08:21 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/07/22 20:47:54 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	divide(t_data *data, t_half *half);
static void	conquer(t_data *data, t_half *half);

/*
Sorts all the nodes in stack_a.
Divides the nodes in two halfs and sorts both of them.
*/
void	sort(t_data *data)
{
	t_half	*half;

	if (data->size_a == 2)
		return (sort_two(data));
	if (data->size_a == 3)
		return (sort_three(data));
	half = malloc(sizeof(t_half));
	half->location = top_a;
	half->size = data->size_a;
	half->min_num = 0;
	half->max_num = data->size_a - 1;
	conquer(data, half);
}

/*
Executes the given move and saves it in the list.
Updates the size of the stacks.
*/
void	move(t_data *data, t_move move)
{
	if (move == pa && data->size_b > 0)
	{
		data->size_a++;
		data->size_b--;
	}
	else if (move == pb && data->size_a > 0)
	{
		data->size_a--;
		data->size_b++;
	}
	execute_move(data, move);
	save_move(data, move);
}

/*
Moves a node from the given location to the corresponding location.
*/
void	move_from_to(t_data *data, t_location from, bool is_min)
{
	if (from == top_a && !is_min)
		return (move(data, ra));
	if (from == top_a && is_min)
		return (move(data, pb));
	if (from == bot_a && !is_min)
		return (move(data, rra));
	if (from == bot_a && is_min)
		return (move(data, rra), move(data, pb));
	if (from == top_b && !is_min)
		return (move(data, pa));
	if (from == top_b && is_min)
		return (move(data, rb));
	if (from == bot_b && !is_min)
		return (move(data, rrb), move(data, pa));
	if (from == bot_b && is_min)
		return (move(data, rrb));
}

/*
Divides the given half in two halfs.
One half is for the lower numbers and the other for the higher ones.
*/
static void	divide(t_data *data, t_half *half)
{
	unsigned int	i;

	i = 0;
	half->min_half = malloc(sizeof(t_half));
	half->max_half = malloc(sizeof(t_half));

	half->min_half->size = (half->size + 1) / 2;
	half->min_half->min_num = half->min_num;
	half->min_half->max_num = half->min_num + half->min_half->size - 1;
	half->max_half->size = (half->size) / 2;
	half->max_half->min_num = half->max_num - half->max_half->size + 1;
	half->max_half->max_num = half->max_num;
	while (i < half->size)
	{
		move_from_to(data, half->location, get_first_node(data, half)->index
			<= (half->min_num + half->max_num) / 2);
		i++;
	}
}

/*
Recursive function that divides the half until it is too little.
When the half is size 2 or 3, it sorts them directly to top_a.
*/
static void	conquer(t_data *data, t_half *half)
{
	unsigned int	n_mins;

	bottom_to_top(data, half);
	simplify_max(data, half);
	n_mins = simplify_min_before(data, half);
	if (half->size == 0 || half->size == 1)
		;
	else if (half->size == 2)
		base_case_two(data, half, NULL);
	else if (half->size == 3)
		base_case_three(data, half);
	else
	{
		divide(data, half);
		conquer(data, half->max_half);
		conquer(data, half->min_half);
	}
	simplify_min_after(data, half, n_mins);
	free(half);
}
