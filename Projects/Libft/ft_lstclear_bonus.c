/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 21:34:52 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/02/08 18:35:55 by pdel-olm         ###   ########.fr       */
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
	lstdel_recursive(*lst, del);
	*lst = 0;
}

static void	lstdel_recursive(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	lstdel_recursive(lst->next, del);
	ft_lstdelone(lst, del);
}
