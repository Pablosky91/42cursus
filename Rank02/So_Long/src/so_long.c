/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:50:28 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/11/01 18:11:18 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init(t_game **game, int argc);

int	main(int argc, char **argv)
{
	t_game	*game;

	init(&game, argc);
	read_map(game, argv[1]);
	init_mlx(game);
	mlx_key_hook(game->mlx, &my_key_hook, game);
	mlx_loop_hook(game->mlx, &my_loop_hook, game);
	mlx_loop(game->mlx);
	exit_game(game, SL_OK);
	return (0);
}

/**
 * @brief Initialises and allocates the game structure.
 * 
 * @param game The game instance to be initialised.
 * @param argc The argument count passed to the program.
 */
static void	init(t_game **game, int argc)
{
	if (argc < 2)
		exit_game(NULL, SL_NO_ARGUMENT);
	*game = ft_calloc(1, sizeof(t_game));
	if (!*game)
		exit_game(NULL, SL_NO_ALLOCATION);
	(*game)->map = ft_calloc(1, sizeof(t_map));
	if (!((*game)->map))
		exit_game(*game, SL_NO_ALLOCATION);
}
