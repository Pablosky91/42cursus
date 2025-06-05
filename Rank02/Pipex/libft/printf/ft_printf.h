/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:14:16 by pdel-olm          #+#    #+#             */
/*   Updated: 2025/02/17 16:31:12 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

# define HEX_UPPER "0123456789ABCDEF"
# define HEX_LOWER "0123456789abcdef"
# define PRINT_NULL_STRING "(null)"
# define PRINT_NULL_POINTER "(nil)"
# define PRINTF_SPECIFIER '%'

int	ft_printf_fd(int fd, const char *format, ...);
int	ft_printf(const char *format, ...);

int	pf_print_char(int fd, char c);
int	pf_print_flag(int fd, char flag, va_list args);
int	pf_print_hexadecimal(int fd, size_t hex, char *letter_case);
int	pf_print_int(int fd, int nbr);
int	pf_print_pointer(int fd, size_t p);
int	pf_print_string(int fd, char *str);
int	pf_print_unsigned_int(int fd, unsigned int nbr);
int	pf_print(int fd, char c);

#endif