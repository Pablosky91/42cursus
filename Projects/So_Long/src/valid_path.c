/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:45:12 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/08/29 16:30:00 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_status(t_status_node *status)
{
	status->next = NULL;
	free(status->position);
	free(status);
}

void	free_checker(t_path_checker *checker)
{
	t_status_node	*iter;
	t_status_node	*next;
	
	iter = checker->head;
	while (iter)
	{
		next = iter->next;
		free_status(iter);
		iter = next;
	}
	free(checker);
}

void	print_pos(t_position *position)
{
	ft_printf("{%i, %i}", position->row, position->col);
}

void	print_path(t_path_checker	*checker)
{
	t_status_node	*node;
	
	ft_printf("\n");
	node = checker->head;
	while (node != 0)
	{
		print_pos(node->position);
		ft_printf("\n");
		node = node->next;
	}
	printf("\n");
}

bool	is_same_status(t_status_node *status_1, t_status_node *status_2)
{
	if (status_1->position->row != status_2->position->row)
		return (false);
	if (status_1->position->col != status_2->position->col)
		return (false);
	return (true);
}

bool	is_node_repeated(t_path_checker *checker, t_status_node *node)
{
	t_status_node	*iter;

	iter = checker->head;
	while (iter)
	{
		if (is_same_status(iter, node))
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

t_status_node	*create_node(t_position *position)
{
	t_status_node	*node;

	node = malloc(sizeof(t_status_node));
	node->position = position;
	node->next = NULL;
}

void	add_node(t_path_checker *checker, t_status_node	*node)
{
	if (!checker->head)
		checker->head = node;
	if (checker->tail)
		checker->tail->next = node;
	checker->tail = node;
}

/* t_position	*get_position_slide(t_game *game, t_position *position , t_direction direction)
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
} */

t_cell	get_cell_by(t_game *game, t_position	position, t_direction direction)
{
	if (direction == up)
		position.row--;
	if (direction == left)
		position.col--;
	if (direction == down)
		position.row++;
	if (direction == right)
		position.col++;
	return (game->map->cells[position.row][position.col]);
}

bool recursive(t_game *game, t_path_checker *checker)
{
	t_direction		direction;
	t_status_node	*start; //might be argument
	t_status_node	*new_node;

	direction = 1;
	start = checker->tail;
	while(direction <= 4)
	{

		new_node = create_node(create_pos(start->position->row, start->position->col));
		while(get_cell_by(game, *new_node->position, direction) != wall)
		{
			if (direction == up)
				new_node->position->row--;
			else if (direction == left)
				new_node->position->col--;
			else if (direction == down)
				new_node->position->row++;
			else if (direction == right)
				new_node->position->col++;
			//check here for fishes, exit and enemies
			if (game->map->cells[new_node->position->row][new_node->position->col] == home)
				return (true);
		}
		
		if (!is_node_repeated(checker, new_node))
		{
			add_node(checker, new_node);
			if (recursive(game, checker))
				return (true);
		}
		
		direction++;
	}
	return (false);
}

void	add_alloc(t_path_checker *checker, t_status_node *node)
{
	/* t_status_node *new_node = malloc(sizeof(t_status_node));
	new_node->position = malloc(sizeof(t_position));
	
	*(new_node->position) = *(node->position);
	new_node->next = 0; */
//	new_node->position = malloc(sizeof(t_position));
//	new_node->position = node.position;
	if (!checker->head)
		checker->head = /* new_ */node;
	if (checker->tail)
		checker->tail->next = /* new_ */node;
	checker->tail = /* new_ */node;
}

bool	valid_path(t_game *game)
{
	t_path_checker	*checker;
	checker = malloc(sizeof(t_path_checker));
	checker->head = NULL;
	checker->tail = NULL;

/* 	checker->head = malloc(sizeof(t_status_node));
	checker->head->position = malloc(sizeof(t_position));

	*(checker->head->position) = *(game->initial_pos);
	//checker->head->position->row = game->initial_pos->row;
	//checker->head->position->col = game->initial_pos->col;
	
	checker->head->next = NULL;
	checker->tail = checker->head;

	ft_printf("game %i %i pos %i %i\n", game->initial_pos->row, game->initial_pos->col, checker->head->position->row, checker->head->position->col);

	checker->head->position->row = 0;
	checker->head->position->col = 5;

	ft_printf("game %i %i pos %i %i\n", game->initial_pos->row, game->initial_pos->col, checker->head->position->row, checker->head->position->col);

	game->initial_pos->row = 2;
	game->initial_pos->col = 2;

	ft_printf("game %i %i pos %i %i\n", game->initial_pos->row, game->initial_pos->col, checker->head->position->row, checker->head->position->col);

///////////////////
	
	t_status_node *node = malloc(sizeof(t_status_node));
	node->next = 0;
	node->position = malloc(sizeof(t_position));
	
	node->position->row = 2;
	node->position->col = 2;

	add_alloc(checker, node);
	print_path(checker);

	node->position->row = 3;
	node->position->col = 4; */





	/* checker->head = malloc(sizeof(t_status_node));
	checker->head->position = malloc(sizeof(t_position));
	*(checker->head->position) = *(game->initial_pos); */
	//same as
	//add_node(checker, create_node(create_pos(game->initial_pos->row, game->initial_pos->col)));

	//printf("Valid: %i\n", recursive(game, checker));


	
	print_path(checker);
	free_checker(checker);
}
