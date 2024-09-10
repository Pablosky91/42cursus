/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:14:16 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/09/10 15:50:35 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

# define HEX_UPPER "0123456789ABCDEF"
# define HEX_LOWER "0123456789abcdef"
# define PRINT_NULL "(null)"
# define PRINTF_SPECIFIER '%'

int	ft_printf(const char *format, ...);

int	pf_print_char(char c);
int	pf_print_flag(char flag, va_list args);
int	pf_print_hexadecimal(size_t hex, char *letter_case);
int	pf_print_int(int nbr);
int	pf_print_pointer(size_t p);
int	pf_print_string(char *str);
int	pf_print_unsigned_int(unsigned int nbr);
int	pf_print(char c);

#endif