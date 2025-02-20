/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 21:46:36 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/02/20 17:45:22 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_child(t_pipex pipex, int *write_pipe, int *read_pipe, char *msg)
{
	ft_free_double_pointer((void **)pipex.path);
	free(write_pipe);
	free(read_pipe);
	ft_printf_fd(STDERR_FILENO, "Error\n");
	perror(msg);
	exit(1);
}

static bool	child_read(t_pipex pipex, int cmd_pos, int *read_pipe)
{
	int		infile_fd;

	if (reads_from_infile(pipex, cmd_pos))
	{
		infile_fd = open(pipex.infile, O_RDONLY);
		if (infile_fd < 0)
		{
			ft_printf_fd(STDERR_FILENO, "%s: No such file or directory\n", pipex.infile);
			return (false);
		}
		dup2(infile_fd, STDIN_FILENO);
		//TODO protect dup2
		close(infile_fd);
		//TODO protect close
	}
	else
	{
		dup2(read_pipe[PIPE_READ], STDIN_FILENO);
		//TODO protect dup2
		close(read_pipe[PIPE_READ]);
		//TODO protect close
		close(read_pipe[PIPE_WRITE]);
		//TODO protect close
	}
	return (true);
}

static bool	child_write(t_pipex pipex, int cmd_pos, int *write_pipe)
{
	int		outfile_fd;

	if (writes_to_outfile(pipex, cmd_pos))
	{
		outfile_fd = open(pipex.outfile, pipex.outfile_flag, 0644);
		if (outfile_fd < 0)
		{
			ft_printf_fd(STDERR_FILENO, "%s: No such file or directory\n", pipex.infile);
			return (false);
		}
		dup2(outfile_fd, STDOUT_FILENO);
		//TODO protect dup2
		close(outfile_fd);
		//TODO protect close
	}
	else
	{
		dup2(write_pipe[PIPE_WRITE], STDOUT_FILENO);
		//TODO protect dup2
		close(write_pipe[PIPE_WRITE]);
		//TODO protect close
		close(write_pipe[PIPE_READ]);
		//TODO protect close
	}
	return (true);
}

static void	child(t_pipex pipex, int cmd_pos, int *write_pipe, int *read_pipe)
{
	char		**cmd;
	char		*cmd_path;
	t_exit_code	exit_value;

	if (!child_read(pipex, cmd_pos, read_pipe))
		free_child(pipex, write_pipe, read_pipe, "Read");
	if (!child_write(pipex, cmd_pos, write_pipe))
		free_child(pipex, write_pipe, read_pipe, "Write");
	cmd = ft_split(pipex.argv[cmd_pos], ' ');
	//TODO protect malloc
	exit_value = get_command(pipex.path, cmd[0], &cmd_path);
	//TODO protect malloc
	if (exit_value == EC_SUCCESS)
		execve(cmd_path, cmd, pipex.envp);
	if (exit_value == EC_COMMAND_NOT_EXECUTABLE)
	{
		ft_printf_fd(STDERR_FILENO, "%s: Permission denied\n", cmd_path);
		free(cmd_path);
	}
	if (exit_value == EC_COMMAND_NOT_FOUND)
		ft_printf_fd(STDERR_FILENO, "%s: command not found\n", cmd[0]);
	ft_free_double_pointer((void **)cmd);
	exit(exit_value);
}

int	*process_command(t_pipex pipex, int cmd_pos, int *read_pipe, pid_t *last_child)
{
	int		*write_pipe;
	pid_t	pid;

	write_pipe = NULL;
	if (!writes_to_outfile(pipex, cmd_pos))
	{
		write_pipe = malloc(2 * sizeof(int));
		//TODO protect malloc
		pipe(write_pipe);
		//TODO protect pipe
	}
	pid = fork();
	//TODO protect fork
	//if (pid == -1)
	// 	free_child(pipex, write_pipe, read_pipe, "Fork");
	if (pid == 0)
		child(pipex, cmd_pos, write_pipe, read_pipe);
	*last_child = pid;
	if (!reads_from_infile(pipex, cmd_pos))
	{
		close(read_pipe[PIPE_WRITE]);
		//TODO protect close
		close(read_pipe[PIPE_READ]);
		//TODO protect close
		free(read_pipe);
	}
	return (write_pipe);
}
