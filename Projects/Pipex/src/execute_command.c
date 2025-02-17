/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 21:46:36 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/02/17 15:53:58 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_read(t_pipex pipex, int cmd_pos, int *read_pipe)
{
	int		infile_fd;

	if (reads_from_infile(pipex, cmd_pos))
	{
		infile_fd = open(pipex.infile, O_RDONLY);
		if (infile_fd < 0)
			exit(0);
		dup2(infile_fd, STDIN_FILENO);
		close(infile_fd);
	}
	else
	{
		dup2(read_pipe[PIPE_READ], STDIN_FILENO);
		close(read_pipe[PIPE_READ]);
		close(read_pipe[PIPE_WRITE]);
	}
}

static void	child_write(t_pipex pipex, int cmd_pos, int *write_pipe)
{
	int		outfile_fd;

	if (writes_to_outfile(pipex, cmd_pos))
	{
		outfile_fd = open(pipex.outfile, pipex.outfile_flag, 0644);
		dup2(outfile_fd, STDOUT_FILENO);
		close(outfile_fd);
	}
	else
	{
		dup2(write_pipe[PIPE_WRITE], STDOUT_FILENO);
		close(write_pipe[PIPE_WRITE]);
		close(write_pipe[PIPE_READ]);
	}
}

static void	child(t_pipex pipex, int cmd_pos, int *write_pipe, int *read_pipe)
{
	char	**cmd;

	child_read(pipex, cmd_pos, read_pipe);
	child_write(pipex, cmd_pos, write_pipe);
	cmd = ft_split(pipex.argv[cmd_pos], ' ');
	execve(get_command(pipex.path, cmd[0]), cmd, pipex.envp);
	perror(cmd[0]);
	exit(0);
}

int	*execute_command(t_pipex pipex, int cmd_pos, int *read_pipe)
{
	int		*write_pipe;
	pid_t	pid;

	write_pipe = NULL;
	if (!writes_to_outfile(pipex, cmd_pos))
	{
		write_pipe = malloc(2 * sizeof(int));
		pipe(write_pipe);
	}
	pid = fork();
	if (pid == 0)
		child(pipex, cmd_pos, write_pipe, read_pipe);
	if (!reads_from_infile(pipex, cmd_pos))
	{
		close(read_pipe[PIPE_WRITE]);
		close(read_pipe[PIPE_READ]);
		free(read_pipe);
	}
	return (write_pipe);
}
