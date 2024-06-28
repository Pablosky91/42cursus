/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:08:21 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/06/28 20:56:50 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//TODO content index 2 3
// 1 2 3 -> done
// 1 3 2 -> sa ra
// 2 1 3 -> sa
// 2 3 1 -> rra
// 3 1 2 -> ra
// 3 2 1 -> sa rra
//sorts the three items in stack_a
//TODO remove is_b and the check for 3 numbers
void	sort_three(t_data *data, bool is_b)
{
	t_stack	*stack;
	int		first;
	int		second;
	int		third;

	stack = data->top_a;
	if (is_b)
		stack = data->top_b;
	if (!stack || !stack->next || !stack->next->next
		|| stack->next->next->next)
		return ;
	first = stack->content;
	second = stack->next->content;
	third = stack->next->next->content;
	if (first < second && second > third && first < third)
		return (moves(data, sa + is_b), moves(data, ra + is_b));
	if (first > second && second < third && first < third)
		return (moves(data, sa + is_b));
	if (first < second && second > third && first > third)
		return (moves(data, rra + is_b));
	if (first > second && second < third && first > third)
		return (moves(data, ra + is_b));
	if (first > second && second > third)
		return (moves(data, sa + is_b),
			moves(data, rra + is_b));
}

//TODO remove is_b and the check for 2 numbers
void	sort_two(t_data *data, bool is_b)
{
	t_stack	*stack;
	int		first;
	int		second;

	stack = data->top_a;
	if (is_b)
		stack = data->top_b;
	if (!stack || !stack->next || stack->next->next)
		return ;
	first = stack->content;
	second = stack->next->content;
	if (first > second)
		moves(data, sa + is_b);
}

void move_from_to(t_data *data, t_location from, bool is_min)
{
	if (from == top_a && !is_min)
		return (moves(data, ra));
	if (from == top_a && is_min)
		return (moves(data, pb));
	if (from == bot_a && !is_min)
		return (moves(data, rra));
	if (from == bot_a && is_min)
		return (moves(data, rra), moves(data, pb));
	if (from == top_b && !is_min)
		return (moves(data, pa));
	if (from == top_b && is_min)
		return (moves(data, rb));
	if (from == bot_b && !is_min)
		return (moves(data, rrb), moves(data, pa));
	if (from == bot_b && is_min)
		return (moves(data, rrb));
}

void	halve(t_half *half)
{
	half->min_half = malloc(sizeof(t_half));
	half->max_half = malloc(sizeof(t_half));
	if (half->location == top_a)
		half->max_half->location = bot_a;
	else
		half->max_half->location = top_a;
	if (half->location == top_b)
		half->min_half->location = bot_b;
	else
		half->min_half->location = top_b;
	half->min_half->size = (half->size + 1) / 2;
	half->min_half->min_num = half->min_num;
	half->min_half->max_num = half->min_num + half->min_half->size - 1;
	half->min_half->mid_num = half->min_half->max_num - half->min_half->size / 2;
	half->max_half->size = (half->size) / 2;
	half->max_half->min_num = half->max_num - half->max_half->size + 1;
	half->max_half->max_num = half->max_num;
	half->max_half->mid_num = half->max_half->max_num - half->max_half->size / 2;
}

		//system("clear");
		//show_stacks(data);
		//sleep(1);
		/* if (half->location == top_a || half->location == top_b)
			aux = aux->next;
		else
			aux = aux->prev; */
void	recursive(t_data *data, t_half *half)
{
	unsigned int	i;
	t_stack			*aux;
	
	if (half->size <= 1 && half->location != top_a)
		return (move_from_to(data, half->location, top_a));
	else if (half->size <= 1)
		return ;
	i = 0;
	halve(half);
	while (i < half->size)
	{
		if (half->location == top_a)
			aux = data->top_a;
		else if (half->location == bot_a)
			aux = data->bot_a;
		else if (half->location == top_b)
			aux = data->top_b;
		else if (half->location == bot_b)
			aux = data->bot_b;
		move_from_to(data, half->location, aux->index <= half->mid_num);
		show_stacks(data);
		i++;
	}
	recursive(data, half->max_half);
	free(half->max_half);
	recursive(data, half->min_half);
	free(half->min_half);
}

void	sort(t_data *data)
{
	t_half	*half;
	if(data->size == 2)
		return (sort_two(data, false));
	if(data->size == 3)
		return (sort_three(data, false));
/* 	if(data->size == 5)
		return (sort_five(data, false)); */
	half = malloc(sizeof(t_half));
	half->location = top_a;
	half->size = data->size;
	half->min_num = 0;
	half->max_num = data->size - 1;
	half->mid_num = (data->size - 1) / 2;
	recursive(data, half);
	free(half);
}
