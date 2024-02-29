/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:51:26 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/01/26 23:13:33 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Tests for an ASCII character, which is any character
	between 0 and octal 0177 inclusive.
*/
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
