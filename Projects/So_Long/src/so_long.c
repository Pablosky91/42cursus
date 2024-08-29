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
	game->map_height = 12;
	game->map_width = 20;
	game->map = ft_calloc(sizeof(t_cell *), game->map_height + 1);
	ft_printf("malloc of %i rows\n", game->map_height);
	for(int i = 0; i < game->map_height; i++)
	{
		game->map[i] = malloc(sizeof(t_cell) * game->map_width);
		ft_printf("malloc of row n%i\n", i);
		for(int j = 0; j < game->map_width; j++)
		{
			if (i == 0 || i == game->map_height - 1 || j == 0 || j == game->map_width - 1)
				game->map[i][j] = wall;
			else if (i == 1 && j == 1)
			{
				game->map[i][j] = player;
				game->initial_pos->row = i;
				game->initial_pos->col = j;
			}
			else if (i == game->map_height - 2 && j == game->map_width - 2)
				game->map[i][j] = home;
			else if (i == game->map_height / 2 && j == game->map_width / 2)
				game->map[i][j] = coin;
			else if (i == 1 && j == game->map_width / 2)
				game->map[i][j] = wall;
			else if (i == game->map_height - 2 && j == game->map_width / 2 - 1)
				game->map[i][j] = wall;
			else
				game->map[i][j] = ice;
		}
	}
}

void	show_map(t_game *game)
{
	for(int i = 0; i < game->map_height; i++)
	{
		for(int j = 0; j < game->map_width; j++)
		{
			if (game->map[i][j] == wall)
				ft_printf("X");
			else if(game->map[i][j] == player)
				ft_printf("P");
			else if(game->map[i][j] == coin)
				ft_printf("C");
			else if(game->map[i][j] == home)
				ft_printf("E");
			else if(game->map[i][j] == ice)
				ft_printf(" ");
			if (j == game->map_width - 1)
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
	(*game)->mlx = NULL;//mlx_init((*game)->map_width * IMG_SIZE, (*game)->map_height * IMG_SIZE, "So Long", true);
	(*game)->player = malloc(sizeof(t_player));
	(*game)->player->player_movement = still;
	(*game)->initial_pos = malloc(sizeof(t_position));
}


int	main(int argc, char **argv)
{
	t_game	*game;

	init(&game);

	//create_map(game);
	read_map(game, argv[1]);
	ft_printf("rows: %i cols: %i\n", game->map_height, game->map_width);
	show_map(game);

	valid_path(game);

	
	


	print_map(game);
	mlx_loop_hook(game->mlx, &my_loop_hook, game);
	mlx_key_hook(game->mlx, &my_key_hook, game);
	mlx_loop(game->mlx);
	
	free_game(game);
	return (0);
}
