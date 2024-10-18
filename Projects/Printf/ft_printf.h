/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:14:16 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/18 16:13:17 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

# define STDOUT 1
# define HEX_UPPER "0123456789ABCDEF"
# define HEX_LOWER "0123456789abcdef"
# define PRINT_NULL "(null)"
# define PRINTF_SPECIFIER '%'

int	ft_print_char(char c);
int	ft_print_flag(char flag, va_list args);
int	ft_print_hexadecimal(size_t hex, char *letter_case);
int	ft_print_int(int nbr);
int	ft_print_pointer(size_t p);
int	ft_print_string(char *str);
int	ft_print_unsigned_int(unsigned int nbr);
int	ft_print(char c);
int	ft_printf(const char *format, ...);

#endif