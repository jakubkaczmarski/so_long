/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_func_thingy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:33:17 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/03/15 18:40:31 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(int fd)
{
	int		lines_count;
	char	*line;

	lines_count = 0;
	line = get_next_line(fd);
	while (line)
	{
		lines_count++;
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	return (lines_count);
}

void	clean_textures(t_arr *str_arr)
{
	mlx_delete_texture(&str_arr->xpm[0]->texture);
	mlx_delete_texture(&str_arr->xpm[1]->texture);
	mlx_delete_texture(&str_arr->xpm[2]->texture);
	mlx_delete_texture(&str_arr->xpm[3]->texture);
	mlx_delete_texture(&str_arr->xpm[4]->texture);
	mlx_delete_texture(&str_arr->xpm[5]->texture);
	mlx_terminate(str_arr->mlx);
}

int	error_check(t_arr *str_arr)
{
	int	i;

	if (check_lenght(str_arr->arr) == -1 || check_signs(str_arr->arr, 'C') == 0
		|| check_signs(str_arr->arr, 'P') == 0
		|| check_signs(str_arr->arr, 'E') == 0
		|| check_walls(str_arr->arr) == -1
		|| check_if_right_characs(str_arr->arr) == -1)
	{
		ft_printf("\nError");
		ft_printf("Map Problem\n");
		i = 0;
		while (str_arr->arr[i])
		{
			free(str_arr->arr[i]);
			i++;
		}
		free(str_arr->arr);
		return (0);
	}
	else
		return (1);
}

void	free_all(t_arr *str_arr)
{
	int	i;

	i = 0;
	while (str_arr->arr[i])
	{
		free(str_arr->arr[i]);
		i++;
	}
	free(str_arr->arr);
	delete_img(str_arr);
}
