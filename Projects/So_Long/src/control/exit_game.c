/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:21:57 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/09/06 16:24:42 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static const char	*g_message[MAX_CODE] = {
	"",
	"Error\nUnknown error happened during the execution\n",
	"Error\nThe program takes as parameter a map description file\n",
	"Error\nCould not allocate memory\n",
	"Error\nMap file must have .ber extension\n",
	"Error\nNo such file\n",
	"Error\nMap path leads to a directory\n",
	"Error\nPermission to read map file denied\n",
	"Error\nThe map must be surrounded by walls\n",
	"Error\nThe map must be rectangular\n",
	"Error\nThe map must contain at least one collectible\n",
	"Error\nThe map must contain one and only one starting position\n",
	"Error\nThe map must contain one and only one exit\n",
	"Error\nThe map is composed of invalid characters\n",
	"Error\nThe map must have a valid path\n",
	"Error\nCould not create the window\n",
	"Error\nCould not load a PNG file\n",
	"Error\nCould not resize an image\n",
	"Error\nCould not print an image in the window\n"
};

void	exit_game(t_game *game, t_exit_code error)
{
	ft_printf(g_message[error]);
	free_game(game);
	exit(error);
}
