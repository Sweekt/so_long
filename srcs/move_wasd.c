/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_wasd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:07:52 by beroy             #+#    #+#             */
/*   Updated: 2024/01/09 17:07:52 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_map *map_info)
{
	if (map_info->map[map_info->px][map_info->py - 1] == '1')
		return ;
	if (map_info->map[map_info->px][map_info->py - 1] == '0')
	{
		map_info->map[map_info->px][map_info->py - 1] = 'P';
		map_info->map[map_info->px][map_info->py] = '0';
		map_info->py -= 1;
	}
	if (map_info->map[map_info->px][map_info->py - 1] == 'C')
	{
		map_info->map[map_info->px][map_info->py - 1] = 'P';
		map_info->map[map_info->px][map_info->py] = '0';
		map_info->py -= 1;
		map_info->ccount -= 1;
	}
	if (map_info->map[map_info->px][map_info->py - 1] == 'E' && map_info->ccount == 0)
	{
		map_info->map[map_info->px][map_info->py - 1] = 'P';
		map_info->map[map_info->px][map_info->py] = '0';
		map_info->py -= 1;
	}
}
