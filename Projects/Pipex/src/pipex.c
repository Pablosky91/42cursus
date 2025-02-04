/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:19:39 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/02/04 17:09:11 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	is_delimiter_line(char *delimiter, char *line)
{
	int	iter;

	iter = 0;
	while (delimiter[iter] && line[iter])
	{
		if (delimiter[iter] != line[iter])
			return (false);
		iter++;
	}
	return (!delimiter[iter] && line[iter] == '\n' && !line[iter + 1]);
}

//TODO investigate what happens if path is NULL
char	**get_path(char **envp)
{
	int		env_iter;
	char	**split;
	char	*substr;

	env_iter = -1;
	while (envp[++env_iter])
	{
		if (ft_strncmp(envp[env_iter], "PATH=", 5))
			continue ;
		substr = ft_substr(envp[env_iter], 5, ft_strlen(envp[env_iter]) - 5);
		//TODO protect malloc
		split = ft_split(substr, ':');
		//TODO protect malloc
		free(substr);
		return (split);
	}
	return (NULL);
}

char	*join_path(char *path, char *command)
{
	char		*path_command;
	size_t		len_path;
	size_t		len_command;
	size_t		aux;

	len_path = ft_strlen(path);
	len_command = ft_strlen(command);
	path_command = malloc(len_path + len_command + 2 * sizeof(char));
	if (!path_command)
		return (NULL);
	aux = -1;
	while (++aux < len_path)
		path_command[aux] = path[aux];
	path_command[aux] = '/';
	while (++aux < len_path + len_command + 1)
		path_command[aux] = command[aux - len_path - 1];
	path_command[aux] = 0;
	return (path_command);
}

//TODO investigate what happens if no command is found
char	*get_path_command(char **path, char *command)
{
	char	*path_command;
	int		path_iter;

	path_iter = -1;
	while (path[++path_iter])
	{
		path_command = join_path(path[path_iter], command);
		if (!path_command)
			return (NULL);
		if (!access(path_command, X_OK))
			return (path_command);
		free(path_command);
	}
	return (NULL);
}

bool	reads_from_infile(t_pipex pipex, int cmd_pos)
{
	return (cmd_pos == pipex.first_command_pos && pipex.infile);
}

bool	writes_to_outfile(t_pipex pipex, int cmd_pos)
{
	return (cmd_pos == pipex.argc - 2);
}

void	dup2_close(int fd1, int fd2)
{
	dup2(fd1, fd2);
	close(fd1);
}

void	child(t_pipex pipex, int cmd_pos, int *write_pipe, int *read_pipe)
{
	char	**cmd;
	int		infile_fd;
	int		outfile_fd;

	if (reads_from_infile(pipex, cmd_pos))
	{
		infile_fd = open(pipex.infile, O_RDONLY);
		dup2_close(infile_fd, STDIN_FILENO);
	}
	else
	{
		dup2_close(read_pipe[PIPE_READ], STDIN_FILENO);
		close(read_pipe[PIPE_WRITE]);
	}
	if (writes_to_outfile(pipex, cmd_pos))
	{
		outfile_fd = open(pipex.outfile, pipex.outfile_flag, 0644);
		dup2_close(outfile_fd, STDOUT_FILENO);
	}
	else
	{
		dup2_close(write_pipe[PIPE_WRITE], STDOUT_FILENO);
		close(write_pipe[PIPE_READ]);
	}
	cmd = ft_split(pipex.argv[cmd_pos], ' ');
	execve(get_path_command(pipex.path, cmd[0]), cmd, pipex.envp);
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

int	*here_doc(t_pipex *pipex)
{
	int		*fds;
	char	*line;
	bool	end;

	pipex->infile = NULL;
	pipex->outfile_flag = O_CREAT | O_APPEND | O_WRONLY;
	pipex->first_command_pos = 3;
	fds = malloc(2 * sizeof(int));
	end = false;
	pipe(fds);
	while (!end)
	{
		ft_printf("%s", PIPE_HEREDOC);
		line = get_next_line(STDIN_FILENO);
		end = !line || is_delimiter_line(pipex->argv[2], line);
		if (!end)
			write(fds[PIPE_WRITE], line, ft_strlen(line));
		free(line);
	}
	return (fds);
}

int	*init(t_pipex *pipex, int argc, char **argv, char **envp)
{
	int		*fds;

	fds = NULL;
	pipex->argc = argc;
	pipex->argv = argv;
	pipex->envp = envp;
	pipex->path = get_path(envp);
	pipex->infile = argv[1];
	pipex->outfile = argv[argc - 1];
	pipex->outfile_flag = O_CREAT | O_TRUNC | O_WRONLY;
	pipex->first_command_pos = 2;
	if (ft_str_equals(argv[1], HERE_DOC))
		fds = here_doc(pipex);
	return (fds);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		*fds;
	int		cmd_pos;

	if (argc < 5)
	{
		ft_putendl_fd("Usage: ./pipex file1 cmd1 cmd2 file2", 2);
		exit(1);
	}
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