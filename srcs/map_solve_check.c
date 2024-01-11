/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_solve_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:04:31 by beroy             #+#    #+#             */
/*   Updated: 2024/01/11 14:09:58 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	fill_checker(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	map_filler(char **map, size_t x, size_t y)
{
	if (map[x][y] != '1' && map[x][y] != 'O')
	{
		map[x][y] = 'O';
		map_filler(map, x - 1, y);
		map_filler(map, x + 1, y);
		map_filler(map, x, y - 1);
		map_filler(map, x, y + 1);
	}
}

int	solver_check(t_map *map_info)
{
	char	**map_clone;

	map_clone = ft_tabdup(map_info->map);
	if (map_clone == NULL)
		return (1);
	map_filler(map_clone, map_info->px, map_info->py);
	if (fill_checker(map_clone) == 1)
		return (ft_splitdestroy(map_clone), 1);
	ft_splitdestroy(map_clone);
	return (0);
}
