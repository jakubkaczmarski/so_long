/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 22:10:15 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/03/15 18:35:40 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 1000
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
	mlx_image_t *img_arr[6];
} t_arr;
char	*ft_itoa(int n);
size_t	strlen(const char *ch);
char	*get_next_line(int fd);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *ptr, int value, size_t num);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strrchr(const char *s, int c);
int		check_lenght(char **arr);
void	init_text(t_arr *str_arr);
void	delete_img(t_arr *str_arr);
void	find_ducks(t_arr *str_arr);
void	find_goopher(t_arr *str_arr, int *x, int *y);
int		check_walls(char **arr);
int		check_if_right_characs(char **arr);
int		check_signs(char **arr, char symbol);
void	check_ducky(t_arr *str_arr);
void	exit_clean(t_arr *str_arr);
void	free_all(t_arr *str_arr);
int		error_check(t_arr *str_arr);
void	clean_textures(t_arr *str_arr);
int		count_lines(int fd);
void	move_hook(mlx_key_data_t key, void *param);
void	rewrite_map(t_arr *str_arr);
#endif