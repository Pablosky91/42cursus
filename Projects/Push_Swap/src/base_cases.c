/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:15:16 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/07/25 21:05:30 by pdel-olm         ###   ########.fr       */
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
bool	base_case_two(t_data *data, t_half *half, t_move *result)
{
	const t_move	top_a_10[] = {sa, no};
	const t_move	bot_a_10[] = {rra, rra, sa, no};
	const t_move	top_b_01_x[] = {sb, pa, pa, no};
	const t_move	top_b_01_y[] = {pa, pa, sa, no};
	const t_move	bot_b_10[] = {rrb, rrb, pa, pa, no};

	if (half->location == top_a)
		result = (t_move *)top_a_10;
	else if (half->location == bot_a)
		result = (t_move *)bot_a_10;
	else if (half->location == top_b && (data->move_list_last->move == sa
			|| data->move_list_last->move == sb))
		result = (t_move *)top_b_01_x;
	else if (half->location == top_b)
		result = (t_move *)top_b_01_y;
	else
		result = (t_move *)bot_b_10;
	while (*result && move(data, *result++))
		;
	return (!data->error_code);
}

/*
Base case for the recursive function conquer.
Places the three numbers in the given half to top_a.
*/
bool	base_case_three(t_data *data, t_half *half)
{
	const t_move	top_a_120[] = {pb, sa, pa, sa, no};
	const t_move	top_a_201[] = {sa, pb, sa, pa, no};
	const t_move	top_a_210[] = {sa, pb, sa, pa, sa, no};
	t_move			*result;

	if (half->location == top_a)
	{
		if (get_first_node(data, half)->index
			< get_first_node(data, half)->next->index)
			result = (t_move *)top_a_120;
		else if (get_first_node(data, half)->next->index
			< get_first_node(data, half)->next->next->index)
			result = (t_move *)top_a_201;
		else
			result = (t_move *)top_a_210;
		while (*result && move(data, *result++))
			;
	}
	else if (half->location == bot_a)
		base_case_three_bot_a(data, half);
	else if (half->location == top_b)
		base_case_three_top_b(data, half);
	else
		base_case_three_bot_b(data, half);
	return (!data->error_code);
}

/*
Particular case of base_case_three where the given half is in the bot_a location.
*/
void	base_case_three_bot_a(t_data *data, t_half *half)
{
	const t_move	bot_a_021[] = {rra, rra, sa, rra, sa, no};
	const t_move	bot_a_102[] = {rra, rra, pb, rra, sa, pa, no};
	const t_move	bot_a_012[] = {rra, pb, rra, rra, sa, pa, no};
	t_move			*result;

	if (get_first_node(data, half)->index
		> get_first_node(data, half)->prev->index)
		result = (t_move *)bot_a_102;
	else if (get_first_node(data, half)->prev->index
		> get_first_node(data, half)->prev->prev->index)
		result = (t_move *)bot_a_021;
	else
		result = (t_move *)bot_a_012;
	while (*result && move(data, *result++))
		;
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
	t_move			*result;

	if (get_first_node(data, half)->index
		> get_first_node(data, half)->next->index)
		result = (t_move *)top_b_102;
	else if (get_first_node(data, half)->next->index
		> get_first_node(data, half)->next->next->index)
		result = (t_move *)top_b_021;
	else if (data->move_list_last->move == sa
		|| data->move_list_last->move == sb)
		result = (t_move *)top_b_012_x;
	else
		result = (t_move *)top_b_012_y;
	while (*result && move(data, *result++))
		;
}

/*
Particular case of base_case_three where the given half is in the bot_b location.
*/
void	base_case_three_bot_b(t_data *data, t_half *half)
{
	const t_move	bot_b_021[] = {rrb, rrb, pa, rrb, pa, pa, no};
	const t_move	bot_b_102[] = {rrb, rrb, sb, rrb, pa, pa, pa, no};
	const t_move	bot_b_012[] = {rrb, rrb, rrb, pa, pa, pa, no};
	t_move			*result;

	if (get_first_node(data, half)->index
		> get_first_node(data, half)->prev->index)
		result = (t_move *)bot_b_102;
	else if (get_first_node(data, half)->prev->index
		> get_first_node(data, half)->prev->prev->index)
		result = (t_move *)bot_b_021;
	else
		result = (t_move *)bot_b_012;
	while (*result && move(data, *result++))
		;
}
