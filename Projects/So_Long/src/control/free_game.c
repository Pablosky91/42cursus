/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:41:01 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/18 16:13:24 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_checker(t_path_checker *checker);

void	free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->fishes)
		ft_free_double_pointer((void **) game->fishes);
	if (game->map && game->map->cells)
		ft_free_double_pointer((void **) game->map->cells);
	free(game->map);
	free(game->penguin);
	free(game->home);
	if (game->checker)
		free_checker(game->checker);
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
