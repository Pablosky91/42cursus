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

static void init(t_game **game);

void	create_map(t_game *game)
{
	game->map->height = 7;
	game->map->width = 9;
	game->map->cells = ft_calloc(sizeof(t_cell *), game->map->height + 1);
	game->quantity_fishes = 2;
	game->fishes = ft_calloc(game->quantity_fishes + 1, sizeof(t_fish *));
	for(int i = 0; i < game->map->height; i++)
	{
		game->map->cells[i] = malloc(sizeof(t_cell) * game->map->width);
		for(int j = 0; j < game->map->width; j++)
		{
			if (i == 0 || i == game->map->height - 1 || j == 0 || j == game->map->width - 1)
				game->map->cells[i][j] = wall;
			else if (i == 1 && j == 1)
			{
				game->map->cells[i][j] = penguin;
				game->initial_pos->row = i;
				game->initial_pos->col = j;
			}
			else if (i == game->map->height - 3 && j == game->map->width - 2)
				game->map->cells[i][j] = home;
			else if (i == 5 && j == 7)
			{
				game->map->cells[i][j] = fish;
				game->fishes[0] = malloc(sizeof(t_fish));
				game->fishes[0]->collected = false;
				game->fishes[0]->id = 1;
				game->fishes[0]->position = malloc(sizeof(t_position));
				game->fishes[0]->position->row = i;
				game->fishes[0]->position->col = j;
			}
			else if (i == game->map->height / 2 && j == game->map->width / 2)
			{
				game->map->cells[i][j] = fish;
				game->fishes[1] = malloc(sizeof(t_fish));
				game->fishes[1]->collected = false;
				game->fishes[1]->id = 2;
				game->fishes[1]->position = malloc(sizeof(t_position));
				game->fishes[1]->position->row = i;
				game->fishes[1]->position->col = j;
			}
			else if (i == 1 && j == game->map->width / 2)
				game->map->cells[i][j] = wall;
			else if (i == game->map->height - 2 && j == game->map->width / 2 - 1)
				game->map->cells[i][j] = wall;
			else
				game->map->cells[i][j] = ice;
		}
	}
}

void	show_map(t_game *game)
{
	for(int i = 0; i < game->map->height; i++)
	{
		for(int j = 0; j < game->map->width; j++)
		{
			if (game->map->cells[i][j] == wall)
				ft_printf("X");
			else if(game->map->cells[i][j] == penguin)
				ft_printf("P");
			else if(game->map->cells[i][j] == fish)
				ft_printf("C");
			else if(game->map->cells[i][j] == home)
				ft_printf("E");
			else if(game->map->cells[i][j] == ice)
				ft_printf(" ");
			if (j == game->map->width - 1)
				ft_printf("\n");
		}
	}
	ft_printf("\n");
}

static void	init(t_game **game)
{
	__u_int	i;

	i = 0;
	*game = malloc(sizeof(t_game));
	(*game)->mlx = NULL;
	(*game)->map = malloc(sizeof(t_map));
	(*game)->penguin = malloc(sizeof(t_penguin));
	(*game)->penguin->facing = still;
	(*game)->fishes = NULL;
	(*game)->quantity_fishes = 0;
	(*game)->initial_pos = malloc(sizeof(t_position));
}


int	main(int argc, char **argv)
{
	t_game	*game;

	init(&game);

	//create_map(game);
	read_map(game, argv[1]);
	show_map(game);

	for (int i = 0; game->fishes[i]; i++)
		ft_printf("Fish %i: {%i, %i}\n", game->fishes[i]->id, game->fishes[i]->position->row, game->fishes[i]->position->col);
	ft_printf("\n");

	valid_path(game);



	print_map(game);
	mlx_loop_hook(game->mlx, &my_loop_hook, game);
	mlx_key_hook(game->mlx, &my_key_hook, game);
	mlx_loop(game->mlx);
	
	free_game(game);
	return (0);
}