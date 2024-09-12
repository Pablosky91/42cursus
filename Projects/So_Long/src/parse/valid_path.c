/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:45:12 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/09/12 22:20:57 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_status(t_status_node *status)
{
	status->next = NULL;
	//free(status->position);
	free(status->fishes);
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

/*
void	print_path(t_game *game, t_path_checker	*checker)
{
	t_status_node	*node;
	int				iter;

	ft_printf("\n");
	node = checker->head;
	while (node != 0)
	{
		iter = 0;
		ft_printf("{%i:%i}\t[", node->position->row, node->position->col);
		ft_printf("%i", node->fishes[iter]);
		iter++;
		while (iter < game->quantity_fishes)
		{
			ft_printf(" %i", node->fishes[iter]);
			iter++;
		}
		ft_printf("]\n");
		node = node->next;
	}
	ft_printf("\n");
}
*/

int	get_id_fish(t_game *game, int row, int col/* t_position position */)
{
	int	iter;

	iter = 0;
	while (game->fishes[iter])
	{
		if (game->fishes[iter]->/* position-> */row == /* position. */row && game->fishes[iter]->/* position-> */col == /* position. */col)
			return (game->fishes[iter]->id);
		iter++;
	}
	return (-1);
}

bool	is_same_status(t_game *game, t_status_node *status_1, t_status_node *status_2)
{
	int	iter;

	iter = 0;
	if (status_1->/* position-> */row != status_2->/* position-> */row)
		return (false);
	if (status_1->/* position-> */col != status_2->/* position-> */col)
		return (false);
	while (iter < game->quantity_fishes)
	{
		if (status_1->fishes[iter] != status_2->fishes[iter])
			return (false);
		iter++;
	}
	return (true);
}

bool	is_node_repeated(t_game *game, t_path_checker *checker, t_status_node *node)
{
	t_status_node	*iter;

	iter = checker->head;
	while (iter)
	{
		if (is_same_status(game, iter, node))
			return (true);
		iter = iter->next;
	}
	return (false);
}

/*
t_position	*create_pos(int row, int col)
{
	t_position	*position;

	position = malloc(sizeof(t_position));
	position->row = row;
	position->col = col;
	return (position);
}
*/

t_status_node	*create_node(t_game *game, int row, int col/* t_position *position */)
{
	t_status_node	*node;

	node = malloc(sizeof(t_status_node));
	//node->position = position;
	node->row = row;
	node->col = col;
	node->fishes = ft_calloc(game->quantity_fishes, sizeof(bool));
	node->next = NULL;
	return (node);
}

t_status_node	*copy_node(t_game *game, t_status_node *node)
{
	t_status_node	*copy;
	int				iter;

	iter = 0;
	copy = malloc(sizeof(t_status_node));
	//copy->position = create_pos(node->position->row, node->position->col);
	copy->row = node->row;
	copy->col = node->col;
	copy->fishes = ft_calloc(game->quantity_fishes, sizeof(bool));
	while (iter < game->quantity_fishes)
	{
		copy->fishes[iter] = node->fishes[iter];
		iter++;
	}
	copy->next = NULL;
	return (copy);
}

void	add_node(t_path_checker *checker, t_status_node	*node)
{
	if (!checker->head)
		checker->head = node;
	if (checker->tail)
		checker->tail->next = node;
	checker->tail = node;
}

t_cell	get_cell_by(t_game *game, int row, int col/* t_position	position */, t_direction direction)
{
	if (direction == NORTH)
		/* position. */row--;
	if (direction == WEST)
		/* position. */col--;
	if (direction == SOUTH)
		/* position. */row++;
	if (direction == EAST)
		/* position. */col++;
	return (game->map->cells[/* position. */row][/* position. */col]);
}

bool	recursive(t_game *game, t_path_checker *checker)
{
	int				i;
	bool			all_collected;
	t_direction		direction;
	t_status_node	*new_node;
	t_status_node	*start; //might be argument

	direction = 1;
	start = checker->tail;
	while (direction <= 4)
	{

		new_node = copy_node(game, start);
		while (get_cell_by(game, new_node->row, new_node->col/* *new_node->position */, direction) != WALL)
		{
			if (direction == NORTH)
				new_node->/* position-> */row--;
			else if (direction == WEST)
				new_node->/* position-> */col--;
			else if (direction == SOUTH)
				new_node->/* position-> */row++;
			else if (direction == EAST)
				new_node->/* position-> */col++;
			//check here for fishes, exit and enemies
			//exit
			if (game->map->cells[new_node->/* position-> */row][new_node->/* position-> */col] == HOME)
			{
				all_collected = true;
				i = 0;
				while (i < game->quantity_fishes)
				{
					if (!new_node->fishes[i])
						all_collected = false;
					i++;
				}
				if (all_collected)
				{
					free_status(new_node);
					return (true);
				}
			}
			//fish
			if (game->map->cells[new_node->/* position-> */row][new_node->/* position-> */col] == FISH)
				new_node->fishes[get_id_fish(game, new_node->row, new_node->col/* *(new_node->position) */)] = true;
		}
		if (!is_node_repeated(game, checker, new_node))
		{
			add_node(checker, new_node);
			if (recursive(game, checker))
				return (true);
		}
		else
			free_status(new_node);
		direction++;
	}
	return (false);
}

//TODO alloc prot
void	valid_path(t_game *game)
{
	t_path_checker	*checker;
	bool			valid;

	checker = malloc(sizeof(t_path_checker));
	checker->head = NULL;
	checker->tail = NULL;
	//add_node(checker, create_node(game, create_pos(game->initial_pos->row, game->initial_pos->col)));
	add_node(checker, create_node(game, game->initial_row, game->initial_col));
	valid = recursive(game, checker);
	free_checker(checker);
	if (!valid)
		exit_game(game, NO_VALID_PATH);
}
