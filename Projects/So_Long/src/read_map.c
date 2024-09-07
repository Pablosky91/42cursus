/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 11:46:39 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/09/06 19:37:26 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_map(t_game *game, char *path)
{
	int	fd;

	fd = open(path, O_RDWR);
	if (errno == ENOENT)
		exit_game(game, INEXISTENT_FILE);
	else if (errno == EISDIR)
		exit_game(game, FILE_IS_DIRECTORY);
	else if (errno == EACCES)
		exit_game(game, FILE_NO_PERMISSION);
	return (fd);
}
/*
Gets width, height and number of fishes
*/
void	get_info_map(t_game *game, char *path)
{
	char	*line;
	int		length;
	int		fd;

	fd = open_map(game, path);
	line = get_next_line(fd);
	if (!line)
		exit_game(game, NOT_SURROUNDED);
	game->map->width = ft_strlen(line);
	if (line[ft_strlen(line) - 1] == '\n')
		game->map->width--;
	while (line)
	{
		length = ft_strlen(line);
		if ((line[length - 1] != '\n' || length - 1 != game->map->width)
			&& (line[length - 1] == '\n' || length != game->map->width))
			exit_game(game, NOT_RECTANGULAR);
		game->quantity_fishes += ft_count_char(line, FISH_CHAR);
		game->map->height++;
		free(line);
		line = get_next_line(fd);
	}
	if (game->quantity_fishes == 0)
		exit_game(game, NO_COIN);
	close(fd);
}

void	auxiliary_penguin(t_game *game, int row, int col)
{
	if (game->initial_pos)
		exit_game(game, NO_PLAYER);
	game->initial_pos = malloc(sizeof(t_position));
	game->initial_pos->row = row;
	game->initial_pos->col = col;
	game->map->cells[row][col] = PENGUIN;
}

void	auxiliary_home(t_game *game, int row, int col)
{
	if (game->home->exists)
		exit_game(game, NO_EXIT);
	game->map->cells[row][col] = HOME;
	game->home->exists = true;
}

void	auxiliary_fish(t_game *game, int row, int col)
{
	static int fish_id = 0;

	game->map->cells[row][col] = FISH;
	game->fishes[fish_id] = malloc(sizeof(t_fish));
	game->fishes[fish_id]->collected = false;
	game->fishes[fish_id]->id = fish_id;
	game->fishes[fish_id]->position = malloc(sizeof(t_position));
	game->fishes[fish_id]->position->row = row;
	game->fishes[fish_id]->position->col = col;
	fish_id++;
}

void	auxiliary(t_game *game, char byte, int row, int col)
{

	if ((row == 0 || col == 0 || row == game->map->height - 1 || col == game->map->width - 1) && byte != WALL_CHAR)
		exit_game(game, NOT_SURROUNDED);
	if (byte == WALL_CHAR)
		game->map->cells[row][col] = WALL;
	else if (byte == ICE_CHAR)
		game->map->cells[row][col] = ICE;
	else if (byte == PENGUIN_CHAR)
		auxiliary_penguin(game, row, col);
	else if (byte == HOME_CHAR)
		auxiliary_home(game, row, col);
	else if (byte == FISH_CHAR)
		auxiliary_fish(game, row, col);
	else
		exit_game(game, OTHER_CHARACTERS);
}

//TODO test with empty or small file
void	read_map(t_game *game, char *path)
{
	char	*buffer;
	int		row;
	int		col;
	int		fd;
	//int		fish_id;

	buffer = malloc(sizeof(char));
	get_info_map(game, path);
	fd = open_map(game, path);
	game->map->cells = ft_calloc(game->map->height + 1, sizeof(t_cell *));
	game->fishes = ft_calloc(game->quantity_fishes + 1, sizeof(t_fish *));
	row = 0;
	//fish_id = 0;
	while (row < game->map->height)
	{
		col = 0;
		game->map->cells[row] = ft_calloc(game->map->width + 1, sizeof(t_cell));
		while (col < game->map->width)
		{
			read(fd, buffer, 1);
			auxiliary(game, buffer[0], row, col);
			col++;
		}
		read(fd, buffer, 1);
		row++;
	}
	free(buffer);
	if (!game->initial_pos)
		exit_game(game, NO_PLAYER);
	if (!game->home->exists)
		exit_game(game, NO_EXIT);
}
