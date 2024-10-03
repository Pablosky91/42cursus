/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:24:35 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/03 09:46:41 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static bool		initialize(t_data **data);
static bool		read_instructions(t_data *data);
static bool		is_ordered(t_data *data);
static t_move	get_move_string(char *move);

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 2)
		return (SUCCESS);
	if (!initialize(&data))
		error(data);
	if (!read_data(data, argc, argv))
		error(data);
	if (!read_instructions(data))
		error(data);
	if (is_ordered(data))
		ft_putendl_fd(OK_MESSAGE, STDOUT_FILENO);
	else
		ft_putendl_fd(KO_MESSAGE, STDOUT_FILENO);
	free_data(data);
	return (SUCCESS);
}

/*
Initializes the data structure.
*/
static bool	initialize(t_data **data)
{
	*data = malloc(sizeof(t_data));
	if (!*data)
		return (false);
	(*data)->top_a = NULL;
	(*data)->bot_a = NULL;
	(*data)->top_b = NULL;
	(*data)->bot_b = NULL;
	(*data)->size_a = 0;
	(*data)->size_b = 0;
	(*data)->move_list_first = NULL;
	(*data)->move_list_last = NULL;
	(*data)->error_code = SUCCESS;
	return (true);
}

/*
Reads the input from the console.
While they are valid moves, it executes them.
If it encounters an invalid move, it returns false.
*/
static bool	read_instructions(t_data *data)
{
	char	*line;
	t_move	move;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		move = get_move_string(line);
		free(line);
		if (!move)
			return (provoke_error(data, NOT_A_MOVE));
		execute_move(data, move);
		line = get_next_line(STDIN_FILENO);
	}
	free(line);
	return (true);
}

/*
Checks if all the numbers if stack_a are properly ordered and stack_b is empty.
*/
static bool	is_ordered(t_data *data)
{
	t_node	*iter;

	if (data->top_b)
		return (false);
	iter = data->top_a;
	while (iter)
	{
		if (iter->prev && iter->prev->content >= iter->content)
			return (false);
		iter = iter->next;
	}
	return (true);
}

/*
Returns the given string as a t_move.
*/
static t_move	get_move_string(char *move)
{
	if (ft_str_equals(move, "sa\n"))
		return (SA);
	else if (ft_str_equals(move, "sb\n"))
		return (SB);
	else if (ft_str_equals(move, "ss\n"))
		return (SS);
	else if (ft_str_equals(move, "pa\n"))
		return (PA);
	else if (ft_str_equals(move, "pb\n"))
		return (PB);
	else if (ft_str_equals(move, "ra\n"))
		return (RA);
	else if (ft_str_equals(move, "rb\n"))
		return (RB);
	else if (ft_str_equals(move, "rr\n"))
		return (RR);
	else if (ft_str_equals(move, "rra\n"))
		return (RRA);
	else if (ft_str_equals(move, "rrb\n"))
		return (RRB);
	else if (ft_str_equals(move, "rrr\n"))
		return (RRR);
	return (NO);
}
