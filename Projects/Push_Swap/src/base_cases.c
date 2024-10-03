/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:15:16 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/03 09:46:35 by pdel-olm         ###   ########.fr       */
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
	const t_move	top_a_10[] = {SA, NO};
	const t_move	bot_a_10[] = {RRA, RRA, SA, NO};
	const t_move	top_b_01_x[] = {SB, PA, PA, NO};
	const t_move	top_b_01_y[] = {PA, PA, SA, NO};
	const t_move	bot_b_10[] = {RRB, RRB, PA, PA, NO};

	if (half->location == TOP_A)
		result = (t_move *)top_a_10;
	else if (half->location == BOT_A)
		result = (t_move *)bot_a_10;
	else if (half->location == TOP_B && (data->move_list_last->move == SA
			|| data->move_list_last->move == SB))
		result = (t_move *)top_b_01_x;
	else if (half->location == TOP_B)
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
	const t_move	top_a_120[] = {PB, SA, PA, SA, NO};
	const t_move	top_a_201[] = {SA, PB, SA, PA, NO};
	const t_move	top_a_210[] = {SA, PB, SA, PA, SA, NO};
	t_move			*result;

	if (half->location == TOP_A)
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
	else if (half->location == BOT_A)
		base_case_three_bot_a(data, half);
	else if (half->location == TOP_B)
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
	const t_move	bot_a_021[] = {RRA, RRA, SA, RRA, SA, NO};
	const t_move	bot_a_102[] = {RRA, RRA, PB, RRA, SA, PA, NO};
	const t_move	bot_a_012[] = {RRA, PB, RRA, RRA, SA, PA, NO};
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
	const t_move	top_b_021[] = {PA, PA, SA, PA, SA, NO};
	const t_move	top_b_102[] = {PA, SB, PA, SA, PA, NO};
	const t_move	top_b_012_x[] = {SB, PA, SB, PA, SA, PA, NO};
	const t_move	top_b_012_y[] = {PA, SB, PA, SA, PA, SA, NO};
	t_move			*result;

	if (get_first_node(data, half)->index
		> get_first_node(data, half)->next->index)
		result = (t_move *)top_b_102;
	else if (get_first_node(data, half)->next->index
		> get_first_node(data, half)->next->next->index)
		result = (t_move *)top_b_021;
	else if (data->move_list_last->move == SA
		|| data->move_list_last->move == SB)
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
	const t_move	bot_b_021[] = {RRB, RRB, PA, RRB, PA, PA, NO};
	const t_move	bot_b_102[] = {RRB, RRB, SB, RRB, PA, PA, PA, NO};
	const t_move	bot_b_012[] = {RRB, RRB, RRB, PA, PA, PA, NO};
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
