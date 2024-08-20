/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_double_pointer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 21:38:15 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/08/20 21:39:45 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Frees the double pointer and each of their pointers.
Always returns false.
*/
bool	ft_free_double_pointer(void **double_pointer)
{
	__u_int i;

	i = 0;
	while (double_pointer[i])
		free(double_pointer[i++]);
	free(double_pointer);
	return (false);
}
