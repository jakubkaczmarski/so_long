/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 22:10:15 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/03/15 15:52:50 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 100
# endif

# include "MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <memory.h>
# include "ft_printf.h"
typedef struct s_array_thingy{
	char **arr;
	xpm_t	*xpm[6];
	mlx_t	*mlx;
	int		x;
	int		y;
	int		duck_count;
	int		score;
} t_arr;
char	*ft_itoa(int n);
size_t	strlen(const char *ch);
char	*get_next_line(int fd);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *ptr, int value, size_t num);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strrchr(const char *s, int c);



#endif