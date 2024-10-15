/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:28:41 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/15 15:29:09 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static bool	check_path(t_game *game, t_status_node *start);
static bool	check_path_direction(t_game *game,
				t_direction direction, t_status_node *node);
static bool	check_next_cell(t_game *game,
				t_direction direction, t_status_node *node);
static bool	check_exit(t_game *game, t_status_node *node);

void	valid_path(t_game *game)
{
	game->checker = ft_calloc(1, sizeof(t_path_checker));
	if (!game->checker)
		exit_game(game, SL_NO_ALLOCATION);
	add_node(game, create_node(game, game->initial_row, game->initial_col));
	if (!check_path(game, game->checker->head))
		exit_game(game, SL_NO_VALID_PATH);
}

/**
 * @brief Checks whether there's a valid path from the given status.
 * 
 * @param game All game information.
 * @param node The node from which to check.
 * @return Wether there's a valid path.
 */
static bool	check_path(t_game *game, t_status_node *node)
{
	t_direction		direction;

	direction = 1;
	while (direction <= 4)
		if (check_path_direction(game, direction++, copy_node(game, node)))
			return (true);
	return (false);
}

/**
 * @brief Checks whether there's a valid path from the given status,
 * starting from the given direction.
 * 
 * @param game All game information.
 * @param direction The direction to move.
 * @param node The node from which to check.
 * @return Wether there's a valid path.
 */
static bool	check_path_direction(t_game *game,
				t_direction direction, t_status_node *node)
{
	while (get_cell_by(game, node->row, node->col, direction) != WALL)
	{
		if (check_next_cell(game, direction, node))
		{
			free_status(node);
			return (false);
		}
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

/**
 * @brief Moves the position of the node and checks for collectibles and enemies.
 * 
 * @param game All game information.
 * @param direction The direction to move.
 * @param node The node from which to move.
 * @return Wether the next cell is an enemy.
 */
static bool	check_next_cell(t_game *game,
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
	if (game->map->cells[node->row][node->col] == SEAL)
		return (true);
	return (false);
}

/**
 * @brief Checks whether the position of the node is the exit
 * and all collectibles have been collected.
 * 
 * @param game All game information.
 * @param node The node to check.
 * @return Wether the path ends successfully.
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
