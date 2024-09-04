/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:32:14 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/09/04 20:27:00 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static const int	IMG_SIZE = 100;
static int	SPEED = 10;

t_position	pixels_to_position(int32_t x, int32_t y)
{
	t_position	position;

	position.row = y / IMG_SIZE;
	position.col = x / IMG_SIZE;

	return (position);
}

t_cell	get_cell_at(t_game *game, int32_t x, int32_t y)
{
	//ft_printf ("%i %i -> %i %i -> %i\n", y, x, y/IMG_SIZE, x/IMG_SIZE, game->map->cells[y / IMG_SIZE][x / IMG_SIZE]);
	return (game->map->cells[y / IMG_SIZE][x / IMG_SIZE]);
}

void	show_penguin(t_game *game)
{
	game->penguin->still->enabled = false;
	game->penguin->north->enabled = false;
	game->penguin->west->enabled = false;
	game->penguin->south->enabled = false;
	game->penguin->east->enabled = false;
	if (game->penguin->facing == STILL)
	{
		game->penguin->still->instances[0].x = game->penguin->x;
		game->penguin->still->instances[0].y = game->penguin->y;
		game->penguin->still->enabled = true;
	}
	if (game->penguin->facing == NORTH)
	{
		game->penguin->north->instances[0].x = game->penguin->x;
		game->penguin->north->instances[0].y = game->penguin->y;
		game->penguin->north->enabled = true;
	}
	if (game->penguin->facing == WEST)
	{
		game->penguin->west->instances[0].x = game->penguin->x;
		game->penguin->west->instances[0].y = game->penguin->y;
		game->penguin->west->enabled = true;
	}
	if (game->penguin->facing == SOUTH)
	{
		game->penguin->south->instances[0].x = game->penguin->x;
		game->penguin->south->instances[0].y = game->penguin->y;
		game->penguin->south->enabled = true;
	}
	if (game->penguin->facing == EAST)
	{
		game->penguin->east->instances[0].x = game->penguin->x;
		game->penguin->east->instances[0].y = game->penguin->y;
		game->penguin->east->enabled = true;
	}
}

void	move_penguin(t_game *game)
{
	if (game->penguin->facing == NORTH)
	{
		if (get_cell_at(game, game->penguin->x, game->penguin->y - SPEED) == WALL)
		{
			game->penguin->y = game->penguin->y / IMG_SIZE * IMG_SIZE;
			game->penguin->facing = STILL;
		}
		else
			game->penguin->y -= SPEED;
	}
	else if (game->penguin->facing == WEST)
	{
		if (get_cell_at(game, game->penguin->x -SPEED, game->penguin->y) == WALL)
		{
			game->penguin->x = game->penguin->x / IMG_SIZE * IMG_SIZE;
			game->penguin->facing = STILL;
		}
		else
			game->penguin->x -= SPEED;
	}
	else if (game->penguin->facing == SOUTH)
	{
		if (get_cell_at(game, game->penguin->x, game->penguin->y + SPEED + IMG_SIZE - 1) == WALL)
		{
			game->penguin->y = ((game->penguin->y - 1) / IMG_SIZE + 1) * IMG_SIZE;
			game->penguin->facing = STILL;
		}
		else
			game->penguin->y += SPEED;
	}
	else if (game->penguin->facing == EAST)
	{
		if (get_cell_at(game, game->penguin->x + SPEED + IMG_SIZE - 1, game->penguin->y) == WALL)
		{
			game->penguin->x = ((game->penguin->x - 1) / IMG_SIZE + 1) * IMG_SIZE;
			game->penguin->facing = STILL;
		}
		else
			game->penguin->x += SPEED;
	}
	show_penguin(game);
}

void	collect_fish(t_game *game)
{
	int id_fish = get_id_fish(game, pixels_to_position(game->penguin->x, game->penguin->y));

	if (id_fish != -1 && !game->fishes[id_fish]->collected)
	{
		game->fishes[id_fish]->alive->enabled = false;
		game->fishes[id_fish]->dead->enabled = true;
		game->fishes[id_fish]->collected = true;
		game->collected_fishes++;
		if (game->collected_fishes == game->quantity_fishes)
		{
			game->home->closed->enabled = false;
			game->home->open->enabled = true;
		}
	}
}

