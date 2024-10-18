/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:48:34 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/18 16:13:17 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	is_space(char c);
static int	is_operand(char c);
static int	is_number(char c);

/*
Converts the initial portion of the string
	pointed to by str to int representation.
*/
int	ft_atoi(const char *str)
{
	int				i;
	long long int	nbr;
	long long int	cpy;
	int				sign;

	i = 0;
	nbr = 0;
	cpy = 0;
	sign = 1;
	while (is_space(str[i]))
		i++;
	if (is_operand(str[i]))
	{
		sign *= is_operand(str[i]);
		i++;
	}
	while (is_number(str[i]) != -1)
	{
		nbr = nbr * 10 + is_number(str[i]);
		if (cpy > nbr)
			return (((sign * -1) - 1) / 2);
		cpy = nbr;
		i++;
	}
	return (nbr * sign);
}

static int	is_space(char c)
{
	if (c == ' '
		|| c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

static int	is_operand(char c)
{
	if (c == '+')
		return (1);
	if (c == '-')
		return (-1);
	return (0);
}

static int	is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	return (-1);
}
