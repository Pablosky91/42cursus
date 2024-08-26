/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:45:12 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/08/26 20:36:20 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_checker(t_path_checker *checker)
{
	t_position_node	*iter;
	t_position_node	*next;
	
	iter = checker->head;
	while (iter)
	{
		next = iter->next;
		free(iter->position);
		free(iter);
		iter = next;
	}
	free(checker);
}

void	print_pos(t_position *position)
{
	printf("{%i, %i}", position->row, position->col);
}

void	print_path(t_path_checker	*checker)
{
	t_position_node	*node;
	
	node = checker->head;
	while (node != 0)
	{
		print_pos(node->position);
		node = node->next;
	}
	printf("\n");
}

bool	is_same_node(t_position_node *node_1, t_position_node *node_2)
{
	if (node_1->position->row != node_2->position->row)
		return (false);
	if (node_1->position->col != node_2->position->col)
		return (false);
	return (true);
}

bool	is_node_repeated(t_path_checker *checker, t_position_node *node)
{
	t_position_node	*iter;
	
	iter = checker->head;
	while (iter)
	{
		if (is_same_node(iter, node))
			return (true);
		iter = iter->next;
	}
	return (false);
}

t_position	*create_pos(__u_int row, __u_int col)
{
	t_position	*position;

	position = malloc(sizeof(t_position));
	position->row = row;
	position->col = col;
}

t_position_node	*create_node(t_position *position)
{
	t_position_node	*node;

	node = malloc(sizeof(t_position_node));
	node->position = position;
	node->next = NULL;
}

void	add_node(t_path_checker *checker, t_position_node	*node)
{
	if (!checker->head)
		checker->head = node;
	if (checker->tail)
		checker->tail->next = node;
	checker->tail = node;
}

t_position	*get_position_slide(t_game *game, t_position *position , t_direction direction)
{
	__u_int		row;
	__u_int		col;

	row = position->row;
	col = position->col;
	while (game->map[row][col] != wall)
	{
		if (direction == up)
			row--;
		if (direction == left)
			col--;
		if (direction == down)
			row++;
		if (direction == right)
			col++;
	}
	if (direction == up)
		row++;
	if (direction == left)
		col++;
	if (direction == down)
		row--;
	if (direction == right)
		col--;
	return (create_pos(row, col));
}

bool	recursive(t_game *game, t_path_checker *checker)
{
	t_position_node	*current_node = checker->tail;
	t_position	*pos_aux;
	t_position_node	*node_aux;
	
	pos_aux = get_position_slide(game, current_node->position, up);
	node_aux = create_node(pos_aux);
	print_pos(pos_aux);
	printf(" N -> ");
	print_pos(pos_aux);
	if (is_node_repeated(checker, node_aux))
	{
		printf(": repeated\n");
		free(pos_aux);
		free(node_aux);
	}
	else
	{
		printf(": new\n");
		add_node(checker, node_aux);
		if (game->map[pos_aux->row][pos_aux->col] == home)
			return (true);
		if (recursive(game, checker))
			return (true);
	}

	pos_aux = get_position_slide(game, current_node->position, left);
	node_aux = create_node(pos_aux);
	print_pos(pos_aux);
	printf(" W -> ");
	print_pos(pos_aux);
	if (is_node_repeated(checker, node_aux))
	{
		printf(": repeated\n");
		free(pos_aux);
		free(node_aux);
	}
	else
	{
		printf(": new\n");
		add_node(checker, node_aux);
		if (game->map[pos_aux->row][pos_aux->col] == home)
			return (true);
		if (recursive(game, checker))
			return (true);
	}

	pos_aux = get_position_slide(game, current_node->position, down);
	node_aux = create_node(pos_aux);
	print_pos(pos_aux);
	printf(" S -> ");
	print_pos(pos_aux);
	if (is_node_repeated(checker, node_aux))
	{
		printf(": repeated\n");
		free(pos_aux);
		free(node_aux);
	}
	else
	{
		printf(": new\n");
		add_node(checker, node_aux);
		if (game->map[pos_aux->row][pos_aux->col] == home)
			return (true);
		if (recursive(game, checker))
			return (true);
	}

	pos_aux = get_position_slide(game, current_node->position, right);
	node_aux = create_node(pos_aux);
	print_pos(pos_aux);
	printf(" E -> ");
	print_pos(pos_aux);
	if (is_node_repeated(checker, node_aux))
	{
		printf(": repeated\n");
		free(pos_aux);
		free(node_aux);
	}
	else
	{
		printf(": new\n");
		add_node(checker, node_aux);
		if (game->map[pos_aux->row][pos_aux->col] == home)
			return (true);
		if (recursive(game, checker))
			return (true);
	}
	return (false);
}

bool	valid_path(t_game *game)
{
	t_path_checker	*checker;

	checker = malloc(sizeof(t_path_checker));
	checker->head = NULL;
	checker->tail = NULL;

	add_node(checker, create_node(create_pos(game->initial_pos->row, game->initial_pos->col)));
	printf("Valid: %i\n", recursive(game, checker));
	print_path(checker);

/* 	add_node(checker, create_pos(game->initial_pos->row, game->initial_pos->col));
	printf("repeated: %i\n", is_node_repeated(checker, checker->tail));
	print_path(checker);
	if (is_node_repeated(checker, checker->tail))
		return (free_checker(checker), false);

	add_node(checker, create_pos(2, 3));
	printf("repeated: %i\n", is_node_repeated(checker, checker->tail));
	print_path(checker);
	if (is_node_repeated(checker, checker->tail))
		return (free_checker(checker), false);

	add_node(checker, create_pos(5, 8));
	printf("repeated: %i\n", is_node_repeated(checker, checker->tail));
	print_path(checker);
	if (is_node_repeated(checker, checker->tail))
		return (free_checker(checker), false);

	add_node(checker, create_pos(13, 21));
	printf("repeated: %i\n", is_node_repeated(checker, checker->tail));
	print_path(checker);
	if (is_node_repeated(checker, checker->tail))
		return (free_checker(checker), false); */

	free_checker(checker);
}
