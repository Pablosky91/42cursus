/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:04:38 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/03 15:05:01 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_window(t_game *game)
{
	int32_t	width;
	int32_t	height;
	mlx_t	*mlx;

	mlx_set_setting(MLX_HEADLESS, true);
	mlx = mlx_init(1, 1, WINDOW_TITLE, false);
	if (!mlx)
		exit_game(game, _MLX_INIT);
	mlx_get_monitor_size(0, &width, &height);
	mlx_terminate(mlx);
	mlx_set_setting(MLX_HEADLESS, false);
	game->img_size = ft_get_min ((width * 95 / 100) / game->map->width,
			(height * 95 / 100) / game->map->height);
	game->speed = game->img_size / 8;
	game->mlx = mlx_init(game->map->width * game->img_size,
			game->map->height * game->img_size, WINDOW_TITLE, false);
	if (!game->mlx)
		exit_game(game, _MLX_INIT);
}
