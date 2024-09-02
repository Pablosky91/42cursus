/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:59:29 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/09/02 16:15:59 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "math.h"
# include "MLX42.h"

	//ENUMS//

typedef enum e_cell
{
	WALL = 0,
	ICE = 1,
	PENGUIN = 2,
	FISH = 3,
	HOME = 4
}	t_cell;

typedef enum e_direction
{
	STILL = 0,
	NORTH = 1,
	WEST = 2,
	SOUTH = 3,
	EAST = 4
}	t_direction;

	//STRUCTS//

typedef struct s_position
{
	int	row;
	int	col;
}	t_position;

typedef struct s_status_node
{
	t_position				*position;
	bool					*fishes;
	struct s_status_node	*next;
}	t_status_node;

typedef struct s_path_checker
{
	t_status_node	*head;
	t_status_node	*tail;
}	t_path_checker;

typedef struct s_penguin
{
	mlx_image_t	*still;
	mlx_image_t	*north;
	mlx_image_t	*west;
	mlx_image_t	*south;
	mlx_image_t	*east;
	t_direction	facing;
}	t_penguin;

typedef struct s_map
{
	int		width;
	int		height;
	t_cell	**cells;
}	t_map;

typedef struct s_fish
{
	mlx_image_t	*alive;
	mlx_image_t	*dead;
	int			id;
	t_position	*position;
	bool		collected;
}	t_fish;

typedef struct s_game
{
	mlx_t		*mlx;
	t_map		*map;
	t_penguin	*penguin;
	t_fish		**fishes;
	int			quantity_fishes;
	t_position	*initial_pos;
}	t_game;

	//FUNCTIONS

void		free_game(t_game *game);

void		read_map(t_game *game, char *path);
bool		valid_path(t_game *game);

void		my_loop_hook(void *param);
void		my_key_hook(mlx_key_data_t keydata, void *param);
void		print_map(t_game *game);


t_position	*create_pos(int row, int col);

#endif
