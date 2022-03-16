/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:02:29 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/03/16 15:34:19 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	rewrite_map(t_arr *str_arr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	str_arr->cords_y = 0;
	ft_printf("Score %d\n", str_arr->score);
	while (str_arr->arr[i])
	{
		j = 0;
		str_arr->cords_x = 0;
		while (str_arr->arr[i][j])
		{
			draw_to_window(str_arr, i, j);
			j++;
			str_arr->cords_x += 150;
		}
		str_arr->cords_y += 150;
		i++;
	}
}

void	move_hook(mlx_key_data_t key, void *param)
{
	t_arr	*str_arr;

	str_arr = (t_arr *)param;
	find_goopher(str_arr, &str_arr->x, &str_arr->y);
	check_ducky(str_arr);
	if (key.key == MLX_KEY_ESCAPE && key.action == 1)
	{
		free_all(str_arr);
		mlx_close_window(str_arr->mlx);
		return ;
	}
	if (key.key == MLX_KEY_W && key.action == 1)
		manage_w(str_arr);
	if (key.key == MLX_KEY_S && key.action == 1)
		manage_s(str_arr);
	if (key.key == MLX_KEY_D && key.action == 1)
		manage_d(str_arr);
	if (key.key == MLX_KEY_A && key.action == 1)
		manage_a(str_arr);
}

void	draw_to_window(t_arr *str_arr, int i, int j)
{
	if (str_arr->arr[i][j] == '1')
		mlx_image_to_window(str_arr->mlx,
			str_arr->img_arr[2], str_arr->cords_x, str_arr->cords_y);
	else if (str_arr->arr[i][j] == '0')
		mlx_image_to_window(str_arr->mlx,
			str_arr->img_arr[3], str_arr->cords_x, str_arr->cords_y);
	else if (str_arr->arr[i][j] == 'P')
	{
		mlx_image_to_window(str_arr->mlx,
			str_arr->img_arr[3], str_arr->cords_x, str_arr->cords_y);
		mlx_image_to_window(str_arr->mlx,
			str_arr->img_arr[0], str_arr->cords_x, str_arr->cords_y);
	}
	else if (str_arr->arr[i][j] == 'E')
		mlx_image_to_window(str_arr->mlx,
			str_arr->img_arr[4], str_arr->cords_x, str_arr->cords_y);
	draw_special(str_arr, i, j);
}

int	init_arr(t_arr *str_arr, int lines_count, int fd)
{
	str_arr->arr = malloc(sizeof(char *) * lines_count);
	str_arr->score = 0;
	lines_count = 0;
	str_arr->arr[lines_count] = get_next_line(fd);
	while (str_arr->arr[lines_count])
	{
			lines_count++;
			str_arr->arr[lines_count] = get_next_line(fd);
	}
	lines_count = 0;
	while (str_arr->arr[lines_count])
	{
			lines_count++;
	}
	return (lines_count);
}

int	main(void)
{
	int			lines_count;
	int			fd;
	t_arr		*str_arr;

	lines_count = 0;
	if (fd_check(&fd) == 1)
		return (0);
	if (line_check(count_lines(fd, &lines_count)) == 1)
		return (0);
	fd = open("map.ber", O_RDONLY);
	str_arr = malloc(sizeof(t_arr));
	lines_count = init_arr(str_arr, lines_count, fd);
	if (error_check(str_arr) == 0)
		return (0);
	str_arr->mlx = mlx_init(
			150 * ft_strlen(str_arr->arr[0]),
			150 * lines_count, "MLX42", true);
	if (!str_arr->mlx)
		exit(EXIT_FAILURE);
	init_text(str_arr);
	mlx_close_hook(str_arr->mlx, &free_all, str_arr);
	mlx_key_hook(str_arr->mlx, &move_hook, str_arr);
	mlx_loop(str_arr->mlx);
	clean_textures(str_arr);
	return (EXIT_SUCCESS);
}
