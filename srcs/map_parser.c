/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:50:00 by beroy             #+#    #+#             */
/*   Updated: 2023/12/13 17:33:07 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
		return (NULL);
	rd = 1024;
	map_extract = 0;
	while (rd == 1024)
	{
		rd = read(fd, buff, 1024);
		if (rd < 0)
			return (close(fd), NULL);
		buff[1024] = 0;
		map_extract = ft_joinnfree(map_extract, buff);
		if (map_extract == NULL)
			return (close(fd), NULL);
	}
	close (fd);
	map = ft_split(map_extract, "\n");
	if (map == NULL)
		return (free(map_extract), NULL);
	free(map_extract);
	return (map);
}