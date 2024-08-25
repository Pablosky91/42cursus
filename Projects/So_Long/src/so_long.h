/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:59:29 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/08/22 23:35:25 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "MLX42.h"

	//ENUMS//

typedef enum e_cell
{
	wall = 0,
	floor = 1,
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
}	t_game;

#endif
