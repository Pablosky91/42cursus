/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:15:29 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/08/29 16:59:30 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTRA_H
# define EXTRA_H

# include "libft.h"

size_t	ft_count_char(char *s, int c);
bool	ft_free_double_pointer(void **double_pointer);
int		ft_get_max(int a, int b);
int		ft_get_min(int a, int b);
bool	ft_str_equals(char *s1, char *s2);

#endif