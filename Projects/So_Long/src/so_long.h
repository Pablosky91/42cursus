/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:59:29 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/08/29 17:41:56 by pdel-olm         ###   ########.fr       */
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
	wall = 0,
	ice = 1,
	penguin = 2,
	fish = 3,
	home = 4
}	t_cell;

typedef enum e_direction
{
	still = 0,
	up = 1,
	left = 2,
	down = 3,
	right = 4
}	t_direction;

	//STRUCTS//

typedef struct s_position
{
	__u_int	row;
	__u_int	col;
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
	mlx_image_t	*up;
	mlx_image_t	*left;
	mlx_image_t	*down;
	mlx_image_t	*right;
	t_direction	facing;
}	t_penguin;

typedef struct s_map
{
	__u_int	width;
	__u_int	height;
	t_cell	**cells;
}	t_map;

typedef struct s_fish
{
	mlx_image_t	*alive;
	mlx_image_t	*dead;
	__u_int		id;
	t_position	*position;
	bool		collected;
}	t_fish;

typedef struct s_game
{
	mlx_t		*mlx;
	t_map		*map;
	t_penguin	*penguin;
	t_fish		**fishes;
	__u_int		quantity_fishes;
	t_position	*initial_pos;
}	t_game;

	//FUNCTIONS

void	free_game(t_game *game);

void	read_map(t_game *game, char *path);
bool	valid_path(t_game *game);

void	my_loop_hook(void* param);
void	my_key_hook(mlx_key_data_t keydata, void* param);
void	print_map(t_game *game);


t_position	*create_pos(__u_int row, __u_int col);

#endif
