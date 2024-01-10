/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:23:59 by beroy             #+#    #+#             */
/*   Updated: 2024/01/10 16:47:59 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_win(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	ft_splitdestroy(mlx->map_info->map);
	exit(EXIT_SUCCESS);
}

int key_input(int keycode, t_mlx *mlx)
{
	if (keycode == 65307)
		close_win(mlx);
	else if (keycode == 119) //W
		move_up(mlx->map_info);
	else if (keycode == 97) //A
		move_left(mlx->map_info);
	else if (keycode == 115) //S
		move_down(mlx->map_info);
	else if (keycode == 100) //D
		move_right(mlx->map_info);
	if (mlx->map_info->ecount == 1)
		map_gen(mlx, mlx->map_info, mlx->img);
	else
		close_win(mlx);
	return (0);
}

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
	mlx.map_info = &map_info;
	mlx.img = &img;
	map_gen(&mlx, &map_info, &img);
	mlx_hook(mlx.win, 17, 1L<<0, close_win, &mlx);
	mlx_hook(mlx.win, 2, 1L<<0, key_input, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}