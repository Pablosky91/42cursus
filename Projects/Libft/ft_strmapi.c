/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 21:45:20 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/02/01 20:35:47 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Applies the function ’f’ to each character of the string ’s’,
	and passing its index as first argument to create a new string
	(with malloc(3)) resulting from successive applications of ’f’.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*copy;

	copy = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!copy)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		copy[i] = (char)f(i, s[i]);
		i++;
	}
	return (copy);
}
