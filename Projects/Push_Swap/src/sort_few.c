/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_few.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 19:13:01 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/07/22 20:30:04 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Sorts the two items in stack_a.
Moves:
0 1 -> done
1 0 -> swap
*/
void	sort_two(t_data *data)
{
	unsigned int	first;
	unsigned int	second;

	first = data->top_a->index;
	second = data->top_a->next->index;
	if (first > second)
		move(data, sa);
}

/*
Sorts the three items in stack_a.
Moves:
0 1 2 -> done
0 2 1 -> swap, rotate
1 0 2 -> swap
1 2 0 -> reverse rotate
2 0 1 -> rotate
2 1 0 -> swap, reverse rotate
*/
void	sort_three(t_data *data)
{
	unsigned int	first;
	unsigned int	second;
	unsigned int	third;

	first = data->top_a->index;
	second = data->top_a->next->index;
	third = data->top_a->next->next->index;
	if (first < second && second > third && first < third)
		return (move(data, sa), move(data, ra));
	if (first > second && second < third && first < third)
		return (move(data, sa));
	if (first < second && second > third && first > third)
		return (move(data, rra));
	if (first > second && second < third && first > third)
		return (move(data, ra));
	if (first > second && second > third)
		return (move(data, sa), move(data, rra));
}
