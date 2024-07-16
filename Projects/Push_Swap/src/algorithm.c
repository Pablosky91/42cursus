/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:08:21 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/07/16 23:32:59 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Sorts the three items in a stack.
If is_b is false, the stack to sort is stack_a.
If is_b is true, the stack to sort is stack_b.
Movements:
0 1 2 -> done
0 2 1 -> swap rotate
1 0 2 -> swap
1 2 0 -> reverse rotate
2 0 1 -> rotate
2 1 0 -> swap reverse rotate
*/
void	sort_three(t_data *data, bool is_b)
{
	t_stack			*stack;
	unsigned int	first;
	unsigned int	second;
	unsigned int	third;

	if (is_b)
		stack = data->top_b;
	else
		stack = data->top_a;
	first = stack->index;
	second = stack->next->index;
	third = stack->next->next->index;
	if (first < second && second > third && first < third)
		return (move(data, sa + is_b), move(data, ra + is_b));
	if (first > second && second < third && first < third)
		return (move(data, sa + is_b));
	if (first < second && second > third && first > third)
		return (move(data, rra + is_b));
	if (first > second && second < third && first > third)
		return (move(data, ra + is_b));
	if (first > second && second > third)
		return (move(data, sa + is_b), move(data, rra + is_b));
}

/*
Sorts the three items in a stack.
If is_b is false, the stack to sort is stack_a.
If is_b is true, the stack to sort is stack_b.
Movements:
0 1 -> done
1 0 -> swap
*/
void	sort_two(t_data *data, bool is_b)
{
	t_stack			*stack;
	unsigned int	first;
	unsigned int	second;

	if (is_b)
		stack = data->top_b;
	else
		stack = data->top_a;
	first = stack->index;
	second = stack->next->index;
	if (first > second)
		move(data, sa + is_b);
}

//TODO sort stack b descending
/*
Sorts 4, 5 or 6 numbers.
Moves all but the 3 greatest to stack_b.
Sorts both stacks.
Pushes stack_b to stack_a.
*/
void	sort_few(t_data *data)
{
	unsigned int	pivot;
	unsigned int	moved;

	pivot = data->size_a - 3;
	moved = 0;
	while (moved < pivot)
	{
		if (data->top_a->index < pivot)
		{
			move(data, pb);
			moved++;
		}
		else
			move(data, ra);
	}
	sort_three(data, false);
	if (pivot == 2)
		sort_two(data, true);
	else if (pivot == 3)
		sort_three(data, true);
	while (moved > 0)
	{
		move(data, pa);
		moved--;
	}
}

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

void	halve(t_half *half)
{
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
}

void	recursive(t_data *data, t_half *half)
{
	unsigned int	i;
	unsigned int	n_mins;
	t_stack			*aux;

	bottom_to_top(data, half);
	simplify_max(data, half);
	//TODO check if size == 0?
	n_mins = simplify_min(data, half);

	//base case 1
	if (half->size == 1 && half->location != top_a)
		move_from_to(data, half->location, top_a);
	else if (half->size == 0 || half->size == 1)
		;
	//base case 2
	else if (half->size == 2)
		base_case_2(data, half);
	//base case 3
	else if (half->size == 3)
		base_case_3(data, half);
	else
	{
		i = 0;
		halve(half);
		while (i < half->size)
		{
			aux = get_first_stack(half, data);
			move_from_to(data, half->location, aux->index <= (half->min_num + half->max_num) / 2);
			i++;
		}
		recursive(data, half->max_half);
		free(half->max_half);
		recursive(data, half->min_half);
		free(half->min_half);
	}
	while (n_mins > 0)
	{
		if (half->location == top_a)
			half->location = top_b;
		move_from_to(data, half->location, false);
		n_mins--;
	}
		// TODO maybe just free(half); here instead
}

void	sort(t_data *data)
{
	t_half	*half;

	/* if (data->size_a == 2)
		return (sort_two(data, false));
	if (data->size_a == 3)
		return (sort_three(data, false));
	if (data->size_a >= 4 && data->size_a <= 6)
		return (sort_few(data)); */
	half = malloc(sizeof(t_half));
	half->location = top_a;
	half->size = data->size_a;
	half->min_num = 0;
	half->max_num = data->size_a - 1;
	recursive(data, half);
	free(half);
}
