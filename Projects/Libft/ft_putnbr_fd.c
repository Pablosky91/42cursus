/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 21:45:15 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/02/01 19:58:18 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putnbr_recursive(int n, int fd);

/*
Outputs the integer ’n’ to the given file descriptor.
*/
void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		ft_putchar_fd('0', fd);
	else if (n < 0)
		ft_putchar_fd('-', fd);
	putnbr_recursive(n, fd);
}

static void	putnbr_recursive(int n, int fd)
{
	int	sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	if (n != 0)
	{
		putnbr_recursive(n / 10, fd);
		ft_putchar_fd((n % 10) * sign + '0', fd);
	}
}
