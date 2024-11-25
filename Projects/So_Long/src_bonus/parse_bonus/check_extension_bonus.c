/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:26:46 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/11/25 21:05:26 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_extension(t_game *game, char *path)
{
	size_t	len_path;
	size_t	len_ext;
	char	*extension;

	len_path = ft_strlen(path);
	len_ext = ft_strlen(MAP_EXTENSION);
	if (len_path <= len_ext)
		exit_game(game, SL_INVALID_EXTENSION);
	extension = ft_substr(path, len_path - len_ext, len_ext);
	if (!extension)
		exit_game(game, SL_NO_ALLOCATION);
	if (!ft_str_equals(extension, MAP_EXTENSION))
	{
		free(extension);
		exit_game(game, SL_INVALID_EXTENSION);
	}
	free(extension);
	if (path[len_path - len_ext - 1] == PATH_SEPARATOR)
		exit_game(game, SL_INVALID_EXTENSION);
	game->map->name = ft_strrchr(path, PATH_SEPARATOR);
	game->map->name = ft_substr(game->map->name, 1,
			ft_strlen(game->map->name) - len_ext - 1);
	if (!game->map->name)
		exit_game(game, SL_NO_ALLOCATION);
}
