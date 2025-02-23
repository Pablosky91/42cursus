/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:19:39 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/02/20 17:50:44 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		*fds;
	int		cmd_pos;
	pid_t	last_child;

	fds = init(&pipex, argc, argv, envp);
	cmd_pos = pipex.first_command_pos;
	while (cmd_pos < argc - 1)
		fds = process_command(pipex, cmd_pos++, fds, &last_child);
	return (exit_pipex(pipex, last_child));
}

//PROTECT SPLIT AND JOIN
//PROTECT FILE OPEN
//PROTECT DUP2
//CLOSE ALL FDS
//PROTECT EXECVE
//FREE ALL