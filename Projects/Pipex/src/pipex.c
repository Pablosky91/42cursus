/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:19:39 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/02/17 15:40:45 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		*fds;
	int		cmd_pos;

	fds = init(&pipex, argc, argv, envp);
	cmd_pos = pipex.first_command_pos;
	while (cmd_pos < argc - 1)
		fds = execute_command(pipex, cmd_pos++, fds);
	while (wait(NULL) != -1)
		;
	ft_free_double_pointer((void **) pipex.path);
}

//PROTECT SPLIT AND JOIN
//PROTECT FILE OPEN
//PROTECT DUP2
//CLOSE ALL FDS
//PROTECT EXECVE
//FREE ALL