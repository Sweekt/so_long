/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_wasd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:07:52 by beroy             #+#    #+#             */
/*   Updated: 2024/01/11 12:10:20 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_map *map_info)
{
	char	tmp;

	tmp = map_info->map[map_info->px - 1][map_info->py];
	if (tmp == '1')
		return ;
	else
	{
		map_info->map[map_info->px - 1][map_info->py] = 'P';
		if (map_info->estate == 1)
		{
			map_info->map[map_info->px][map_info->py] = 'E';
			map_info->estate = 0;
		}
		else
			map_info->map[map_info->px][map_info->py] = '0';
		map_info->px -= 1;
		if (tmp == 'C')
			map_info->ccount -= 1;
		else if (tmp == 'E' && map_info->ccount == 0)
			map_info->ecount -= 1;
		else if (tmp == 'E' && map_info->ccount != 0)
			map_info->estate = 1;
	}
	map_info->moves += 1;
}

void	move_left(t_map *map_info)
{
	char	tmp;

	tmp = map_info->map[map_info->px][map_info->py - 1];
	if (tmp == '1')
		return ;
	else
	{
		map_info->map[map_info->px][map_info->py - 1] = 'P';
		if (map_info->estate == 1)
		{
			map_info->map[map_info->px][map_info->py] = 'E';
			map_info->estate = 0;
		}
		else
			map_info->map[map_info->px][map_info->py] = '0';
		map_info->py -= 1;
		if (tmp == 'C')
			map_info->ccount -= 1;
		else if (tmp == 'E' && map_info->ccount == 0)
			map_info->ecount -= 1;
		else if (tmp == 'E' && map_info->ccount != 0)
			map_info->estate = 1;
	}
	map_info->moves += 1;
}

void	move_down(t_map *map_info)
{
	char	tmp;

	tmp = map_info->map[map_info->px + 1][map_info->py];
	if (tmp == '1')
		return ;
	else
	{
		map_info->map[map_info->px + 1][map_info->py] = 'P';
		if (map_info->estate == 1)
		{
			map_info->map[map_info->px][map_info->py] = 'E';
			map_info->estate = 0;
		}
		else
			map_info->map[map_info->px][map_info->py] = '0';
		map_info->px += 1;
		if (tmp == 'C')
			map_info->ccount -= 1;
		else if (tmp == 'E' && map_info->ccount == 0)
			map_info->ecount -= 1;
		else if (tmp == 'E' && map_info->ccount != 0)
			map_info->estate = 1;
	}
	map_info->moves += 1;
}

void	move_right(t_map *map_info)
{
	char	tmp;

	tmp = map_info->map[map_info->px][map_info->py + 1];
	if (tmp == '1')
		return ;
	else
	{
		map_info->map[map_info->px][map_info->py + 1] = 'P';
		if (map_info->estate == 1)
		{
			map_info->map[map_info->px][map_info->py] = 'E';
			map_info->estate = 0;
		}
		else
			map_info->map[map_info->px][map_info->py] = '0';
		map_info->py += 1;
		if (tmp == 'C')
			map_info->ccount -= 1;
		else if (tmp == 'E' && map_info->ccount == 0)
			map_info->ecount -= 1;
		else if (tmp == 'E' && map_info->ccount != 0)
			map_info->estate = 1;
	}
	map_info->moves += 1;
}
