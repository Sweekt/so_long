/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:50:00 by beroy             #+#    #+#             */
/*   Updated: 2024/01/10 15:44:40 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_state_init(t_map *map_info)
{
	size_t	i;
	size_t	j;

	map_info->ccount = 0;
	map_info->ecount = 0;
	map_info->pcount = 0;
	map_info->estate = 0;
	i = 0;
	while (map_info->map[i])
	{
		j = 0;
		while (map_info->map[i][j])
		{
			if (map_info->map[i][j] == 'C')
				map_info->ccount++;
			else if (map_info->map[i][j] == 'E')
				map_info->ecount++;
			else if (map_info->map[i][j] == 'P')
			{
				map_info->px = i;
				map_info->py = j;
				map_info->pcount++;
			}
			j++;
		}
		i++;
	}
}

char	*ft_joinnfree(char *map, char *buff)
{
	char	*tmp;

	tmp = ft_strjoin(map, buff);
	free(map);
	return (tmp);
}

char	**map_parser(char *filename)
{
	int 	fd;
	int 	rd;
	char	buff[1025];
	char	*map_extract;
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (close(fd), NULL);
	rd = 1024;
	map_extract = ft_calloc(sizeof(char), 1);
	if (map_extract == NULL)
		return (close(fd), NULL);
	while (rd == 1024)
	{
		rd = read(fd, buff, 1024);
		if (rd < 0)
			return (free(map_extract), close(fd), NULL);
		buff[rd] = 0;
		map_extract = ft_joinnfree(map_extract, buff);
		if (map_extract == NULL)
			return (close(fd), NULL);
	}
	close (fd);
	map = ft_split(map_extract, '\n');
	/*if (map == NULL)
		return (free(map_extract), NULL);*/
	return (free(map_extract), map);
}
