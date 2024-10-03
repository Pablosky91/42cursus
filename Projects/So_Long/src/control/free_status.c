/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 10:49:46 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/03 10:51:46 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_status(t_status_node *status)
{
	status->next = NULL;
	free(status->fishes);
	free(status);
}
