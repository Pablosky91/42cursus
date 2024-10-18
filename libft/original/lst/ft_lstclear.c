/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 21:34:52 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/18 16:13:17 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	lstdel_recursive(t_list *lst, void (*del)(void *));

/*
Deletes and frees the given node and every successor
	of that node, using the function ’del’ and free(3).
Finally, the pointer to the list must be set to NULL.
*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	lstdel_recursive(*lst, del);
	*lst = 0;
}

static void	lstdel_recursive(t_list *node, void (*del)(void *))
{
	if (!node)
		return ;
	lstdel_recursive(node->next, del);
	ft_lstdelone(node, del);
}
