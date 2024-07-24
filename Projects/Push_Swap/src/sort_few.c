/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_few.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 19:13:01 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/07/24 18:58:13 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Sorts the two items in stack_a.
Moves:
0 1 -> done
1 0 -> swap
*/
t_error	sort_two(t_data *data)
{
	unsigned int	first;
	unsigned int	second;

	first = data->top_a->index;
	second = data->top_a->next->index;
	if (first > second)
		return (move(data, sa));
	return(success);
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
t_error	sort_three(t_data *data)
{
	unsigned int	first;
	unsigned int	second;
	unsigned int	third;
	t_error			error_code;

	first = data->top_a->index;
	second = data->top_a->next->index;
	third = data->top_a->next->next->index;
	if (first < second && second > third && first < third)
	{//TODO
		if (!(error_code = move(data, sa)))
			return (move(data, ra));
	}
	if (first > second && second < third && first < third)
		return (move(data, sa));
	if (first < second && second > third && first > third)
		return (move(data, rra));
	if (first > second && second < third && first > third)
		return (move(data, ra));
	if (first > second && second > third)//TODO
	{
		if (!(error_code = move(data, sa)))
			return (move(data, rra));
	}
	return (success);
}
