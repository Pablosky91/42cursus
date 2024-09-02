/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 11:46:39 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/09/02 16:16:38 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_count_char(char *s, int c)
{
	size_t	i;
	size_t	len;
	size_t	count;

	i = 0;
	len = ft_strlen(s);
	count = 0;
	while (i <= len)
	{
		if (s[i] == (char) c)
			count++;
		i++;
	}
	return (count);
}

void	get_size_map(t_game *game, char *path)
{
	char	*line;
	int		length;
	int		fd;

	fd = open(path, O_RDONLY);
	game->map->height = 0;
	game->map->width = 0;
	line = get_next_line(fd);
	while (line)
	{
		length = ft_strlen(line);
		if (line[length - 1] == '\n')
			length--;
		if (game->map->width && length != game->map->width)
			ft_printf("different sized rows\n");
		//TODO error size rows
		game->quantity_fishes += ft_count_char(line, 'C');
		game->map->width = length;
		game->map->height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

//TODO test with empty or small file
void	read_map(t_game *game, char *path)
{
	char	*buffer;
	int		row;
	int		col;
	int		fd;
	int		fish_id;

	buffer = malloc(sizeof(char));
	get_size_map(game, path);
	fd = open(path, O_RDONLY);
	game->map->cells = ft_calloc(game->map->height + 1, sizeof(t_cell *));
	game->fishes = ft_calloc(game->quantity_fishes + 1, sizeof(t_fish *));
	row = 0;
	fish_id = 0;
	while (row < game->map->height)
	{
		col = 0;
		game->map->cells[row] = ft_calloc(game->map->width + 1, sizeof(t_cell));
		while (col < game->map->width)
		{
			read(fd, buffer, 1);
			if (buffer[0] == '1')
				game->map->cells[row][col] = WALL;
			else if (buffer[0] == '0')
				game->map->cells[row][col] = ICE;
			else if (buffer[0] == 'P')
			{
				game->map->cells[row][col] = PENGUIN;
				game->initial_pos->row = row;
				game->initial_pos->col = col;
			}
			else if (buffer[0] == 'E')
				game->map->cells[row][col] = HOME;
			else if (buffer[0] == 'C')
			{
				game->map->cells[row][col] = FISH;
				game->fishes[fish_id] = malloc(sizeof(t_fish));
				game->fishes[fish_id]->collected = false;
				game->fishes[fish_id]->id = fish_id;
				game->fishes[fish_id]->position = malloc(sizeof(t_position));
				game->fishes[fish_id]->position->row = row;
				game->fishes[fish_id]->position->col = col;
				fish_id++;
			}
			col++;
		}
		read(fd, buffer, 1);
		row++;
	}
	free(buffer);
}
