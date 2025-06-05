/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:08:22 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/03/07 19:53:37 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_and_free_pipe(int *pipe)
{
	if (!pipe)
		return ;
	close(pipe[PIPE_WRITE]);
	close(pipe[PIPE_READ]);
	free(pipe);
	pipe = NULL;
}

void	error_processing_command(t_pipex pipex,
	int *write_pipe, int *read_pipe, t_exit_code exit_code)
{
	close_and_free_pipe(write_pipe);
	close_and_free_pipe(read_pipe);
	ft_free_double_pointer((void **)pipex.path);
	exit(exit_code);
}

bool	reads_from_infile(t_pipex pipex, int cmd_pos)
{
	return (cmd_pos == pipex.first_command_pos && pipex.infile);
}

bool	writes_to_outfile(t_pipex pipex, int cmd_pos)
{
	return (cmd_pos == pipex.argc - 2);
}
