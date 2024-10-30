/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:30:00 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/30 11:06:40 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <errno.h>
# include <math.h>
# include "libft.h"
# include "MLX42.h"

/******************************************************************************/
/*                                   MACROS                                   */
/******************************************************************************/

# define WALL_CHAR		'1'
# define ICE_CHAR		'0'
# define PENGUIN_CHAR	'P'
# define FISH_CHAR		'C'
# define HOME_CHAR		'E'
# define SEAL_CHAR		'S'

# define MAP_EXTENSION	".ber"
# define PATH_SEPARATOR	'/'

# define WINDOW_TITLE	"So Long"
# define WINDOW_SIZE	0.95
# define RELATIVE_SPEED 0.125

# define ICE_LAYER		1
# define OBJECTS_LAYER	2
# define PENGUIN_LAYER	3
# define SEAL_LAYER		4

# define FRAMES_PENGUIN_STILL	30
# define FRAMES_PENGUIN_MOVING	10

# define IMG_ICE			"textures/ice.png"
# define IMG_WALL			"textures/wall.png"
# define IMG_PENGUIN_A		"textures/penguin_a.png"
# define IMG_PENGUIN_B		"textures/penguin_b.png"
# define IMG_PENGUIN_N_A	"textures/penguin_up_a.png"
# define IMG_PENGUIN_N_B	"textures/penguin_up_b.png"
# define IMG_PENGUIN_W_A	"textures/penguin_left_a.png"
# define IMG_PENGUIN_W_B	"textures/penguin_left_b.png"
# define IMG_PENGUIN_S_A	"textures/penguin_down_a.png"
# define IMG_PENGUIN_S_B	"textures/penguin_down_b.png"
# define IMG_PENGUIN_E_A	"textures/penguin_right_a.png"
# define IMG_PENGUIN_E_B	"textures/penguin_right_b.png"
# define IMG_FISH_ALIVE		"textures/fish.png"
# define IMG_FISH_DEAD		"textures/bones.png"
# define IMG_HOME_CLOSED	"textures/home_closed.png"
# define IMG_HOME_OPEN		"textures/home_open.png"
# define IMG_SEAL			"textures/seal.png"
# define IMG_LOGO			"textures/logo.png"
# define IMG_CURSOR_N		"textures/cursor_up.png"
# define IMG_CURSOR_W		"textures/cursor_left.png"
# define IMG_CURSOR_S		"textures/cursor_down.png"
# define IMG_CURSOR_E		"textures/cursor_right.png"

# define MOVE_MSG	"Moves: %i\n"

/******************************************************************************/
/*                                   ENUMS                                    */
/******************************************************************************/

typedef enum e_exit_code
{
	SL_OK					= 0,
	SL_SURRENDER			= 1,
	SL_DEATH				= 2,
	SL_UNKNOWN				= 3,
	SL_NO_ARGUMENT			= 4,
	SL_NO_ALLOCATION		= 5,
	SL_INVALID_EXTENSION	= 6,
	SL_INEXISTENT_FILE		= 7,
	SL_FILE_IS_DIRECTORY	= 8,
	SL_FILE_NO_PERMISSION	= 9,
	SL_NOT_SURROUNDED		= 10,
	SL_NOT_RECTANGULAR		= 11,
	SL_NO_COIN				= 12,
	SL_NO_PLAYER			= 13,
	SL_NO_EXIT				= 14,
	SL_OTHER_CHARACTERS		= 15,
	SL_NO_VALID_PATH		= 16,
	SL_MLX_INIT				= 17,
	SL_MLX_PNG				= 18,
	SL_MLX_RESIZE			= 19,
	SL_MLX_PRINT			= 20,
	SL_MAX_CODE				= 21
}	t_exit_code;

typedef enum e_cell
{
	WALL	= 0,
	ICE		= 1,
	FISH	= 2,
	PENGUIN	= 3,
	HOME	= 4,
	SEAL	= 5
}	t_cell;

typedef enum e_direction
{
	STILL	= 0,
	NORTH	= 1,
	WEST	= 2,
	SOUTH	= 3,
	EAST	= 4
}	t_direction;

/******************************************************************************/
/*                                  STRUCTS                                   */
/******************************************************************************/

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
	mlx_image_t	*still_a;
	mlx_image_t	*still_b;
	mlx_image_t	*north_a;
	mlx_image_t	*north_b;
	mlx_image_t	*west_a;
	mlx_image_t	*west_b;
	mlx_image_t	*south_a;
	mlx_image_t	*south_b;
	mlx_image_t	*east_a;
	mlx_image_t	*east_b;
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

typedef struct s_cursor
{
	mlx_win_cursor_t	*up;
	mlx_win_cursor_t	*left;
	mlx_win_cursor_t	*down;
	mlx_win_cursor_t	*right;
}	t_cursor;

typedef struct s_game
{
	mlx_t			*mlx;
	t_map			*map;
	t_penguin		*penguin;
	t_fish			**fishes;
	t_home			*home;
	t_path_checker	*checker;
	t_cursor		*cursor;
	int				initial_row;
	int				initial_col;
	int				quantity_fishes;
	int				collected_fishes;
	int				moves;
	int				img_size;
	int				speed;
	int				frame;
}	t_game;

/******************************************************************************/
/*                                 FUNCTIONS                                  */
/******************************************************************************/

/******************************************************************************/
/*                            FUNCTIONS - CONTROL                             */
/******************************************************************************/

/**
 * @brief Exits the program in a clean way, freeing all allocated memory.
 * 
 * @param game All game information.
 * @param exit_code The reason why the program is closed.
 */
void			exit_game(t_game *game, t_exit_code exit_code);

/**
 * @brief Frees all allocated memory by the program.
 * 
 * @param game All game information.
 */
