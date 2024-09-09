/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 11:46:39 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/09/09 22:18:58 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_extension(t_game *game, char *path)
{
	size_t	len_path;
	size_t	len_ext;
	char	*extension;

	len_path = ft_strlen(path);
	len_ext = ft_strlen(MAP_EXTENSION);
	if (len_path <= len_ext)
		exit_game(game, INVALID_EXTENSION);
	extension = ft_substr(path, len_path - len_ext, len_ext);
	if (!extension)
		exit_game(game, NO_ALLOCATION);
	if (!ft_str_equals(extension, MAP_EXTENSION))
	{
		free(extension);
		exit_game(game, INVALID_EXTENSION);
	}
	free(extension);
	if (path[len_path - len_ext - 1] == PATH_SEPARATOR)
		exit_game(game, INVALID_EXTENSION);
}

int	open_map(t_game *game, char *path)
{
	int	fd;

	fd = open(path, O_RDWR);
	if (errno == ENOENT)
		exit_game(game, INEXISTENT_FILE);
	else if (errno == EISDIR)
		exit_game(game, FILE_IS_DIRECTORY);
	close(fd);
	fd = open(path, O_RDONLY);
	if (errno == EACCES)
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
	if (!game->quantity_fishes)
		exit_game(game, NO_COIN);
	close(fd);
}

t_error	auxiliary_penguin(t_game *game, int row, int col)
{
	if (game->initial_pos)
		return (NO_PLAYER);
	game->initial_pos = malloc(sizeof(t_position));
	if (!game->initial_pos)
		return (NO_ALLOCATION);
	game->initial_pos->row = row;
	game->initial_pos->col = col;
	game->map->cells[row][col] = PENGUIN;
	return (OK);
}

t_error	auxiliary_home(t_game *game, int row, int col)
{
	if (game->home->exists)
		return (NO_EXIT);
	game->map->cells[row][col] = HOME;
	game->home->exists = true;
	return (OK);
}

t_error	auxiliary_fish(t_game *game, int row, int col)
{
	static int	fish_id = 0;

	game->map->cells[row][col] = FISH;
	game->fishes[fish_id] = malloc(sizeof(t_fish));
	if (!game->fishes[fish_id])
		return (NO_ALLOCATION);
	game->fishes[fish_id]->collected = false;
	game->fishes[fish_id]->id = fish_id;
	game->fishes[fish_id]->position = malloc(sizeof(t_position));
	if (!game->fishes[fish_id]->position)
		return (NO_ALLOCATION);
	game->fishes[fish_id]->position->row = row;
	game->fishes[fish_id]->position->col = col;
	fish_id++;
	return (OK);
}

t_error	auxiliary(t_game *game, char byte, int row, int col)
{

	if ((row == 0 || col == 0 || row == game->map->height - 1 || col == game->map->width - 1) && byte != WALL_CHAR)
		return (NOT_SURROUNDED);
	if (byte == WALL_CHAR)
		game->map->cells[row][col] = WALL;
	else if (byte == ICE_CHAR)
		game->map->cells[row][col] = ICE;
	else if (byte == PENGUIN_CHAR)
		return (auxiliary_penguin(game, row, col));
	else if (byte == HOME_CHAR)
		return (auxiliary_home(game, row, col));
	else if (byte == FISH_CHAR)
		return (auxiliary_fish(game, row, col));
	else
		return (OTHER_CHARACTERS);
	return (OK);
}

//TODO error malloc 
void	read_map(t_game *game, char *path)
{
	char	*buffer;
	int		row;
	int		col;
	int		fd;
	t_error	error_code;

	check_extension(game, path);
	get_info_map(game, path);
	game->map->cells = ft_calloc(game->map->height + 1, sizeof(t_cell *));
	if (!game->map->cells)
		exit_game(game, NO_ALLOCATION);
	game->fishes = ft_calloc(game->quantity_fishes + 1, sizeof(t_fish *));
	if (!game->fishes)
		exit_game(game, NO_ALLOCATION);
	fd = open_map(game, path);
	buffer = malloc(sizeof(char));
	if (!buffer)
		exit_game(game, NO_ALLOCATION);
	row = 0;
	while (row < game->map->height)
	{
		col = 0;
		game->map->cells[row] = ft_calloc(game->map->width + 1, sizeof(t_cell));
		if (!game->map->cells[row])
			exit_game(game, NO_ALLOCATION);
		while (col < game->map->width)
		{
			read(fd, buffer, 1);
			//TODO invalid read
			error_code = auxiliary(game, buffer[0], row, col);
			if (error_code)
				exit_game(game, error_code);
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
	valid_path(game);
}
