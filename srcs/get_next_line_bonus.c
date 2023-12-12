/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:34:48 by beroy             #+#    #+#             */
/*   Updated: 2023/11/27 13:32:28 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_bzero(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
	{
		str[i] = 0;
		i++;
	}
}

char	*ft_line(int fd, int rd, char *line, char bf[OPEN_MAX][BUFFER_SIZE + 1])
{
	while (rd && ft_linecheck(line) == 0)
	{
		rd = read(fd, bf[fd], BUFFER_SIZE);
		if (rd < 0)
			return (ft_bzero(bf[fd]), free(line), NULL);
		bf[fd][rd] = 0;
		line = ft_strjoin(line, bf[fd]);
		if (line == NULL)
			return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buff[OPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			readed;

	readed = 1;
	if (fd < 0)
		return (NULL);
	if (read(fd, NULL, 0) < 0)
		return (ft_bzero(buff[fd]), NULL);
	line = ft_strdup(buff[fd]);
	if (line == NULL)
		return (NULL);
	line = ft_line(fd, readed, line, buff);
	if (line == NULL)
		return (NULL);
	ft_buffclean(buff[fd]);
	if (line[0] == 0)
		return (free(line), NULL);
	return (line);
}
