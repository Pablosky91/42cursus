/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:08:22 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/03/06 20:46:04 by pdel-olm         ###   ########.fr       */
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

bool	reads_from_infile(t_pipex pipex, int cmd_pos)
{
	return (cmd_pos == pipex.first_command_pos && pipex.infile);
}

bool	writes_to_outfile(t_pipex pipex, int cmd_pos)
{
	return (cmd_pos == pipex.argc - 2);
}
