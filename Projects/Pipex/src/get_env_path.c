/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 21:46:11 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/02/17 20:15:58 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_env_path(char **envp)
{
	int		env_iter;
	char	**split;
	char	*substr;

	env_iter = -1;
	while (envp[++env_iter])
	{
		if (ft_strncmp(envp[env_iter], "PATH=", 5))
			continue ;
		substr = ft_substr(envp[env_iter], 5, ft_strlen(envp[env_iter]) - 5);
		if (!substr)
			return (NULL);
		split = ft_split(substr, ':');
		free(substr);
		if (!split)
			return (NULL);
		return (split);
	}
	return (NULL);
}