void			free_game(t_game *game);

/**
 * @brief Frees a node from the path_checker.
 * 
 * @param status The status_node to be freed.
 */
void			free_status(t_status_node *status);

/******************************************************************************/
/*                             FUNCTIONS - PARSE                              */
/******************************************************************************/

/**
 * @brief Checks the given path has a valid extension.
 * 
 * @param game All game information.
 * @param path The path of the map file.
 */
void			check_extension(t_game *game, char *path);

/**
 * @brief Gets width, height and number of fishes of the map.
 * 
 * @param game All game information.
 * @param path The path of the map file.
 * @return Exit code (type of error or success).
 */
t_exit_code		get_info_map(t_game *game, char *path);

/**
 * @brief Opens the file, checking for several errors.
 * 
 * @param game All game information.
 * @param path The path of the map file.
 * @return The file descriptor.
 */
int				open_file(t_game *game, char *path);

/**
 * @brief Reads and stores a map.
 * 
 * @param game All game information.
 * @param path The path of the map file.
 */
void			read_map(t_game *game, char *path);

/**
 * @brief Saves a cell in the map structure.
 * 
 * @param game All game information.
 * @param byte Byte read from the map file.
 * @param row Row of the map.
 * @param col Column of the map.
 * @return Exit code (type of error or success).
 */
t_exit_code		save_cell(t_game *game, char byte, int row, int col);

/******************************************************************************/
/*                            FUNCTIONS - PATHING                             */
/******************************************************************************/

/**
 * @brief Adds a node to the back of the checker list.
 * 
 * @param game All game information.
 * @param node The node to be added.
 */
void			add_node(t_game *game, t_status_node	*node);

/**
 * @brief Copies the content of a node.
 * 
 * @param game All game information.
 * @param node The node to be copied.
 * @return A pointer of the new node.
 */
t_status_node	*copy_node(t_game *game, t_status_node *node);

/**
 * @brief Creates a new node with a given position and an empty fish array.
 * 
 * @param game All game information.
 * @param row Row of the node.
 * @param col Column of the row.
 * @return A pointer of the new node.
 */
t_status_node	*create_node(t_game *game, int row, int col);

/**
 * @brief Gets the type of the cell next to a position in a given direction.
 * 
 * @param game All game information.
 * @param row Row of the initial cell.
 * @param col Column of the initial cell.
 * @param direction The direction to get the wanted cell.
 * @return The type of cell.
 */
t_cell			get_cell_by(t_game *game,
					int row, int col, t_direction direction);

/**
 * @brief Gets the fish id from a position, if it exists.
 * 
 * @param game All game information.
 * @param row The row of the fish.
 * @param col The column of the fish.
 * @return The fish id. -1 if there's no fish on that position.
 */
int				get_id_fish(t_game *game, int row, int col);

/**
 * @brief Compares the content of two nodes.
 * 
 * @param game All game information.
 * @param status_1 One node.
 * @param status_2 The other node.
 * @return Wether they are the same status or not.
 */
bool			is_same_status(t_game *game,
					t_status_node *status_1, t_status_node *status_2);

/**
 * @brief Compares the given node to all stored nodes in the checker.
 * 
 * @param game All game information.
 * @param node The new node to be compared.
 * @return Wether the node is repeated or not.
 */
bool			is_node_repeated(t_game *game, t_status_node *node);

/**
 * @brief Checks wether there is a valid path in a map.
 * 
 * @param game All game information.
 */
void			valid_path(t_game *game);

/******************************************************************************/
/*                             FUNCTIONS - WINDOW                             */
/******************************************************************************/

/**
 * @brief Creates a window to display the game.
 * 
 * @param game All game information.
 */
void			create_window(t_game *game);

/**
 * @brief Calculates the direction from the center of the penguin to the cursor.
 * 
 * @param game All game information.
 * @return The direction from penguin to the cursor.
 */
t_direction		direction_to_mouse(t_game *game);

/**
 * @brief Creates the mlx instance, window and all images.
 * 
 * @param game All game information.
 */
void			init_mlx(t_game *game);

/**
 * @brief Updates the ordinates of the penguin as it moves.
 * 
 * @param game All game information.
 * @param moving Direction in which the penguin is moving.
 * @param future_x Actual x ordinate of the penguin.
 * @param future_y Actual y ordinate of the penguin.
 * @return The id of the cell the penguin moves onto.
 * If there is a fish, its id. If it is the home, -HOME. Any other cell -1.
 */
int				move_penguin(t_game *game,
					t_direction moving, int32_t x, int32_t y);

//TODO doc
void			my_close_hook(void *param);

//TODO doc
void			my_cursor_hook(double x_pos, double y_pos, void *param);

/**
 * @brief Function called whenever a key is acted on.
 * It starts the movement based on the input.
 * 
 * @param keydata All keydata information.
 * @param param All game information.
 */
void			my_key_hook(mlx_key_data_t keydata, void *param);

/**
 * @brief Function called every frame of the game.
 * It moves and shows the penguin and checks for fishes and the home.
 * 
 * @param param All game information.
 */
void			my_loop_hook(void *param);

//TODO doc
void			my_mouse_hook(mouse_key_t button,
					action_t action, modifier_key_t mods, void *param);

//TODO doc
void			my_scroll_hook(double x_delta, double y_delta, void *param);

//TODO doc
/**
 * @brief 
 * 
 * @param game All game information.
 */
void			retry(t_game *game);

/**
 * @brief Updates the position and sprite of the penguin in the window.
 * 
 * @param game All game information.
 */
void			show_penguin(t_game *game);

/**
 * @brief Starts the movement in the given direction when possible.
 * 
 * @param game All game information.
 * @param direction The direction to move.
 */
void			start_movement(t_game *game, t_direction direction);

#endif
