/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:11:40 by beroy             #+#    #+#             */
/*   Updated: 2023/12/14 18:21:10 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_tablen(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	if (nmemb == 0 || size == 0)
	{
		ptr = malloc(nmemb * size);
		return (ptr);
	}
	if (nmemb > SIZE_MAX / size || size > SIZE_MAX / nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (ptr);
	i = 0;
	while (i < nmemb * size)
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

char	**ft_tabdup(char **str)
{
	size_t	i;
	size_t	j;
	char	**dup;

	dup = calloc(sizeof(char**) * (ft_tablen(map) + 1));
	if (dup == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		j = 0;
		dup[i] = calloc (sizeof(char) * (ft_strlen(str[i]) + 1));
		if (dup[i] == NULL)
			return (ft_splitdestroy(dup), NULL);
		while (str[i][j])
		{
			dup[i][j] = str[i][j];
			j++;
		}
		i++;
	}
	return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	size_t	i;
	size_t	j;

	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	i = 0;
	j = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		join[i + j] = s2[j];
		j++;
	}
	join[i + j] = 0;
	return (join);
}
