/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:17:59 by beroy             #+#    #+#             */
/*   Updated: 2024/01/10 17:24:05 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	asset_put(t_mlx *mlx, char c, t_data *img)
{
	if (c == '1')
		img->img = mlx_xpm_file_to_image(mlx->mlx, "assets/wall.xpm", &img->img_width, &img->img_height);
	if (c == '0')
		img->img = mlx_xpm_file_to_image(mlx->mlx, "assets/background.xpm", &img->img_width, &img->img_height);
	if (c == 'C')
		img->img = mlx_xpm_file_to_image(mlx->mlx, "assets/loot.xpm", &img->img_width, &img->img_height);
	if (c == 'P')
		img->img = mlx_xpm_file_to_image(mlx->mlx, "assets/player.xpm", &img->img_width, &img->img_height);
	if (c == 'E' && mlx->map_info->ccount != 0)
		img->img = mlx_xpm_file_to_image(mlx->mlx, "assets/exit.xpm", &img->img_width, &img->img_height);
	if (c == 'E' && mlx->map_info->ccount == 0)
		img->img = mlx_xpm_file_to_image(mlx->mlx, "assets/exit_o.xpm", &img->img_width, &img->img_height);
}

void	map_gen(t_mlx *mlx, t_map *map_info, t_data *img)
{
	size_t	w;
	size_t	h;

	h = 0;
	while (h < map_info->maph)
	{
		w = 0;
		while (w < map_info->mapw)
		{
			asset_put(mlx, map_info->map[h][w], img);
			mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, w * 32, h * 32);
			w++;
		}
		h++;
	}
}