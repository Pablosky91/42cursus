/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:50:22 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/02/20 17:57:32 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exit_pipex(t_pipex pipex, pid_t last_child)
{
	int		status;
	int		exit_value;
	pid_t	pid;

	pid = 0;
	while (pid != -1)
	{
		pid = wait(&status);
		if (pid == last_child)
			exit_value = WEXITSTATUS(status);
	}
	ft_free_double_pointer((void **) pipex.path);
	return (exit_value);
}
