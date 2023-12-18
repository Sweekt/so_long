/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:23:59 by beroy             #+#    #+#             */
/*   Updated: 2023/12/18 16:38:52 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*int main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (MLX_ERROR);
	win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");
	if (win_ptr == NULL)
	{
		free(win_ptr);
		return (MLX_ERROR);
	}
	while (1)
		;
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}*/

int	main(int argc, char **argv)
{
	t_map	map_info;

	if (argc != 2)
		return (write(1, "Map Input Error\n", 16), 0);
	map_info.map = map_parser(argv[1]);
	if (map_info.map == NULL)
		return (0);
	write(1, "Parsing OK!\n", 12);
	map_state_init(&map_info);
	write(1, "Struct init OK!\n", 16);
	if (map_checker(&map_info) == 1)
		return (write(1, "Invalid Map\n", 12), ft_splitdestroy(map_info.map), 0);
	return (0);
}