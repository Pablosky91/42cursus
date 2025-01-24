/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   pipex.c											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/01/16 12:19:39 by pdel-olm		  #+#	#+#			 */
/*   Updated: 2025/01/16 12:46:58 by pdel-olm		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "pipex.h"

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

bool	is_first_command(int n_cmd)
{
	return (n_cmd == 2);
}

bool	is_last_command(t_pipex pipex, int n_cmd)
{
	return (n_cmd == pipex.argc - 2);
}

void	dup2_close(int fd1, int fd2)
{
	dup2(fd1, fd2);
	close(fd1);
}

void	child(t_pipex pipex, int n_cmd, int *new_fds, int *old_fds)
{
	char	**cmd;
	int		infile_fd;
	int		outfile_fd;

	if (is_first_command(n_cmd))
	{
		infile_fd = open(pipex.argv[1], O_RDONLY);
		dup2_close(infile_fd, STDIN_FILENO);
	}
	else
	{
		dup2_close(old_fds[PIPE_READ], STDIN_FILENO);
		close(old_fds[PIPE_WRITE]);
	}
	if (is_last_command(pipex, n_cmd))
	{
		outfile_fd = open(pipex.argv[pipex.argc - 1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
		dup2_close(outfile_fd, STDOUT_FILENO);
	}
	else
	{
		dup2_close(new_fds[PIPE_WRITE], STDOUT_FILENO);
		close(new_fds[PIPE_READ]);
	}
	cmd = ft_split(pipex.argv[n_cmd], ' ');
	execve(get_path_command(pipex.path, cmd[0]), cmd, pipex.envp);
}

int	*execute_command(t_pipex pipex, int n_cmd, int *old_fds)
{
	int		*new_fds;
	pid_t	pid;

	new_fds = NULL;
	if (!is_last_command(pipex, n_cmd))
	{
		new_fds = malloc(2 * sizeof(int));
		pipe(new_fds);
	}
	pid = fork();
	if (pid == 0)
		child(pipex, n_cmd, new_fds, old_fds);
	if (!is_first_command(n_cmd))
	{
		close(old_fds[PIPE_WRITE]);
		close(old_fds[PIPE_READ]);
	}
	free(old_fds);
	return (new_fds);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		n_cmd;
	int		*fds;

	if (argc < 5)
	{
		ft_putendl_fd("Usage: ./pipex file1 cmd1 cmd2 file2", 2);
		exit(1);
	}
	pipex.argv = argv;
	pipex.argc = argc;
	pipex.envp = envp;
	pipex.path = get_path(envp);
	n_cmd = 1;
	fds = NULL;
	while (++n_cmd < argc - 1)
		fds = execute_command(pipex, n_cmd, fds);
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