/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:26:30 by beroy             #+#    #+#             */
/*   Updated: 2023/12/12 18:54:24 by beroy            ###   ########.fr       */
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
# include "mlx_linux/mlx.h"
# include "mlx_linux/mlx_int.h"
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strdup(char *str);
int		ft_linecheck(char *str);
char	*ft_strjoin(char *s1, char *s2);
void	ft_buffclean(char *str);

#endif