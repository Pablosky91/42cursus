/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:45:12 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/08/27 19:18:39 by pdel-olm         ###   ########.fr       */
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

/*bool	recursive(t_game *game, t_path_checker *checker)
{
	t_position_node	*current_node = checker->tail;
	t_position	*pos_aux;
	t_position_node	*node_aux;
	
	pos_aux = get_position_slide(game, current_node->position, up);
	node_aux = create_node(pos_aux);
	print_pos(current_node->position);
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
	print_pos(current_node->position);
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
	print_pos(current_node->position);
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
	print_pos(current_node->position);
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
	return (game->map[position.row][position.col]);
}

bool recursive(t_game *game, t_path_checker *checker)
{
	t_direction	direction;
	t_position_node	*start;
	t_position_node	*new_node;

	direction = 1;
	start = checker->tail;
	//new_node = *start;
	while(direction <= 4)
	{
		//printf("start %i, %i\n",start->position->row, start->position->col);
		new_node = create_node(create_pos(start->position->row, start->position->col));
		/* new_node.position->row = start->position->row;
		new_node.position->col = start->position->col;
		new_node.next = NULL; */
		printf("pos: ");
		print_pos(new_node->position);
		printf(" dir: %i\n", direction);
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
			/* printf("going %i to ", direction);
			print_pos(new_node->position);
			printf("\n"); */
			//check here for coins, exit and enemies
			if (game->map[new_node->position->row][new_node->position->col] == home)
				return (true);
		}
		
		if (!is_node_repeated(checker, new_node))
		{
			printf("adding ");
			print_pos(new_node->position);
			printf("\n\n");
			add_node(checker, new_node);
			if (recursive(game, checker))
			{
				/* free(new_node->position);
				free(new_node); */
				return (true);
			}
		}
		
		direction++;
	}
	printf("closing ");
	print_pos(start->position);
	printf("\n\n");
	/* free(new_node->position);
	free(new_node); */
	return (false);
}

bool	valid_path(t_game *game)
{
	t_path_checker	*checker;

	checker = malloc(sizeof(t_path_checker));
	checker->head = NULL;
	checker->tail = NULL;

	printf("ini: %i %i\n", game->initial_pos->row, game->initial_pos->col);
	add_node(checker, create_node(create_pos(game->initial_pos->row, game->initial_pos->col)));
	printf("Valid: %i\n", recursive(game, checker));
	print_path(checker);

	//free_checker(checker);
}
