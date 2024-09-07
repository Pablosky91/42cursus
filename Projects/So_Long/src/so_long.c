/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 8:59:27 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/08/27 12:39:12 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init(t_game **game);

void	create_map(t_game *game)
{
	game->map->height = 7;
	game->map->width = 9;
	game->map->cells = ft_calloc(sizeof(t_cell *), game->map->height + 1);
	game->quantity_fishes = 2;
	game->fishes = ft_calloc(game->quantity_fishes + 1, sizeof(t_fish *));
	for (int i = 0; i < game->map->height; i++)
	{
		game->map->cells[i] = malloc(sizeof(t_cell) * game->map->width);
		for (int j = 0; j < game->map->width; j++)
		{
			if (i == 0 || i == game->map->height - 1 || j == 0 || j == game->map->width - 1)
				game->map->cells[i][j] = WALL;
			else if (i == 1 && j == 1)
			{
				game->map->cells[i][j] = PENGUIN;
				game->initial_pos->row = i;
				game->initial_pos->col = j;
			}
			else if (i == game->map->height - 3 && j == game->map->width - 2)
				game->map->cells[i][j] = HOME;
			else if (i == 5 && j == 7)
			{
				game->map->cells[i][j] = FISH;
				game->fishes[0] = malloc(sizeof(t_fish));
				game->fishes[0]->collected = false;
				game->fishes[0]->id = 1;
				game->fishes[0]->position = malloc(sizeof(t_position));
				game->fishes[0]->position->row = i;
				game->fishes[0]->position->col = j;
			}
			else if (i == game->map->height / 2 && j == game->map->width / 2)
			{
				game->map->cells[i][j] = FISH;
				game->fishes[1] = malloc(sizeof(t_fish));
				game->fishes[1]->collected = false;
				game->fishes[1]->id = 2;
				game->fishes[1]->position = malloc(sizeof(t_position));
				game->fishes[1]->position->row = i;
				game->fishes[1]->position->col = j;
			}
			else if (i == 1 && j == game->map->width / 2)
				game->map->cells[i][j] = WALL;
			else if (i == game->map->height - 2 && j == game->map->width / 2 - 1)
				game->map->cells[i][j] = WALL;
			else
				game->map->cells[i][j] = ICE;
		}
	}
}

void	show_map(t_game *game)
{
	for (int i = 0; i < game->map->height; i++)
	{
		for (int j = 0; j < game->map->width; j++)
		{
			if (game->map->cells[i][j] == WALL)
				ft_printf("X");
			else if (game->map->cells[i][j] == PENGUIN)
				ft_printf("P");
			else if (game->map->cells[i][j] == FISH)
				ft_printf("C");
			else if (game->map->cells[i][j] == HOME)
				ft_printf("E");
			else if (game->map->cells[i][j] == ICE)
				ft_printf(" ");
			if (j == game->map->width - 1)
				ft_printf("\n");
		}
	}
	ft_printf("\n");
}

static void	init(t_game **game)
{
	*game = malloc(sizeof(t_game));
	(*game)->mlx = NULL;
	(*game)->map = malloc(sizeof(t_map));
	(*game)->map->cells = NULL;
	(*game)->map->width = 0;
	(*game)->map->height = 0;
	(*game)->penguin = malloc(sizeof(t_penguin));
	(*game)->penguin->facing = STILL;
	(*game)->fishes = NULL;
	(*game)->home = malloc(sizeof(t_home));
	(*game)->home->exists = false;
	(*game)->quantity_fishes = 0;
	(*game)->collected_fishes = 0;
	(*game)->initial_pos = NULL;
	(*game)->moves = 0;
}

int	main(int argc, char **argv)
{
	/* int32_t	width = 5, height = 7;
	mlx_get_monitor_size(0, &width, &height);
	ft_printf("w: %i, h: %i\n", width, height); */
	t_game	*game;

	if (argc < 2)
		exit_game(game, NO_ARGUMENT);
	init(&game);
	read_map(game, argv[1]);
	valid_path(game);
	print_map(game);
	mlx_loop_hook(game->mlx, &my_loop_hook, game);
	mlx_key_hook(game->mlx, &my_key_hook, game);
	mlx_mouse_hook(game->mlx, &my_mouse_hook, game);
	mlx_cursor_hook(game->mlx, &my_cursor_hook, game);
	mlx_scroll_hook(game->mlx, &my_scroll_hook, game);
	mlx_loop(game->mlx);
	free_game(game);
	return (0);
}
