/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:26:30 by beroy             #+#    #+#             */
/*   Updated: 2023/12/18 16:35:47 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif
# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

# define MLX_ERROR 1
# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 600

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"

typedef struct s_map {
	char	**map;
	size_t	ccount;
	size_t	ecount;
	size_t	pcount;
	size_t	px;
	size_t	py;
} 				t_map;

char	*ft_strjoin(char *s1, char *s2);
char	**ft_tabdup(char **str);
void	*ft_calloc(size_t nmemb, size_t size);
char	**ft_split(char const *s, char c);
void	*ft_splitdestroy(char **split);
size_t	ft_strlen(char *str);

int		map_checker(t_map *map_info);
char	**map_parser(char *filename);
int 	solver_check(t_map *map_info);
void	map_state_init(t_map *map_info);

#endif