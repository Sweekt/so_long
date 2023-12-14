/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_solve_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:04:31 by beroy             #+#    #+#             */
/*   Updated: 2023/12/14 18:40:53 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int fill_checker(char **map)
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
	if (map[x][y] != '1')
	{
		map[x][y] = 'O';
		map_filler(map, x - 1, y);
		map_filler(map, x + 1, y);
		map_filler(map, x, y - 1);
		map_filler(map, x, y + 1);
	}
}

int path_checker(char** map, size_t x, size_t y)
{
	char	**map_clone;

	map_clone = ft_tabdup(map);
	if (map_clone == NULL)
		return (1);
	map_filler(map_clone, x, y);
	if (fill_checker(map_clone) == 1)
		return (1);
	return (0);
}

int	solver_check(char **map)
{
	size_t	i;
	size_t	j;
	size_t	ecount;
	size_t	pcount;
	t_map	map_pos;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				ecount++;
			if (map[i][j] == 'P')
			{
				pcount++;
				map_pos.px = i;
				map_pos.py = j;
			}
			j++;
		}
		i++;
	}
	if (ecount != 1 || pcount != 1)
		return (1);
	if (path_checker(map, map_pos.px, map_pos.py) == 1)
		return (1);
	return (0);
}
