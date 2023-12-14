/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:46:02 by beroy             #+#    #+#             */
/*   Updated: 2023/12/13 17:46:51 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int check_border(char **map)
{
	size_t	i;
	size_t	h;
	size_t	w;

	i = 0;
	w = ft_strlen(map[0]);
	while (map[h])
	{
		if (map[h][0] != '1' || map[h][w] != '1')
			return (1);
		l++;
	}
	while (map[0][i])
	{
		if (map[0][i] != '1' || map[h][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int check_shape(char **map)
{
	size_t	tmp;
	size_t	i;

	tmp = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) != tmp)
			return (1);
		i++;
	}
	return (0);
}

int	map_checker(char **map)
{
	if (check_shape(map) == 1)
		return (1);
	if (check_border(map) == 1)
		return (1);
	if (solver_check(map) == 1)
		return (1);
}