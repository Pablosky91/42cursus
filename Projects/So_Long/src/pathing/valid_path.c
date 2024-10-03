/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:45:12 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/03 11:18:01 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	recursive(t_game *game, t_status_node *start)
{
	int				i;
	bool			all_collected;
	t_direction		direction;
	t_status_node	*new_node;

	direction = 1;
	while (direction <= 4)
	{
		new_node = copy_node(game, start);
		while (get_cell_by(game, new_node->row, new_node->col, direction) != WALL)
		{
			if (direction == NORTH)
				new_node->row--;
			else if (direction == WEST)
				new_node->col--;
			else if (direction == SOUTH)
				new_node->row++;
			else if (direction == EAST)
				new_node->col++;
			//check here for fishes, exit and enemies
			//exit
			if (game->map->cells[new_node->row][new_node->col] == HOME)
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
			if (game->map->cells[new_node->row][new_node->col] == FISH)
				new_node->fishes[get_id_fish(game, new_node->row, new_node->col)] = true;
		}
		if (!is_node_repeated(game, new_node))
		{
			add_node(game, new_node);
			if (recursive(game, game->checker->tail))
				return (true);
		}
		else
			free_status(new_node);
		direction++;
	}
	return (false);
}

void	valid_path(t_game *game)
{
	bool			valid;

	game->checker = ft_calloc(1, sizeof(t_path_checker));
	if (!game->checker)
		exit_game(game, NO_ALLOCATION);
	add_node(game, create_node(game, game->initial_row, game->initial_col));
	valid = recursive(game, game->checker->tail);
	if (!valid)
		exit_game(game, NO_VALID_PATH);
}
