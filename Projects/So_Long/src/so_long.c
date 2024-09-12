/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:50:28 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/09/12 23:29:45 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init(t_game **game);

/* void my_resize_hook(int32_t width, int32_t height, void* param)
{
	t_game *game = param;
	ft_printf("window width: %i, height: %i\n", game->mlx->width, game->mlx->height);
	char *c = ft_strjoin(ft_itoa(game->mlx->width), ft_itoa(game->mlx->height));
	mlx_put_string(game->mlx, c, 100, 100);

} */

int	main(int argc, char **argv)
{
	t_game	*game;

	game = NULL;
	if (argc < 2)
		exit_game(game, NO_ARGUMENT);
	init(&game);
	read_map(game, argv[1]);
	// mlx_mouse_hook(game->mlx, &my_mouse_hook, game);
	// mlx_cursor_hook(game->mlx, &my_cursor_hook, game);
	// mlx_scroll_hook(game->mlx, &my_scroll_hook, game);
	print_map(game);
	mlx_loop_hook(game->mlx, &my_loop_hook, game);
	mlx_key_hook(game->mlx, &my_key_hook, game);
	//mlx_resize_hook(game->mlx, &my_resize_hook, game);
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
	(*game)->img_size = 100;
	(*game)->speed = 10;
}
