/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:59:29 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/08/28 22:20:33 by pdel-olm         ###   ########.fr       */
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
	player = 2,
	coin = 3,
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

typedef struct s_position_node
{
	t_position				*position;
	struct s_position_node	*next;
}	t_status_node;

typedef struct s_path_checker
{ 
	t_status_node	*head;
	t_status_node	*tail;
}	t_path_checker;

typedef struct s_player
{
	mlx_image_t	*still;
	mlx_image_t	*up;
	mlx_image_t	*left;
	mlx_image_t	*down;
	mlx_image_t	*right;
	t_direction	player_movement;
}	t_player;

typedef struct s_game
{
	mlx_t		*mlx;
	__u_int		map_width;
	__u_int		map_height;
	t_cell		**map;
	t_player	*player;
	t_position	*initial_pos;
}	t_game;

	//FUNCTIONS

void	read_map(t_game *game, char *path);
bool	valid_path(t_game *game);

t_position	*create_pos(__u_int row, __u_int col);

#endif
