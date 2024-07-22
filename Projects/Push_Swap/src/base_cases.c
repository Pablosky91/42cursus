/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:15:16 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/07/22 19:23:39 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	base_case_three_bot_a(t_data *data, t_half *half);
static void	base_case_three_top_b(t_data *data, t_half *half);
static void	base_case_three_bot_b(t_data *data, t_half *half);

/*
Base case for the recursive function conquer.
Places the two numbers in the given half to top_a.
*/
void	base_case_two(t_data *data, t_half *half, t_move *aux)
{
	const t_move	top_a_10[] = {sa, no};
	const t_move	bot_a_10[] = {rra, rra, sa, no};
	const t_move	top_b_01_x[] = {sb, pa, pa, no};
	const t_move	top_b_01_y[] = {pa, pa, sa, no};
	const t_move	bot_b_10[] = {rrb, rrb, pa, pa, no};

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
Base case for the recursive function conquer.
Places the three numbers in the given half to top_a.
*/
void	base_case_three(t_data *data, t_half *half)
{
	const t_move	top_a_120[] = {pb, sa, pa, sa, no};
	const t_move	top_a_201[] = {sa, pb, sa, pa, no};
	const t_move	top_a_210[] = {sa, pb, sa, pa, sa, no};
	t_move			*aux;

	if (half->location == top_a)
	{
		if (get_first_node(data, half)->index
			< get_first_node(data, half)->next->index)
			aux = (t_move *)top_a_120;
		else if (get_first_node(data, half)->next->index
			< get_first_node(data, half)->next->next->index)
			aux = (t_move *)top_a_201;
		else
			aux = (t_move *)top_a_210;
		while (*aux)
			move(data, *aux++);
	}
	else if (half->location == bot_a)
		base_case_three_bot_a(data, half);
	else if (half->location == top_b)
		base_case_three_top_b(data, half);
	else
		base_case_three_bot_b(data, half);
}

/*
Particular case of base_case_three where the given half is in the bot_a location.
*/
void	base_case_three_bot_a(t_data *data, t_half *half)
{
	const t_move	bot_a_021[] = {rra, rra, sa, rra, sa, no};
	const t_move	bot_a_102[] = {rra, rra, pb, rra, sa, pa, no};
	const t_move	bot_a_012[] = {rra, pb, rra, rra, sa, pa, no};
	t_move			*aux;

	if (get_first_node(data, half)->index
		> get_first_node(data, half)->prev->index)
		aux = (t_move *)bot_a_102;
	else if (get_first_node(data, half)->prev->index
		> get_first_node(data, half)->prev->prev->index)
		aux = (t_move *)bot_a_021;
	else
		aux = (t_move *)bot_a_012;
	while (*aux)
		move(data, *aux++);
}

/*
Particular case of base_case_three where the given half is in the top_b location.
*/
void	base_case_three_top_b(t_data *data, t_half *half)
{
	const t_move	top_b_021[] = {pa, pa, sa, pa, sa, no};
	const t_move	top_b_102[] = {pa, sb, pa, sa, pa, no};
	const t_move	top_b_012_x[] = {sb, pa, sb, pa, sa, pa, no};
	const t_move	top_b_012_y[] = {pa, sb, pa, sa, pa, sa, no};
	t_move			*aux;

	if (get_first_node(data, half)->index
		> get_first_node(data, half)->next->index)
		aux = (t_move *)top_b_102;
	else if (get_first_node(data, half)->next->index
		> get_first_node(data, half)->next->next->index)
		aux = (t_move *)top_b_021;
	else if (data->move_list_last->move == sa
		|| data->move_list_last->move == sb)
		aux = (t_move *)top_b_012_x;
	else
		aux = (t_move *)top_b_012_y;
	while (*aux)
		move(data, *aux++);
}

/*
Particular case of base_case_three where the given half is in the bot_b location.
*/
void	base_case_three_bot_b(t_data *data, t_half *half)
{
	const t_move	bot_b_021[] = {rrb, rrb, pa, rrb, pa, pa, no};
	const t_move	bot_b_102[] = {rrb, rrb, sb, rrb, pa, pa, pa, no};
	const t_move	bot_b_012[] = {rrb, rrb, rrb, pa, pa, pa, no};
	t_move			*aux;

	if (get_first_node(data, half)->index
		> get_first_node(data, half)->prev->index)
		aux = (t_move *)bot_b_102;
	else if (get_first_node(data, half)->prev->index
		> get_first_node(data, half)->prev->prev->index)
		aux = (t_move *)bot_b_021;
	else
		aux = (t_move *)bot_b_012;
	while (*aux)
		move(data, *aux++);
}
