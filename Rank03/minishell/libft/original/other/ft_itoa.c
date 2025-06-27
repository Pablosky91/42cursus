/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 21:45:12 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/18 16:13:17 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	save_number(char *number, int n, int len);
static int	nbrlen(int n);

/*
Allocates (with malloc(3)) and returns a string
	representing the integer received as an argument.
Negative numbers must be handled.
*/
char	*ft_itoa(int n)
{
	char	*number;
	int		len;

	len = nbrlen(n);
	number = ft_calloc(len + 1, sizeof(char));
	if (!number)
		return (0);
	save_number(number, n, len);
	return (number);
}

static void	save_number(char *number, int n, int len)
{
	int	sign;

	sign = 1;
	if (!n)
		number[0] = '0';
	else if (n < 0)
	{
		number[0] = '-';
		sign = -1;
	}
	while (n)
	{
		len--;
		number[len] = ((n % 10) * sign) + '0';
		n /= 10;
	}
}

static int	nbrlen(int n)
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
