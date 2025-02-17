/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:57:50 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/02/17 15:58:11 by pdel-olm         ###   ########.fr       */
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
	char	*infile;
	char	*outfile;
	int		outfile_flag;
	int		first_command_pos;
}	t_pipex;

int		*execute_command(t_pipex pipex, int cmd_pos, int *read_pipe);

char	*get_command(char **path, char *command);

char	**get_env_path(char **envp);

int		*here_doc(t_pipex *pipex);

int		*init(t_pipex *pipex, int argc, char **argv, char **envp);

bool	reads_from_infile(t_pipex pipex, int cmd_pos);

bool	writes_to_outfile(t_pipex pipex, int cmd_pos);

#endif
