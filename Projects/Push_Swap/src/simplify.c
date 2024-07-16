/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplify.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:15:18 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/07/16 17:57:31 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bottom_to_top(t_data *data, t_half *half)
{
	if (half->location == bot_a && half->size == data->size_a)
		half->location = top_a;
	else if (half->location == bot_b && half->size == data->size_b)
		half->location = top_b;
}

void	simplify_max(t_data *data, t_half *half)
{
	t_stack	*aux;

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
}

unsigned int	simplify_min(t_data *data, t_half *half)
{
	t_stack			*aux;
	unsigned int	n_mins;

	n_mins = 0;
	aux = get_first_stack(half, data);
	if (half->location != top_a)
		while (stack_forward(&aux, half, data))
			;
	while (aux && half->size > 0 && aux->index == half->min_num)
	{
		if (half->location != top_a)
			stack_backward(&aux, half);
		else
			stack_forward(&aux, half, data);
		half->min_num++;
		half->size--;
		n_mins++;
		if (half->location == top_a)
			move(data, pb);
	}
	return (n_mins);
}
