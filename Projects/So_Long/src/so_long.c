/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:59:27 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/08/22 23:37:57 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static const int IMG_SIZE = 128;

static void	my_hook(void* param)
{
	t_game *game = param;

	if (game->player_movement == up)
		game->player->instances[0].y -=16;
	if (game->player_movement == left)
		game->player->instances[0].x -=16;
	if (game->player_movement == down)
		game->player->instances[0].y +=16;
	if (game->player_movement == right)
		game->player->instances[0].x +=16;
	}

static void	my_key_hook(mlx_key_data_t keydata, void* param)
{
	t_game *game = param;

	if (keydata.action != MLX_PRESS)
		return ;
	if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		game->player_movement = up;
	if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		game->player_movement = left;
	if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		game->player_movement = down;
	if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		game->player_movement = right;
	if (keydata.key == MLX_KEY_ESCAPE)
		game->player_movement = still;
}

void	create_map(t_game *game)
{
	for(int i = 0; i < game->map_height; i++)
	{
		for(int j = 0; j < game->map_width; j++)
		{
			if (i == 0 || i == game->map_height - 1 || j == 0 || j == game->map_width - 1)
				game->map[i][j] = wall;
			else if(i == 1 && j == 1)
				game->map[i][j] = player;
			else
				game->map[i][j] = floor;
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
			else if(game->map[i][j] == floor)
				ft_printf(" ");
			if (j == game->map_width - 1)
				ft_printf("\n");
		}
	}
	ft_printf("\n");
}

static void init(t_game **game)
{
	__u_int	i;

	i = 0;
	*game = malloc(sizeof(t_game));
	(*game)->map_width = 12;
	(*game)->map_height = 8;
	(*game)->mlx = mlx_init((*game)->map_width * IMG_SIZE, (*game)->map_height * IMG_SIZE, "So Long", true);
	(*game)->map = malloc(sizeof(t_cell *) * (*game)->map_height);
	while (i < (*game)->map_height)
		(*game)->map[i++] = malloc(sizeof(t_cell *) * (*game)->map_width);

}

static void	free_game(t_game *game)
{
	__u_int	i;

	i = 0;
	while (i < game->map_height)
		free(game->map[i++]);
	free(game->map);
	free(game);
}

static void	ice(t_game *game)
{
	mlx_texture_t *texture = mlx_load_png("textures/ice.png");
	mlx_image_t *img = mlx_new_image(game->mlx, texture->width, texture->height);
	img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	mlx_resize_image(img, IMG_SIZE, IMG_SIZE);
	for(int i = 0; i < game->map_height; i++)
	{
		for(int j = 0; j < game->map_width; j++)
		{
			mlx_image_to_window(game->mlx, img, IMG_SIZE * j, IMG_SIZE * i);
			img->instances[i * game->map_width + j].z = 1;
		}
	}
}

static void	penguin(t_game *game)
{
	mlx_texture_t *texture = mlx_load_png("textures/penguin.png");
	game->player = mlx_new_image(game->mlx, texture->width, texture->height);
	game->player = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	mlx_resize_image(game->player, IMG_SIZE, IMG_SIZE);
	mlx_image_to_window(game->mlx, game->player, IMG_SIZE, IMG_SIZE);
	game->player->instances[0].z = 2;
}

int	main(void)
{
	t_game	*game;

	init(&game);
	create_map(game);
	show_map(game);
	ice(game);
	penguin(game);












	mlx_loop_hook(game->mlx, my_hook, game);
	mlx_key_hook(game->mlx, &my_key_hook, game);
	mlx_loop(game->mlx);
	free_game(game);
	return (0);
}