void	enter_home(t_game *game)
{
	if (game->collected_fishes == game->quantity_fishes && get_cell_at(game, game->penguin->x, game->penguin->y) == HOME)
	{
		free_game(game);
		exit(0);
	}
}

void	my_loop_hook(void *param)
{
	t_game	*game;

	game = param;
	move_penguin(game);
	collect_fish(game);
	enter_home(game);
	//static int frame = 0;
	//ft_printf("Frame: %i\n", frame++);
	//mlx_put_string(game->mlx, ft_strjoin("Frame: ", ft_itoa(frame)), 50, 50);
}

void	my_key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		free_game(game);
		exit(0);
	}
	if (keydata.key == MLX_KEY_KP_ADD && keydata.action == MLX_PRESS)
		SPEED++;
	if (keydata.key == MLX_KEY_KP_SUBTRACT && keydata.action == MLX_PRESS)
		SPEED--;
	if (keydata.action != MLX_PRESS || game->penguin->facing != STILL)
		return ;
	if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		game->penguin->facing = NORTH;
	else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		game->penguin->facing = WEST;
	else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		game->penguin->facing = SOUTH;
	else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		game->penguin->facing = EAST;
	if(get_cell_by(game, pixels_to_position(game->penguin->x, game->penguin->y), game->penguin->facing) != WALL)
		ft_printf("Moves: %i\n", ++game->moves);
}

void	create_image(mlx_t *mlx, mlx_image_t **img, char *path, int row, int col)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	*img = mlx_new_image(mlx, texture->width, texture->height);
	*img = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	mlx_resize_image(*img, IMG_SIZE, IMG_SIZE);
	mlx_image_to_window(mlx, *img, col * IMG_SIZE, row * IMG_SIZE);
}

void	print_map(t_game *game)
{
	int			row;
	int			col;
	mlx_image_t	*img;
	int id_fish = 0;
	game->mlx = mlx_init(game->map->width * IMG_SIZE, game->map->height * IMG_SIZE, "So Long", false);

	row = 0;
	while (row < game->map->height)
	{
		col = 0;
		while (col < game->map->width)
		{
			//ice
			create_image(game->mlx, &img, "textures/ice.png", row, col);
			img->instances[0].z = 1;


			//wall
			if (game->map->cells[row][col] == WALL)
			{
				create_image(game->mlx, &img, "textures/wall.png", row, col);
				img->instances[0].z = 2;
			}

			//penguin
			if (game->map->cells[row][col] == PENGUIN)
			{
				game->penguin->x = col * IMG_SIZE;
				game->penguin->y = row * IMG_SIZE;

				create_image(game->mlx, &(game->penguin->still), "textures/penguin.png", row, col);
				game->penguin->still->instances[0].z = 3;

				create_image(game->mlx, &(game->penguin->north), "textures/slide_up.png", row, col);
				game->penguin->north->enabled = false;
				game->penguin->north->instances[0].z = 3;

				create_image(game->mlx, &(game->penguin->west), "textures/slide_left.png", row, col);
				game->penguin->west->enabled = false;
				game->penguin->west->instances[0].z = 3;

				create_image(game->mlx, &(game->penguin->south), "textures/slide_down.png", row, col);
				game->penguin->south->enabled = false;
				game->penguin->south->instances[0].z = 3;

				create_image(game->mlx, &(game->penguin->east), "textures/slide_right.png", row, col);
				game->penguin->east->enabled = false;
				game->penguin->east->instances[0].z = 3;
			}
			
			//fish
			if (game->map->cells[row][col] == FISH)
			{
				create_image(game->mlx, &(game->fishes[id_fish]->alive), "textures/fish.png", row, col);
				game->fishes[id_fish]->alive->enabled = true;
				game->fishes[id_fish]->alive->instances[0].z = 2;

				create_image(game->mlx, &(game->fishes[id_fish]->dead), "textures/bones.png", row, col);
				game->fishes[id_fish]->dead->enabled = false;
				game->fishes[id_fish]->dead->instances[0].z = 2;

				id_fish++;
			}

			//exit
			if (game->map->cells[row][col] == HOME)
			{
				create_image(game->mlx, &(game->home->closed), "textures/home_closed.png", row, col);
				game->home->closed->instances[0].z = 2;

				create_image(game->mlx, &(game->home->open), "textures/home_open.png", row, col);
				game->home->open->enabled = false;
				game->home->open->instances[0].z = 2;
			}

			col++;
		}
		row++;
	}
}
