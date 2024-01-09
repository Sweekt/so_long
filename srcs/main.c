/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:23:59 by beroy             #+#    #+#             */
/*   Updated: 2024/01/09 14:55:06 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_map	map_info;
	t_mlx	mlx;
	t_data	img;

	if (argc != 2)
		return (write(1, "Map Input Error\n", 16), 0);
	map_info.map = map_parser(argv[1]);
	if (map_info.map == NULL)
		return (0);
	map_state_init(&map_info);
	if (map_checker(&map_info) == 1)
		return (write(1, "Invalid Map\n", 12), ft_splitdestroy(map_info.map), 0);
	mlx.mlx = mlx_init();
	if (mlx.mlx == NULL)
		return (MLX_ERROR);
	mlx.win = mlx_new_window(mlx.mlx, map_info.mapw * 32, map_info.maph * 32, "So loooooong");
	if (mlx.win == NULL)
	{
		free(mlx.win);
		return (MLX_ERROR);
	}
	map_gen(&mlx, map_info, &img);
	mlx_loop(mlx.mlx);
	return (0);
}