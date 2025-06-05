/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:39:22 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/03/08 00:08:07 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	*init(t_pipex *pipex, int argc, char **argv, char **envp)
{
	int		*fds;

	if (argc != 5)
	{
		ft_printf_fd(STDERR_FILENO, "Usage: ./pipex file1 cmd1 cmd2 file2\n");
		exit(EC_ERROR);
	}
	fds = NULL;
	pipex->argc = argc;
	pipex->argv = argv;
	pipex->envp = envp;
	pipex->path = get_env_path(envp);
	pipex->infile = argv[1];
	pipex->outfile = argv[argc - 1];
	pipex->outfile_flag = O_CREAT | O_TRUNC | O_WRONLY;
	pipex->first_command_pos = 2;
	return (fds);
}
