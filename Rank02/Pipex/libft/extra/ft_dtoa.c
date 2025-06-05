/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:11:44 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/11/25 22:49:35 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	save_integer_part(char *number, double n, int len);
static void	save_decimal_part(char *number, double n, int len, int decimals);
static int	integer_len(double n);

/*
Allocates (with malloc(3)) and returns a string
	representing the double received as an argument
	with the decimal figures received as an argument.
*/
char	*ft_dtoa(double n, int decimals)
{
	char	*number;
	int		len;

	if (decimals <= 0)
		return (ft_itoa(n));
	len = integer_len(n);
	number = ft_calloc(len + 1 + decimals + 1, sizeof(char));
	if (!number)
		return (0);
	save_integer_part(number, n, len);
	save_decimal_part(number, n, len, decimals);
	return (number);
}

static void	save_decimal_part(char *number, double n, int len, int decimals)
{
	int	sign;
	int	iter;

	sign = 1;
	if (n < 0)
		sign = -1;
	number[len] = '.';
	iter = 1;
	while (iter <= decimals)
	{
		n *= 10;
		number[len + iter] = (((int) n) % 10 * sign) + '0';
		iter++;
	}
}

static void	save_integer_part(char *number, double n, int len)
{
	int	sign;
	int	integer;

	sign = 1;
	integer = n;
	if (!integer)
		number[0] = '0';
	else if (integer < 0)
	{
		number[0] = '-';
		sign = -1;
	}
	while (integer)
	{
		len--;
		number[len] = ((integer % 10) * sign) + '0';
		integer /= 10;
	}
}

static int	integer_len(double n)
{
	int	len;

	len = 1;
	if (n < 0)
		len++;
	while (n >= 10 || n <= -10)
	{
		n /= 10;
		len++;
	}
	return (len);
}
