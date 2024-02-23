/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:14:16 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/02/23 18:51:02 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft/libft.h"
#include <stdarg.h>

int ft_print_string(char *str);
int	ft_print(char c);
int	ft_print_flag(char flag, va_list args);
int	ft_printf(const char *format, ...);

#endif