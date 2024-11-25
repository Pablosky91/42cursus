/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:57:18 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/18 16:13:17 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define LINE_LEN true
# define WHOLE_LEN false
# define TO_FREE true
# define NOT_TO_FREE false
# define MAX_FD 4096

char	*get_next_line(int fd);

char	*gnl_free_and_null(char **s);
char	*gnl_strjoin(char *s1, char *s2, size_t len);
size_t	gnl_strlen(char *s, int len_line);
char	*gnl_substr(char *s, size_t start, size_t len, int to_free);
void	gnl_init_empty_string(char **s);

#endif