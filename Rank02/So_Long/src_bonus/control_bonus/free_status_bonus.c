/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_status_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:26:37 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/18 16:13:24 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_status(t_status_node *status)
{
	status->next = NULL;
	free(status->fishes);
	free(status);
}
