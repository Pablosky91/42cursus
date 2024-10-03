/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_logo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:05:41 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/03 15:06:02 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_logo(t_game *game)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("textures/logo.png");
	if (!texture)
		exit_game(game, _MLX_PNG);
	mlx_set_icon(game->mlx, texture);
	mlx_delete_texture(texture);
}
