/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:59:29 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/03 11:18:57 by pdel-olm         ###   ########.fr       */
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

# define WINDOW_TITLE "So Long"

	//ENUMS//

typedef enum e_exit_code
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
	NO_VALID_PATH,
	MAX_CODE
}	t_exit_code;

typedef enum e_cell
{
	WALL = 0,
	ICE = 1,
	FISH = 2,
	PENGUIN = 3,
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

typedef struct s_status_node
{
	int						row;
	int						col;
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
	int			row;
	int			col;
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
	mlx_t			*mlx;
	t_map			*map;
	t_penguin		*penguin;
	t_fish			**fishes;
	t_home			*home;
	t_path_checker	*checker;
	int				initial_row;
	int				initial_col;
	int				quantity_fishes;
	int				collected_fishes;
	int				moves;
	int				img_size;
	int				speed;
}	t_game;

	//FUNCTIONS//

	//CONTROL//

void			exit_game(t_game *game, t_exit_code error);
void			free_checker(t_path_checker *checker);
void			free_game(t_game *game);
void			free_status(t_status_node *status);

	//PARSE//

void			check_extension(t_game *game, char *path);
t_exit_code		get_info_map(t_game *game, char *path);
int				open_file(t_game *game, char *path);
void			read_map(t_game *game, char *path);
t_exit_code		save_cell(t_game *game, char byte, int row, int col);

	//PATHING//

void			add_node(t_game *game, t_status_node	*node);
t_status_node	*copy_node(t_game *game, t_status_node *node);
t_status_node	*create_node(t_game *game, int row, int col);
t_cell			get_cell_by(t_game *game, int row, int col, t_direction direction);
int				get_id_fish(t_game *game, int row, int col);
bool			is_same_status(t_game *game, t_status_node *status_1, t_status_node *status_2);
bool			is_node_repeated(t_game *game, t_status_node *node);
void			valid_path(t_game *game);

	//WINDOW//

void			init_mlx(t_game *game);
void			my_key_hook(mlx_key_data_t keydata, void *param);
void			my_loop_hook(void *param);
void			start_movement(t_game *game, t_direction direction);

t_cell			get_cell_by(t_game *game, int row, int col, t_direction direction);
int				get_id_fish(t_game *game, int row, int col);
void			move_penguin(t_game *game);
void			collect_fish(t_game *game);
void			enter_home(t_game *game);

//BONUSvoid		my_cursor_hook(double x_pos, double y_pos, void *param);
//BONUSvoid		my_mouse_hook(mouse_key_t button, action_t action, modifier_key_t mods, void *param);
//BONUSvoid		my_scroll_hook(double x_delta, double y_delta, void *param);

#endif
