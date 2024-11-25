/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:26:09 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/11/23 22:48:26 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	free_checker(t_path_checker *checker);

void	free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->fishes)
		ft_free_double_pointer((void **) game->fishes);
	if (game->seals)
		ft_free_double_pointer((void **) game->seals);
	if (game->map && game->map->cells)
		ft_free_double_pointer((void **) game->map->cells);
	free(game->map->name);
	free(game->map);
	free(game->penguin);
	free(game->home);
	free(game->counter);
	free(game->ending);
	if (game->checker)
		free_checker(game->checker);
	free(game->cursor);
	if (game->mlx)
		mlx_terminate(game->mlx);
	free(game);
}

/**
 * @brief Frees all nodes in a checker and the checker itself.
 * 
 * @param checker The path_checker to free.
 */
static void	free_checker(t_path_checker *checker)
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
