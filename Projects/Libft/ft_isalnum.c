/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:48:45 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/01/26 23:09:29 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Tests for any character for which isalpha(3) or isdigit(3) is true.
*/
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
