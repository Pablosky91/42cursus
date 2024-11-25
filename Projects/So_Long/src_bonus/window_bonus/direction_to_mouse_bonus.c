/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_to_mouse_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:59:07 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/11/22 18:35:20 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_direction	direction_to_mouse(t_game *game)
{
	int32_t	mouse_x;
	int32_t	mouse_y;
	double	diff_x;
	double	diff_y;
	bool	vertical;

	mlx_get_mouse_pos(game->mlx, &mouse_x, &mouse_y);
	diff_x = mouse_x - game->penguin->x - game->img_size / 2;
	diff_y = mouse_y - game->penguin->y - game->img_size / 2;
	vertical = fabs(diff_x) < fabs(diff_y);
	if (vertical && diff_y <= 0)
		return (NORTH);
	else if (vertical)
		return (SOUTH);
	else if (diff_x <= 0)
		return (WEST);
	else
		return (EAST);
}
