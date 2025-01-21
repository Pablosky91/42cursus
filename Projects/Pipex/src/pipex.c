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

char *join_path(char *path, char *command)
{
	char	*path_command;
	size_t		len_path;
	size_t		len_command;
	size_t		aux;

	len_path = ft_strlen(path);
	len_command = ft_strlen(command);
	path_command = ft_calloc(len_path + len_command + 2, sizeof(char));
	if (!path_command)
		return (NULL);
	aux = -1;
	while (++aux < len_path)
		path_command[aux] = path[aux];
	path_command[aux] = '/';
	while (++aux < len_path + len_command + 1)
		path_command[aux] = command[aux - len_path - 1];
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

int	main(int argc, char **argv, char **envp)
{
	char	**path;
	char	*file1;
	char	**cmd1;
	char	**cmd2;
	char	**cmd3;
	char	*file2;
	int		fds_1[2];
	int		fds_2[2];
	pid_t	pid1;
	pid_t	pid2;
	pid_t	pid3;
	int		infile_fd;
	int		outfile_fd;

	path = get_path(envp);
	if (argc < 5)
	{
		ft_putendl_fd("Usage: ./pipex file1 cmd1 cmd2 file2", 2);
		exit(1);
	}
	file1 = argv[1];
	file2 = argv[argc - 1];
	pipe(fds_1);
	pid1 = fork();
	if (pid1 == 0) // first child
	{
		infile_fd = open(file1, O_RDONLY);
		dup2(infile_fd, STDIN_FILENO);
		dup2(fds_1[1], STDOUT_FILENO);
		close(fds_1[0]);
		close(fds_1[1]);
		close(infile_fd);
		cmd1 = ft_split(argv[2], ' ');
		execve(get_path_command(path, cmd1[0]), cmd1, envp);
	}
	else if (pid1 > 0) // first parent
	{
		pipe(fds_2);
		pid2 = fork();
		if (pid2 == 0) // second child
		{
			dup2(fds_1[0], STDIN_FILENO);
			dup2(fds_2[1], STDOUT_FILENO);
			close(fds_1[0]);
			close(fds_1[1]);
			cmd2 = ft_split(argv[3], ' ');
			execve(get_path_command(path, cmd2[0]), cmd2, envp);
		}
		else if (pid2 > 0) //second parent
		{
			close(fds_1[0]);
			close(fds_1[1]);
			pid3 = fork();
			if (pid3 == 0) // third child
			{
				outfile_fd = open(file2, O_CREAT | O_TRUNC | O_WRONLY, 0644);
				dup2(fds_2[0], STDIN_FILENO);
				dup2(outfile_fd, STDOUT_FILENO);
				close(fds_2[0]);
				close(fds_2[1]);
				close(outfile_fd);
				cmd3 = ft_split(argv[4], ' ');
				execve(get_path_command(path, cmd3[0]), cmd3, envp);
			}
			else if (pid3 > 0) //third parent
			{
				close(fds_2[0]);
				close(fds_2[1]);
				waitpid(pid1, NULL, 0);
				waitpid(pid2, NULL, 0);
				waitpid(pid3, NULL, 0);
			}
		}
	}
	ft_free_double_pointer((void **) path);
}

//PROTECT SPLIT AND JOIN
//PROTECT FILE OPEN
//PROTECT DUP2
//CLOSE ALL FDS
//PROTECT EXECVE
//FREE ALL