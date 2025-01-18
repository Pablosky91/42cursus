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
	char	**cmd3;
	char	*file2;
	int		fds_1[2];
	int		fds_2[2];
	pid_t	pid1;
	pid_t	pid2;
	pid_t	pid3;
	int		infile_fd;
	int		outfile_fd;
	char	*path1;
	char	*path2;
	char	*path3;

	if (argc < 5)
	{
		ft_putendl_fd("Usage: ./pipex file1 cmd1 cmd2 file2", 2);
		exit(1);
	}
	path1 = NULL;
	path2 = NULL;
	path3 = NULL;
	file1 = argv[1];
	cmd1 = ft_split(argv[2], ' ');
	cmd2 = ft_split(argv[3], ' ');
	cmd3 = ft_split(argv[4], ' ');
	file2 = argv[5];
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
		path1 = ft_strjoin("/usr/bin/", cmd1[0]);
		execve(path1, cmd1, envp);
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
			path2 = ft_strjoin("/usr/bin/", cmd2[0]);
			execve(path2, cmd2, envp);

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
				path3 = ft_strjoin("/usr/bin/", cmd3[0]);
				execve(path3, cmd3, envp);
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
	ft_free_double_pointer((void **) cmd1);
	ft_free_double_pointer((void **) cmd2);
	ft_free_double_pointer((void **) cmd3);
	free(path1);
	free(path2);
	free(path3);
}

//PROTECT SPLIT AND JOIN
//PROTECT FILE OPEN
//PROTECT DUP2
//CLOSE ALL FDS
//PROTECT EXECVE
//FREE ALL