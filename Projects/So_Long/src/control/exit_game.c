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

void	message_error(t_error error)
{
	if (error == NO_ARGUMENT)
		ft_printf("Error\nThe program takes as parameter a map description file\n");
	else if (error == UNKNOWN)
		ft_printf("Error\nUnknown error happened during the execution\n");
	else if (error == NO_ALLOCATION)
		ft_printf("Error\nCannot allocate memory\n");
	else if (error == INEXISTENT_FILE)
		ft_printf("Error\nNo such file\n");
	else if (error == FILE_IS_DIRECTORY)
		ft_printf("Error\nMap path leads to a directory\n");
	else if (error == FILE_NO_PERMISSION)
		ft_printf("Error\nPermission to read map file denied\n");
	else if (error == INVALID_EXTENSION)
		ft_printf("Error\nMap file must have .ber extension\n");
	else if (error == NOT_RECTANGULAR)
		ft_printf("Error\nThe map must be rectangular\n");
	else if (error == NOT_SURROUNDED)
		ft_printf("Error\nThe map must be surrounded by walls\n");
	else if (error == OTHER_CHARACTERS)
		ft_printf("Error\nThe map is composed of invalid characters\n");
	else if (error == NO_COIN)
		ft_printf("Error\nThe map must contain at least one collectible\n");
	else if (error == NO_PLAYER)
		ft_printf("Error\nThe map must contain one and only one starting position\n");
	else if (error == NO_EXIT)
		ft_printf("Error\nThe map must contain one and only one exit\n");
	else if (error == NO_VALID_PATH)
		ft_printf("Error\nThe map must have a valid path\n");
}

void	exit_game(t_game *game, t_error error)
{
	message_error(error);
	free_game(game);
	exit(error);
}
