/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:08:21 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/07/02 21:42:32 by pdel-olm         ###   ########.fr       */
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
		return (moves(data, sa + is_b), moves(data, ra + is_b));
	if (first > second && second < third && first < third)
		return (moves(data, sa + is_b));
	if (first < second && second > third && first > third)
		return (moves(data, rra + is_b));
	if (first > second && second < third && first > third)
		return (moves(data, ra + is_b));
	if (first > second && second > third)
		return (moves(data, sa + is_b), moves(data, rra + is_b));
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
		moves(data, sa + is_b);
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
			moves(data, pb);
			moved++;
		}
		else
			moves(data, ra);
	}
	sort_three(data, false);
	if (pivot == 2)
		sort_two(data, true);
	else if (pivot == 3)
		sort_three(data, true);
	while (moved > 0)
	{
		moves(data, pa);
		moved--;
	}
}

void	move_from_to(t_data *data, t_location from, bool is_min)
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

void	base_case_2(t_data *data, t_half *half)
{
	const t_move	top_a_10[] = {sa, no};
	const t_move	bot_a_01[] = {rra, rra, sa, no};
	const t_move	top_b_01[] = {sb, pa, pa, no};
	const t_move	bot_b_01[] = {rrb, rrb, pa, pa, no};
	t_move			*aux;

	if (half->location == top_a)
		aux = (t_move *)top_a_10;
	else if (half->location == bot_a)
		aux = (t_move *)bot_a_01;
	else if (half->location == top_b)
		aux = (t_move *)top_b_01;
	else if (half->location == bot_b)
		aux = (t_move *)bot_b_01;
	while (*aux)
		moves(data, *aux++);
}

void	base_case_3(t_data *data, t_half *half)
{
	(void) data;
	(void) half;
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
		//is bottom top?
	if (half->location == bot_a && half->size == data->size_a)
		half->location = top_a;
	else if (half->location == bot_b && half->size == data->size_b)
		half->location = top_b;
	//ft_printf("%i %i-%i\n", half->location, half->min_num, half->max_num);
	//show_stacks(data);
	i = 0;
	if (half->location == top_a)
	{
		aux = data->top_a;
		while (i < half->size - 1){
			i++;
			aux = aux->next;
		}
		while (aux && aux->index == half->max_num)
		{
			aux = aux->prev;
			half->max_num--;
			half->size--;
			//ft_printf("-ta\n");
		}
	}
	if (half->location == bot_a)
	{
		aux = data->bot_a;
		while (aux && half->size > 0 && aux->index == half->max_num)
		{
			aux = aux->prev;
			half->max_num--;
			half->size--;
			//ft_printf("-ba\n");
			//moves(data, rra);
			//show_stacks(data);
			move_from_to(data, bot_a, false);
		}
	}
	else if (half->location == top_b)
	{
		aux = data->top_b;
		while (aux && half->size > 0 && aux->index == half->max_num)
		{
			aux = aux->next;
			half->max_num--;
			half->size--;
			//ft_printf("-tb\n");
			//moves(data, pa);
			//show_stacks(data);
			move_from_to(data, top_b, false);
		}
	}
	else if (half->location == bot_b)
	{
		aux = data->bot_b;
		while (aux && half->size > 0 && aux->index == half->max_num)
		{
			aux = aux->prev;
			half->max_num--;
			half->size--;
			//ft_printf("-bb\n");
			//moves(data, rrb);
			//moves(data, pa);
			//show_stacks(data);
			move_from_to(data, bot_b, false);
		}
	}






	

	//base case 1
	else if (half->size <= 1 && half->location != top_a)
		return (move_from_to(data, half->location, top_a));
	half->mid_num = (half->min_num + half->max_num) / 2;
	if (half->size <= 1)
		return ;
	//base case 2
	if (half->size == 2)
		return (base_case_2(data, half));
	//base case 3
	if (half->size == 3)
		base_case_3(data, half);
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
		//show_stacks(data);
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
	half->mid_num = (data->size_a - 1) / 2;
	recursive(data, half);
	free(half);
}
