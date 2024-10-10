/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:41:01 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/10 12:30:19 by pdel-olm         ###   ########.fr       */
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
