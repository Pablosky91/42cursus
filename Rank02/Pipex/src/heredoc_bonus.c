/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 21:46:25 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/03/06 21:23:49 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static bool	is_delimiter_line(char *delimiter, char *line);
static void	here_doc_error(t_pipex *pipex, int *fds);

int	*here_doc(t_pipex *pipex)
{
	int		*fds;
	char	*line;
	bool	end;

	pipex->infile = NULL;
	pipex->outfile_flag = O_CREAT | O_APPEND | O_WRONLY;
	pipex->first_command_pos = 3;
	fds = ft_calloc(2, sizeof(int));
	if (!fds)
		here_doc_error(pipex, fds);
	end = false;
	if (pipe(fds) == -1)
		here_doc_error(pipex, fds);
	while (!end)
	{
		ft_printf("%s", "> ");
		line = ft_get_next_line(STDIN_FILENO);
		if (!line || is_delimiter_line(pipex->argv[2], line))
			end = true;
		if (!end)
			ft_printf_fd(fds[PIPE_WRITE], "%s", line);
		free(line);
	}
	return (fds);
}

static bool	is_delimiter_line(char *delimiter, char *line)
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

static void	here_doc_error(t_pipex *pipex, int *fds)
{
	ft_free_double_pointer((void **)pipex->path);
	free(fds);
	exit(EC_ERROR);
}
