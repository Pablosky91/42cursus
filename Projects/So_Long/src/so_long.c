/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:50:28 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/09/13 21:54:23 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init(t_game **game);

int	main(int argc, char **argv)
{
	t_game	*game;

	game = NULL;
	if (argc < 2)
		exit_game(game, NO_ARGUMENT);
	init(&game);
	read_map(game, argv[1]);
	init_mlx(game);
	mlx_loop_hook(game->mlx, &my_loop_hook, game);
	mlx_key_hook(game->mlx, &my_key_hook, game);
	// mlx_mouse_hook(game->mlx, &my_mouse_hook, game);
	// mlx_cursor_hook(game->mlx, &my_cursor_hook, game);
	// mlx_scroll_hook(game->mlx, &my_scroll_hook, game);
	mlx_loop(game->mlx);
	exit_game(game, OK);
	return (0);
}

static void	init(t_game **game)
{
	*game = ft_calloc(1, sizeof(t_game));
	if (!*game)
		exit_game(*game, NO_ALLOCATION);
	(*game)->map = ft_calloc(1, sizeof(t_map));
	if (!((*game)->map))
		exit_game(*game, NO_ALLOCATION);
	(*game)->penguin = ft_calloc(1, sizeof(t_penguin));
	if (!((*game)->penguin))
		exit_game(*game, NO_ALLOCATION);
	(*game)->home = ft_calloc(1, sizeof(t_home));
	if (!((*game)->home))
		exit_game(*game, NO_ALLOCATION);
	(*game)->initial_row = -1;
	(*game)->initial_col = -1;
}
