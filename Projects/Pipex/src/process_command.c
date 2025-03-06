/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 21:46:36 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/03/06 21:29:48 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	error(t_pipex pipex, int *write_pipe, int *read_pipe, t_exit_code exit_code)
{
	close_and_free_pipe(write_pipe);
	close_and_free_pipe(read_pipe);
	ft_free_double_pointer((void **)pipex.path);
	exit(exit_code);
}

static bool	child_read(t_pipex pipex, int cmd_pos, int *read_pipe)
{
	int	infile_fd;
	int	error_sum;

	error_sum = 0;
	if (reads_from_infile(pipex, cmd_pos))
	{
		infile_fd = open(pipex.infile, O_RDONLY);
		if (infile_fd < 0)
		{
			perror(pipex.infile);
			error_sum += -1;
		}
		if (dup2(infile_fd, STDIN_FILENO) < 0)
			error_sum += -1;
		error_sum += close(infile_fd);
	}
	else
	{
		if (dup2(read_pipe[PIPE_READ], STDIN_FILENO) < 0)
			error_sum += -1;
		error_sum += close(read_pipe[PIPE_READ]);
		error_sum += close(read_pipe[PIPE_WRITE]);
	}
	return (error_sum == 0);
}

static bool	child_write(t_pipex pipex, int cmd_pos, int *write_pipe)
{
	int	outfile_fd;
	int	error_sum;

	error_sum = 0;
	if (writes_to_outfile(pipex, cmd_pos))
	{
		outfile_fd = open(pipex.outfile, pipex.outfile_flag, 0644);
		if (outfile_fd < 0)
		{
			perror(pipex.outfile);
			error_sum += -1;
		}
		if (dup2(outfile_fd, STDOUT_FILENO) < 0)
			error_sum += -1;
		error_sum += close(outfile_fd);
	}
	else
	{
		if (dup2(write_pipe[PIPE_WRITE], STDOUT_FILENO) < 0)
			error_sum += -1;
		error_sum += close(write_pipe[PIPE_WRITE]);
		error_sum += close(write_pipe[PIPE_READ]);
	}
	return (error_sum == 0);
}

static void	child(t_pipex pipex, int cmd_pos, int *write_pipe, int *read_pipe)
{
	char		**cmd;
	char		*cmd_path;
	t_exit_code	exit_value;

	cmd_path = NULL;
	if (!child_read(pipex, cmd_pos, read_pipe))
		error(pipex, write_pipe, read_pipe, EC_ERROR);
	if (!child_write(pipex, cmd_pos, write_pipe))
		error(pipex, write_pipe, read_pipe, EC_ERROR);
	cmd = ft_split(pipex.argv[cmd_pos], ' ');
	if (!cmd)
		error(pipex, write_pipe, read_pipe, EC_ERROR);
	exit_value = get_command(pipex.path, cmd[0], &cmd_path);
	if (exit_value == EC_SUCCESS)
		execve(cmd_path, cmd, pipex.envp);
	if (exit_value == EC_COMMAND_NOT_EXECUTABLE)
		ft_printf_fd(STDERR_FILENO, "%s: Permission denied\n", cmd_path);
	if (exit_value == EC_COMMAND_NOT_FOUND)
		ft_printf_fd(STDERR_FILENO, "%s: Command not found\n", cmd[0]);
	if (exit_value == EC_SUCCESS)
	{
		ft_printf_fd(STDERR_FILENO, "%s: Is a directory\n", cmd_path);
		exit_value = EC_COMMAND_NOT_EXECUTABLE;
	}
	if (exit_value == EC_FILE_NOT_FOUND)
	{
		ft_printf_fd(STDERR_FILENO, "%s: No such file or directory\n", cmd_path);
		exit_value = EC_COMMAND_NOT_FOUND;
	}
	free(cmd_path);
	ft_free_double_pointer((void **)cmd);
	error(pipex, write_pipe, read_pipe, exit_value);
}

int	*process_command(t_pipex pipex, int cmd_pos, int *read_pipe, pid_t *child_pid)
{
	int		*write_pipe;

	write_pipe = NULL;
	if (!writes_to_outfile(pipex, cmd_pos))
	{
		write_pipe = ft_calloc(2, sizeof(int));
		if (!write_pipe)
			error(pipex, write_pipe, read_pipe, EC_ERROR);
		if (pipe(write_pipe) == -1)
			error(pipex, write_pipe, read_pipe, EC_ERROR);
	}
	*child_pid = fork();
	if (*child_pid == -1)
		error(pipex, write_pipe, read_pipe, EC_ERROR);
	if (*child_pid == 0)
		child(pipex, cmd_pos, write_pipe, read_pipe);
	if (!reads_from_infile(pipex, cmd_pos))
		close_and_free_pipe(read_pipe);
	return (write_pipe);
}
