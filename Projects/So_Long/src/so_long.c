/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 8:59:27 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/08/26 15:27:27 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static const int IMG_SIZE = 128;
static const int SPEED = 12;

static void	my_hook(void* param)
{
	t_game *game = param;

	if (game->player->player_movement == up)
	{
		game->player->still->instances[0].y -= SPEED;
		game->player->up->instances[0].y -= SPEED;
		game->player->left->instances[0].y -= SPEED;
		game->player->down->instances[0].y -= SPEED;
		game->player->right->instances[0].y -= SPEED;
	}
	if (game->player->player_movement == left)
	{
		game->player->still->instances[0].x -= SPEED;
		game->player->up->instances[0].x -= SPEED;
		game->player->left->instances[0].x -= SPEED;
		game->player->down->instances[0].x -= SPEED;
		game->player->right->instances[0].x -= SPEED;
	}
	if (game->player->player_movement == down)
	{
		game->player->still->instances[0].y += SPEED;
		game->player->up->instances[0].y += SPEED;
		game->player->left->instances[0].y += SPEED;
		game->player->down->instances[0].y += SPEED;
		game->player->right->instances[0].y += SPEED;
	}
	if (game->player->player_movement == right)
	{
		game->player->still->instances[0].x += SPEED;
		game->player->up->instances[0].x += SPEED;
		game->player->left->instances[0].x += SPEED;
		game->player->down->instances[0].x += SPEED;
		game->player->right->instances[0].x += SPEED;
	}
}

void move_player(t_game *game, t_direction direction)
{
	game->player->still->enabled = false;
	game->player->up->enabled = false;
	game->player->left->enabled = false;
	game->player->down->enabled = false;
	game->player->right->enabled = false;
	if (direction == still)
		game->player->still->enabled = true;
	if (direction == up)
		game->player->up->enabled = true;
	if (direction == left)
		game->player->left->enabled = true;
	if (direction == down)
		game->player->down->enabled = true;
	if (direction == right)
		game->player->right->enabled = true;
	game->player->player_movement = direction;
}

static void	my_key_hook(mlx_key_data_t keydata, void* param)
{
	t_game *game = param;

	if (keydata.action != MLX_PRESS)
		return ;
	if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		move_player(game, up);
	if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		move_player(game, left);
	if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		move_player(game, down);
	if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		move_player(game, right);
	if (keydata.key == MLX_KEY_ESCAPE)
		move_player(game, still);
}

void	create_map(t_game *game)
{
	for(int i = 0; i < game->map_height; i++)
	{
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
			else if(game->map[i][j] == coin)
				ft_printf("C");
			else if(game->map[i][j] == home)
				ft_printf("E");
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
	(*game)->player = malloc(sizeof(t_player));
	(*game)->initial_pos = malloc(sizeof(t_position));
}

static void	free_game(t_game *game)
{
	__u_int	i;

	i = 0;
	while (i < game->map_height)
		free(game->map[i++]);
	free(game->map);
	free(game->player);
	free(game->initial_pos);
	free(game);
}

void create_image(mlx_t *mlx, mlx_image_t **img, char *path, __u_int	row, __u_int	col)
{
	mlx_texture_t *texture = mlx_load_png(path);
	*img = mlx_new_image(mlx, texture->width, texture->height);
	*img = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	mlx_resize_image(*img, IMG_SIZE, IMG_SIZE);
	mlx_image_to_window(mlx, *img, col * IMG_SIZE, row * IMG_SIZE);
}

void	print_map(t_game *game)
{
	__u_int	row;
	__u_int	col;
	mlx_image_t	*img;
	mlx_texture_t *texture;

	row = 0;
	while (row < game->map_height)
	{
		col = 0;
		while (col < game->map_width)
		{
			//ice
			create_image(game->mlx, &img, "textures/ice.png", row, col);
			img->instances[0].z = 1;


			//wall
			if (game->map[row][col] == wall)
			{
				create_image(game->mlx, &img, "textures/wall.png", row, col);
				img->instances[0].z = 2;
			}

			//penguin
			if (game->map[row][col] == player)
			{
				create_image(game->mlx, &(game->player->still), "textures/penguin.png", row, col);
				game->player->still->instances[0].z = 3;
				
				create_image(game->mlx, &(game->player->up), "textures/slide_up.png", row, col);
				game->player->up->enabled = false;
				game->player->up->instances[0].z = 3;

				create_image(game->mlx, &(game->player->left), "textures/slide_left.png", row, col);
				game->player->left->enabled = false;
				game->player->left->instances[0].z = 3;

				create_image(game->mlx, &(game->player->down), "textures/slide_down.png", row, col);
				game->player->down->enabled = false;
				game->player->down->instances[0].z = 3;

				create_image(game->mlx, &(game->player->right), "textures/slide_right.png", row, col);
				game->player->right->enabled = false;
				game->player->right->instances[0].z = 3;
			}

			//coin
			if (game->map[row][col] == coin)
			{
				create_image(game->mlx, &img, "textures/fish.png", row, col);
				img->instances[0].z = 2;
			}

			//exit
			if (game->map[row][col] == home)
			{
				create_image(game->mlx, &img, "textures/home.png", row, col);
				img->instances[0].z = 2;
			}

			col++;
		}
		row++;
	}
}

int	main(void)
{
	t_game	*game;

	init(&game);
	create_map(game);
	show_map(game);

	//print_map(game);
	valid_path(game);

/*
	mlx_loop_hook(game->mlx, my_hook, game);
	mlx_key_hook(game->mlx, &my_key_hook, game);
	mlx_loop(game->mlx);
	*/
	free_game(game);
	return (0);
}
