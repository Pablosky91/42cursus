/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:57:50 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/02/04 17:00:21 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <sys/wait.h>

# define PIPE_READ	STDIN_FILENO
# define PIPE_WRITE	STDOUT_FILENO

# define PIPE_HEREDOC "\e[1mpipe heredoc> \e[0m"
# define HERE_DOC "here_doc"

typedef struct s_pipex
{
	int		argc;
	char	**argv;
	char	**envp;
	char	**path;
	char	*infile;
	char	*outfile;
	int		outfile_flag;
	int		first_command_pos;
}	t_pipex;

#endif
