/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 11:46:39 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/08/28 21:28:41 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_size_map(t_game *game, char *path)
{
	char		*line;
	__u_int		length;
	int			fd;

	fd = open(path, O_RDONLY);
	game->map_height = 0;
	game->map_width = 0;
	line = get_next_line(fd);
	while (line)
	{
		length = ft_strlen(line);
		if (line[length - 1] == '\n')
			length--;
		if (game->map_width && length != game->map_width)
			ft_printf("different sized rows\n");
		//TODO error size rows
		game->map_width = length;
		game->map_height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

/*
void	read_map(t_game *game)
{
	char	*line;
	__u_int row = 0;
	int fd = open(MAP_PATH, O_RDONLY);
	size_t len;

	int i = 0;
	game->map = malloc(sizeof(t_cell *) * ROWS);
	while (i < ROWS)
		game->map[i++] = malloc(sizeof(t_cell *) * COLS);
	game->map_height = ROWS;
	game->map_width = COLS;

	line = get_next_line(fd);
	while (line)
	{
		len = ft_strlen(line);
		while (len > 0)
		{
			if (line[len - 1] == '1')
				game->map[row][len - 1] = wall;
			else if (line[len - 1] == '0')
				game->map[row][len - 1] = ice;
			else if (line[len - 1] == 'P')
			{
				game->map[row][len - 1] = player;
				game->initial_pos = create_pos(row, len - 1);
			}
			else if (line[len - 1] == 'E')
				game->map[row][len - 1] = home;
			else if (line[len - 1] == 'C')
				game->map[row][len - 1] = coin;
			len--;
		}
		row++;
		free(line);
		line = get_next_line(fd);
	}


	//free(line);
}
*/

//TODO test with empty or small file
void	read_map(t_game *game, char *path)
{
	char	*buffer;
	__u_int row;
	__u_int col;
	int fd;

	buffer = malloc(sizeof(char));
	get_size_map(game, path);
	fd = open(path, O_RDONLY);
	game->map = malloc(sizeof(t_cell *) * game->map_height);
	row = 0;
	while (row < game->map_height)
	{
		col = 0;
		game->map[row] = malloc(sizeof(t_cell *) * game->map_width);
		while (col < game->map_width)
		{
			read(fd, buffer, 1);
			if (buffer[0] == '1')
				game->map[row][col] = wall;
			else if (buffer[0] == '0')
				game->map[row][col] = ice;
			else if (buffer[0] == 'P')
			{
				game->map[row][col] = player;
				game->initial_pos->row = row;
				game->initial_pos->col = col;
			}
			else if (buffer[0] == 'E')
				game->map[row][col] = home;
			else if (buffer[0] == 'C')
				game->map[row][col] = coin;
			col++;
		}
		read(fd, buffer, 1);
		row++;
	}
	free(buffer);
}
