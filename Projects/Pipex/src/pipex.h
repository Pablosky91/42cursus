/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:57:50 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/02/20 17:50:58 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <sys/wait.h>

# define PIPE_READ	STDIN_FILENO
# define PIPE_WRITE	STDOUT_FILENO

typedef enum e_exit_code
{
	EC_SUCCESS					= 0,
	EC_ERROR					= 1,
	EC_COMMAND_NOT_EXECUTABLE	= 126,
	EC_COMMAND_NOT_FOUND		= 127
}	t_exit_code;

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

int			*process_command(t_pipex pipex, int cmd_pos, int *read_pipe, pid_t *last_child);

t_exit_code	get_command(char **path, char *command, char **path_command);

char		**get_env_path(char **envp);

int			*here_doc(t_pipex *pipex);

int			*init(t_pipex *pipex, int argc, char **argv, char **envp);

int			exit_pipex(t_pipex pipex, pid_t last_child);

bool		reads_from_infile(t_pipex pipex, int cmd_pos);

bool		writes_to_outfile(t_pipex pipex, int cmd_pos);

#endif
