/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:15:16 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/07/19 20:26:57 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
TODO description
*/
void	base_case_two(t_data *data, t_half *half)
{
	const t_move	top_a_10[] = {sa, no};
	const t_move	bot_a_10[] = {rra, rra, sa, no};
	const t_move	top_b_01_x[] = {sb, pa, pa, no};
	const t_move	top_b_01_y[] = {pa, pa, sa, no};
	const t_move	bot_b_10[] = {rrb, rrb, pa, pa, no};
	t_move			*aux;

	if (half->location == top_a)
		aux = (t_move *)top_a_10;
	else if (half->location == bot_a)
		aux = (t_move *)bot_a_10;
	else if (half->location == top_b && (data->move_list_last->move == sa
		|| data->move_list_last->move == sb))
		aux = (t_move *)top_b_01_x;
	else if (half->location == top_b)
		aux = (t_move *)top_b_01_y;
	else
		aux = (t_move *)bot_b_10;
	while (*aux)
		move(data, *aux++);
}

/*
TODO description
*/
void	base_case_three(t_data *data, t_half *half)
{
	const t_move	top_a_120[] = {pb, sa, pa, sa, no};
	const t_move	top_a_201[] = {sa, pb, sa, pa, no};
	const t_move	top_a_210[] = {sa, pb, sa, pa, sa, no};

	const t_move	bot_a_021[] = {rra, rra, sa, rra, sa, no};
	const t_move	bot_a_102[] = {rra, rra, pb, rra, sa, pa, no};
	const t_move	bot_a_012[] = {rra, pb, rra, rra, sa, pa, no};

	const t_move	top_b_021[] = {pa, pa, sa, pa, sa, no};
	const t_move	top_b_102[] = {pa, sb, pa, sa, pa, no};
	const t_move	top_b_012_x[] = {sb, pa, sb, pa, sa, pa, no};
	const t_move	top_b_012_y[] = {pa, sb, pa, sa, pa, sa, no};

	const t_move	bot_b_021[] = {rrb, rrb, pa, rrb, pa, pa, no};
	const t_move	bot_b_102[] = {rrb, rrb, sb, rrb, pa, pa, pa, no};
	const t_move	bot_b_012[] = {rrb, rrb, rrb, pa, pa, pa, no};
	t_move			*aux;

	if (half->location == top_a)
	{
		if (get_first_stack(data, half)->index < get_first_stack(data, half)->next->index)
			aux = (t_move *)top_a_120;
		else if (get_first_stack(data, half)->next->index < get_first_stack(data, half)->next->next->index)
			aux = (t_move *)top_a_201;
		else
			aux = (t_move *)top_a_210;
	}
	else if (half->location == bot_a)
	{
		if (get_first_stack(data, half)->index > get_first_stack(data, half)->prev->index)
			aux = (t_move *)bot_a_102;
		else if (get_first_stack(data, half)->prev->index > get_first_stack(data, half)->prev->prev->index)
			aux = (t_move *)bot_a_021;
		else
			aux = (t_move *)bot_a_012;
	}
	else if (half->location == top_b)
	{
		if (get_first_stack(data, half)->index > get_first_stack(data, half)->next->index)
			aux = (t_move *)top_b_102;
		else if (get_first_stack(data, half)->next->index > get_first_stack(data, half)->next->next->index)
			aux = (t_move *)top_b_021;
		else if (data->move_list_last->move == sa || data->move_list_last->move == sb)
			aux = (t_move *)top_b_012_x;
		else
			aux = (t_move *)top_b_012_y;
	}
	else
	{
		if (get_first_stack(data, half)->index > get_first_stack(data, half)->prev->index)
			aux = (t_move *)bot_b_102;
		else if (get_first_stack(data, half)->prev->index > get_first_stack(data, half)->prev->prev->index)
			aux = (t_move *)bot_b_021;
		else
			aux = (t_move *)bot_b_012;
	}

	while (*aux)
		move(data, *aux++);
}
