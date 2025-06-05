/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:39:34 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/03/08 00:09:41 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	*init(t_pipex *pipex, int argc, char **argv, char **envp)
{
	int		*fds;

	if (argc < 5 || (argc == 5 && ft_str_equals(argv[1], "here_doc")))
	{
		ft_printf_fd(STDERR_FILENO,
			"Usage: ./pipex file1 cmd1 ... cmdn file2\n");
		ft_printf_fd(STDERR_FILENO,
			"Usage: ./pipex here_doc LIMITER cmd1 ... cmdn file\n");
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
	if (ft_str_equals(argv[1], "here_doc"))
		fds = here_doc(pipex);
	return (fds);
}
