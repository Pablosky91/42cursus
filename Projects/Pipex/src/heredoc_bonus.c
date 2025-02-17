/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 21:46:25 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/02/17 15:58:07 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static bool	is_delimiter_line(char *delimiter, char *line);

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
		ft_printf("%s", "\e[1mpipe heredoc> \e[0m");
		line = ft_get_next_line(STDIN_FILENO);
		if (!line || is_delimiter_line(pipex->argv[2], line))
			end = true;
		if (!end)
			write(fds[PIPE_WRITE], line, ft_strlen(line));
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
