/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:57:50 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/01/24 19:54:06 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <sys/wait.h>

# define PIPE_READ	STDIN_FILENO
# define PIPE_WRITE	STDOUT_FILENO

typedef struct s_pipex
{
	int		argc;
	char	**argv;
	char	**envp;
	char	**path;
}	t_pipex;

#endif
