/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 11:46:39 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/08/27 19:57:49 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static const char *MAP_PATH = "maps/valid_medium.ber";
static const int ROWS = 7;
static const int COLS = 9;

/* void	read_map(t_game *game)
{
	int fd = open(MAP_PATH, O_RDONLY);
	char *c = malloc(1);
	__u_int row = 0;
	__u_int col = 0;
	int br = 1;
	while (br > 0)
	{
		br = read(fd, c, 1);
		if (c[0] == '1')
			game->map[row][col] = wall;
		else if (c[0] == '0')
			game->map[row][col] = ice;
		else if (c[0] == 'P')
		{
			game->map[row][col] = player;
			game->initial_pos = create_pos(row, col);
		}
		else if (c[0] == 'E')
			game->map[row][col] = home;
		else if (c[0] == 'C')
			game->map[row][col] = coin;
		else if (c[0] == '\n')
		{
			row++;
			col = -1;
		}
		else
			break;
		col++;
	}
	printf("row %i  col %i\n", row, col);
	free(c);
} */

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
