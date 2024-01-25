/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:48:34 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/01/25 20:13:02 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_space(char c)
{
	if (c == ' ')
		return (1);
	if (c == '\t')
		return (1);
	if (c == '\n')
		return (1);
	if (c == '\v')
		return (1);
	if (c == '\f')
		return (1);
	if (c == '\r')
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

int	ft_atoi(const char *str)
{
	int	i;
	int	nbr;
	int	sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (is_space(str[i]) == 1)
		i++;
	if (is_operand(str[i]) != 0)
	{
		sign *= is_operand(str[i]);
		i++;
	}
	while (is_number(str[i]) != -1)
	{
		nbr *= 10;
		nbr += is_number(str[i]);
		i++;
	}
	return (nbr * sign);
}
