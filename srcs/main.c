/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:23:59 by beroy             #+#    #+#             */
/*   Updated: 2023/12/18 16:41:53 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_map	map_info;
	void	*mlx_ptr;
	void	*win_ptr;

	if (argc != 2)
		return (write(1, "Map Input Error\n", 16), 0);
	map_info.map = map_parser(argv[1]);
	if (map_info.map == NULL)
		return (0);
	map_state_init(&map_info);
	if (map_checker(&map_info) == 1)
		return (write(1, "Invalid Map\n", 12), ft_splitdestroy(map_info.map), 0);
	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (MLX_ERROR);
	win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "So loooooong");
	if (win_ptr == NULL)
	{
		free(win_ptr);
		return (MLX_ERROR);
	}
	mlx_loop(mlx_ptr);
	return (0);
}