/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_no_nl.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:58:09 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/04/07 17:14:36 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	expand(char **str, char c);

/*
Returns the next line read from a file descriptor.
*/
char	*ft_get_next_line_no_nl(int fd)
{
	char	*line;
	char	*buffer;
	int		bytes_read;

	if (fd < 0)
		return (NULL);
	line = NULL;
	buffer = malloc(1 * sizeof(char));
	if (!buffer)
		return (NULL);
	while (true)
	{
		bytes_read = read(fd, buffer, 1);
		if (!bytes_read)
			break ;
		if (bytes_read < 0)
			return (free(buffer), free(line), NULL);
		expand(&line, buffer[0]);
		if (!line)
			return (free(buffer), NULL);
		if (buffer[0] == '\n')
			break ;
	}
	free(buffer);
	return (line);
}

static void	expand(char **str, char c)
{
	ssize_t	iter;
	ssize_t	len;
	char	*str2;

	if (c == '\n')
		c = '\0';
	iter = -1;
	len = 0;
	if (*str)
		len = ft_strlen(*str);
	str2 = malloc(len + 2);
	if (!str2)
		return ;
	while (++iter < len)
		str2[iter] = (*str)[iter];
	str2[iter] = c;
	str2[iter + 1] = 0;
	free(*str);
	*str = str2;
}
