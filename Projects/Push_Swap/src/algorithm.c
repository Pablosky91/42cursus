/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:08:21 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/07/19 19:38:42 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	divide(t_data *data, t_half *half);
static void	conquer(t_data *data, t_half *half);

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

//TODO which file?
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

static void	divide(t_data *data, t_half *half)
{
	unsigned int	i;

	i = 0;
	half->min_half = malloc(sizeof(t_half));
	half->max_half = malloc(sizeof(t_half));
	if (half->location != top_a)
		half->max_half->location = top_a;
	else
		half->max_half->location = bot_a;
	if (half->location != top_b)
		half->min_half->location = top_b;
	else
		half->min_half->location = bot_b;
	half->min_half->size = (half->size + 1) / 2;
	half->min_half->min_num = half->min_num;
	half->min_half->max_num = half->min_num + half->min_half->size - 1;
	half->max_half->size = (half->size) / 2;
	half->max_half->min_num = half->max_num - half->max_half->size + 1;
	half->max_half->max_num = half->max_num;
	while (i < half->size)
	{
		move_from_to(data, half->location, get_first_stack(data, half)->index
			<= (half->min_num + half->max_num) / 2);
		i++;
	}
}

static void	conquer(t_data *data, t_half *half)
{
	unsigned int	n_mins;

	bottom_to_top(data, half);
	simplify_max(data, half);
	n_mins = simplify_min_before(data, half);
	if (half->size == 0 || half->size == 1)
		;
	else if (half->size == 2)
		base_case_2(data, half);
	else if (half->size == 3)
		base_case_3(data, half);
	else
	{
		divide(data, half);
		conquer(data, half->max_half);
		conquer(data, half->min_half);
	}
	simplify_min_after(data, half, n_mins);
	free(half);
}
