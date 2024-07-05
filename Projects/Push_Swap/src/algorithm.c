/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:08:21 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/07/05 23:21:09 by pdel-olm         ###   ########.fr       */
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

/*
Returns the first stack of the given half->location
*/
t_stack	*get_first_stack(t_half *half, t_data *data)
{
	t_stack	*stack;

	if (half->location == top_a)
		stack = data->top_a;
	else if (half->location == bot_a)
		stack = data->bot_a;
	else if (half->location == top_b)
		stack = data->top_b;
	else if (half->location == bot_b)
		stack = data->bot_b;
	return (stack);
}

/*
Iterates the stack to the next if the half is located at top.
Iterates the stack to the prev if the half is located at bot.
If the stack is null, it initialises to the first stack.
If the stack were to exit the half, the stack is replaced by null.
Returns true if the next/prev stack still is the same half.
*/
bool	stack_forward(t_stack **stack, t_half *half, t_data *data)
{
	t_stack	*aux;

	aux = 0;
	if (!(*stack))
		*stack = get_first_stack(half, data);
	else if (half->location == top_a || half->location == top_b)
		*stack = (*stack)->next;
	else
		*stack = (*stack)->prev;
	if (*stack
		&& ((*stack)->index < half->min_num || (*stack)->index > half->max_num))
		*stack = 0;
	if (*stack && (half->location == top_a || half->location == top_b))
		aux = (*stack)->next;
	else if (*stack)
		aux = (*stack)->prev;
	return (aux && aux->index >= half->min_num && aux->index <= half->max_num);
}

/*
Iterates the stack to the prev if the half is located at top.
Iterates the stack to the next if the half is located at bot.
Returns true if it is the first stack of the half.
*/
bool	stack_backward(t_stack **stack, t_half *half)
{
	t_stack	*aux;

	aux = 0;
	if (half->location == top_a || half->location == top_b)
		*stack = (*stack)->prev;
	else
		*stack = (*stack)->next;
	if (*stack && (half->location == top_a || half->location == top_b))
		aux = (*stack)->prev;
	else if (*stack)
		aux = (*stack)->next;
	return (aux);
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
	//half->min_half->mid_num = half->min_half->max_num - half->min_half->size / 2;
	half->max_half->size = (half->size) / 2;
	half->max_half->min_num = half->max_num - half->max_half->size + 1;
	half->max_half->max_num = half->max_num;
	//half->max_half->mid_num = half->max_half->max_num - half->max_half->size / 2;
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

	//simplify max
	aux = get_first_stack(half, data);
	if (half->location == top_a)
		while (stack_forward(&aux, half, data))
			;
	while (aux && half->size > 0 && aux->index == half->max_num)
	{
		if (half->location == top_a)
			stack_backward(&aux, half);
		else
			stack_forward(&aux, half, data);
		half->max_num--;
		half->size--;
		if (half->location != top_a)
			move_from_to(data, half->location, false);
	}
	//end simplify max
	
	
	//simplify min
/* 	int n_mins = 0;
	if (half->location == top_a)
	{
		aux = data->top_a;
		while (aux && half->size > 0 && aux->index == half->min_num)
		{
			aux = aux->next;
			half->min_num++;
			half->size--;
			n_mins++;
			printf("min\n");
			move_from_to(data, top_a, true);
		}
	} */



	//base case 1
	if (half->size == 1 && half->location != top_a)
		move_from_to(data, half->location, top_a);
	else if (half->size == 0 || half->size == 1)
		;
	//base case 2
	else if (half->size == 2)
		base_case_2(data, half);
	//base case 3
	/* if (half->size == 3)
		base_case_3(data, half); */
	else
	{
		i = 0;
		//TODO remove mid from structure
		half->mid_num = (half->min_num + half->max_num) / 2;
		halve(half);
		while (i < half->size)
		{
			aux = get_first_stack(half, data);
			move_from_to(data, half->location, aux->index <= half->mid_num);
			i++;
		}
		recursive(data, half->max_half);
		free(half->max_half);
		recursive(data, half->min_half);
		free(half->min_half);
		// TODO maybe just free(half); here instead
	}
/* 	printf(" %i\n", n_mins);
	while (n_mins >= 0)
	{
		move_from_to(data, top_b, false);
		n_mins--;
	} */
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
