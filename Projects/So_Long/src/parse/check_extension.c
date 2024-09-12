/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:00:26 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/09/12 13:00:35 by pdel-olm         ###   ########.fr       */
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
