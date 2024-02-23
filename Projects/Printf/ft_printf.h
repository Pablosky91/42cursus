/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:14:16 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/02/24 00:01:08 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

# define STDOUT 1
# define IS_UPPER 0
# define IS_LOWER 32
# define PRINT_NULL "(null)"
# define PRINTF_SPECIFIER '%'

int	ft_print_string(char *str);
int	ft_print(char c);
int	ft_print_char(char c);
int	ft_print_flag(char flag, va_list args);
int	ft_printf(const char *format, ...);

#endif