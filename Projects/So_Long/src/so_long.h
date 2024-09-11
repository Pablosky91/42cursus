/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:59:29 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/09/11 18:11:25 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <errno.h>
# include "libft.h"
# include "math.h"
# include "MLX42.h"

	//MACROS//

# define WALL_CHAR '1'
# define ICE_CHAR '0'
# define PENGUIN_CHAR 'P'
# define FISH_CHAR 'C'
# define HOME_CHAR 'E'

# define MAP_EXTENSION ".ber"
# define PATH_SEPARATOR '/'

	//ENUMS//

typedef enum e_error
{
	OK = 0,
	UNKNOWN,
	NO_ARGUMENT,
	NO_ALLOCATION,
	INVALID_EXTENSION,
	INEXISTENT_FILE,
	FILE_IS_DIRECTORY,
	FILE_NO_PERMISSION,
	NOT_SURROUNDED,
	NOT_RECTANGULAR,
	NO_COIN,
	NO_PLAYER,
	NO_EXIT,
	OTHER_CHARACTERS,
	NO_VALID_PATH
}	t_error;

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
	int32_t		x;
	int32_t		y;
}	t_penguin;

typedef struct s_map
{
	t_cell	**cells;
	int		width;
	int		height;
}	t_map;

typedef struct s_fish
{
	mlx_image_t	*alive;
	mlx_image_t	*dead;
	int			id;
	t_position	*position;
	bool		collected;
}	t_fish;

typedef struct s_home
{
	mlx_image_t	*open;
	mlx_image_t	*closed;
	bool		exists;
}	t_home;

typedef struct s_game
{
	mlx_t		*mlx;
	t_map		*map;
	t_penguin	*penguin;
	t_fish		**fishes;
	t_home		*home;
	t_position	*initial_pos;
	int			quantity_fishes;
	int			collected_fishes;
	int			moves;
}	t_game;

	//FUNCTIONS

void		exit_game(t_game *game, t_error error);
void		free_game(t_game *game);

void		read_map(t_game *game, char *path);
void		valid_path(t_game *game);

void		my_cursor_hook(double x_pos, double y_pos, void *param);
void		my_key_hook(mlx_key_data_t keydata, void *param);
void		my_loop_hook(void *param);
void		my_mouse_hook(mouse_key_t button, action_t action, modifier_key_t mods, void *param);
void		my_scroll_hook(double x_delta, double y_delta, void *param);
void		print_map(t_game *game);

t_position	*create_pos(int row, int col);
t_cell		get_cell_by(t_game *game, t_position	position, t_direction direction);
int			get_id_fish(t_game *game, t_position position);

#endif
