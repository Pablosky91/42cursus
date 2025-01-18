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

int	main(int argc, char **argv, char **envp)
{
	char	*file1;
	char	**cmd1;
	char	**cmd2;
	char	*file2;
	int		fds[2];
	pid_t	pid1;
	pid_t	pid2;
	int		infile_fd;
	int		outfile_fd;
	char	*path1;
	char	*path2;

	if (argc != 5)
	{
		ft_putendl_fd("Usage: ./pipex file1 cmd1 cmd2 file2", 2);
		exit(1);
	}
	path1 = NULL;
	path2 = NULL;
	file1 = argv[1];
	cmd1 = ft_split(argv[2], ' ');
	cmd2 = ft_split(argv[3], ' ');
	file2 = argv[4];
	pipe(fds);
	pid1 = fork();
	if (pid1 == 0) // first child
	{
		infile_fd = open(file1, O_RDONLY);
		dup2(infile_fd, STDIN_FILENO);
		dup2(fds[1], STDOUT_FILENO);
		close(fds[0]);
		close(fds[1]);
		close(infile_fd);
		path1 = ft_strjoin("/usr/bin/", cmd1[0]);
		execve(path1, cmd1, envp);
	}
	else if (pid1 > 0) // first parent
	{
		pid2 = fork();
		if (pid2 == 0) // second child
		{
			outfile_fd = open(file2, O_CREAT | O_TRUNC | O_WRONLY, 0644);
			dup2(fds[0], STDIN_FILENO);
			dup2(outfile_fd, STDOUT_FILENO);
			close(fds[0]);
			close(fds[1]);
			close(outfile_fd);
			path2 = ft_strjoin("/usr/bin/", cmd2[0]);
			execve(path2, cmd2, envp);
		}
		else if (pid2 > 0) //second parent
		{
			close(fds[0]);
			close(fds[1]);
			waitpid(pid1, NULL, 0);
			waitpid(pid2, NULL, 0);
		}
	}
	ft_free_double_pointer((void **) cmd1);
	ft_free_double_pointer((void **) cmd2);
	free(path1);
	free(path2);
}

//PROTECT SPLIT AND JOIN
//PROTECT FILE OPEN
//PROTECT DUP2
//CLOSE ALL FDS
//PROTECT EXECVE
//FREE ALL