/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:46:02 by beroy             #+#    #+#             */
/*   Updated: 2023/12/18 16:40:31 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_content(char **map)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (map[i])
	{
		j = 1;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0'
			&& map[i][j] != 'C' && map[i][j] != 'E'
			&& map[i][j] != 'P')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_border(char **map)
{
	size_t	i;
	size_t	h;
	size_t	w;

	i = 0;
	h = 0;
	w = ft_strlen(map[0]);
	while (map[h])
	{
		if (map[h][0] != '1' || map[h][w - 1] != '1')
			return (1);
		h++;
	}
	while (map[0][i])
	{
		if (map[0][i] != '1' || map[h - 1][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_shape(t_map *map_info)
{
	size_t	i;

	map_info->mapw = ft_strlen(map_info->map[0]);
	i = 0;
	while (map_info->map[i])
	{
		if (ft_strlen(map_info->map[i]) != map_info->mapw)
			return (1);
		i++;
	}
	map_info->maph = i;
	return (0);
}

int	map_checker(t_map *map_info)
{
	if (check_shape(map_info) == 1)
		return (1);
	write(1, "Shape OK!\n", 10);
	if (check_border(map_info->map) == 1)
		return (1);
	write(1, "Border OK!\n", 11);
	if (check_content(map_info->map) == 1)
		return (1);
	write(1, "Content OK!\n", 12);
	if (map_info->ecount != 1 || map_info->pcount != 1)
		return (1);
	write(1, "Count OK!\n", 10);
	if (solver_check(map_info) == 1)
		return (1);
	write(1, "Solve OK!\n", 10);
	return (0);
}
