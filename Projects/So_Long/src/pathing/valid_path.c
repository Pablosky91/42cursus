/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:45:12 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/07 21:26:22 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	check_path(t_game *game, t_status_node *start);
static bool	check_path_direction(t_game *game,
				t_direction direction, t_status_node *node);
static void	check_next_cell(t_game *game,
				t_direction direction, t_status_node *node);
static bool	check_exit(t_game *game, t_status_node *node);

void	valid_path(t_game *game)
{
	game->checker = ft_calloc(1, sizeof(t_path_checker));
	if (!game->checker)
		exit_game(game, SL_NO_ALLOCATION);
	add_node(game, create_node(game, game->initial_row, game->initial_col));
	if (!check_path(game, game->checker->tail))
		exit_game(game, SL_NO_VALID_PATH);
}

/*
Checks whether there's a valid path from the given status.
*/
static bool	check_path(t_game *game, t_status_node *start)
{
	t_direction		direction;

	direction = 1;
	while (direction <= 4)
		if (check_path_direction(game, direction++, copy_node(game, start)))
			return (true);
	return (false);
}

/*
Checks whether there's a valid path from the given status,
starting from the given direction.
*/
static bool	check_path_direction(t_game *game,
				t_direction direction, t_status_node *node)
{
	while (get_cell_by(game, node->row, node->col, direction)
		!= WALL)
	{
		check_next_cell(game, direction, node);
		if (check_exit(game, node))
			return (true);
	}
	if (!is_node_repeated(game, node))
	{
		add_node(game, node);
		if (check_path(game, game->checker->tail))
			return (true);
	}
	else
		free_status(node);
	return (false);
}

/*
Moves the position of the node and checks for collectibles.
*/
static void	check_next_cell(t_game *game,
				t_direction direction, t_status_node *node)
{
	if (direction == NORTH)
		node->row--;
	else if (direction == WEST)
		node->col--;
	else if (direction == SOUTH)
		node->row++;
	else if (direction == EAST)
		node->col++;
	if (game->map->cells[node->row][node->col] == FISH)
		node->fishes[get_id_fish(game, node->row, node->col)] = true;
}

/*
Checks whether the actual position is the exit
and all collectibles are collected.
*/
static bool	check_exit(t_game *game, t_status_node *node)
{
	int		fish_iter;

	if (game->map->cells[node->row][node->col] != HOME)
		return (false);
	fish_iter = 0;
	while (fish_iter < game->quantity_fishes)
		if (!node->fishes[fish_iter++])
			return (false);
	free_status(node);
	return (true);
}
