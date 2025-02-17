/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:52:11 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/02/17 15:53:48 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*join_path(char *path, char *command);

//TODO investigate what happens if no command is found
char	*get_command(char **path, char *command)
{
	char	*path_command;
	int		path_iter;

	if (!path)
		return (NULL);
	path_iter = -1;
	while (path[++path_iter])
	{
		path_command = join_path(path[path_iter], command);
		if (!path_command)
			return (NULL);
		if (!access(path_command, X_OK))
			return (path_command);
		free(path_command);
	}
	return (NULL);
}

static char	*join_path(char *path, char *command)
{
	char		*path_command;
	size_t		len_path;
	size_t		len_command;
	size_t		aux;

	len_path = ft_strlen(path);
	len_command = ft_strlen(command);
	path_command = malloc(len_path + len_command + 2 * sizeof(char));
	if (!path_command)
		return (NULL);
	aux = -1;
	while (++aux < len_path)
		path_command[aux] = path[aux];
	path_command[aux] = '/';
	while (++aux < len_path + len_command + 1)
		path_command[aux] = command[aux - len_path - 1];
	path_command[aux] = 0;
	return (path_command);
}
