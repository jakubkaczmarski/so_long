/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_manag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:13:29 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/03/16 15:16:58 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_special(t_arr *str_arr, int i, int j)
{
	if (str_arr->arr[i][j] == 'C')
	{
		mlx_image_to_window(str_arr->mlx,
			str_arr->img_arr[3], str_arr->cords_x, str_arr->cords_y);
		mlx_image_to_window(str_arr->mlx,
			str_arr->img_arr[1], str_arr->cords_x, str_arr->cords_y);
	}
	else if (str_arr->arr[i][j] == 'Q')
	{
		mlx_image_to_window(str_arr->mlx,
			str_arr->img_arr[3], str_arr->cords_x, str_arr->cords_y);
		mlx_image_to_window(str_arr->mlx,
			str_arr->img_arr[5], str_arr->cords_x, str_arr->cords_y);
	}
	else if (str_arr->arr[i][j] == 'X')
	{
		mlx_image_to_window(str_arr->mlx,
			str_arr->img_arr[4], str_arr->cords_x, str_arr->cords_y);
		mlx_image_to_window(str_arr->mlx,
			str_arr->img_arr[0], str_arr->cords_x, str_arr->cords_y);
	}
}

void	change_img_t(t_arr *str_arr)
{
	if (str_arr->exit == 1)
	{
		check_ducky(str_arr);
		str_arr->x--;
		str_arr->arr[str_arr->x][str_arr->y] = 'P';
		str_arr->arr[str_arr->x + 1][str_arr->y] = 'E';
		str_arr->exit = 0;
	}
	else
	{
		str_arr->x--;
		check_ducky(str_arr);
		str_arr->arr[str_arr->x][str_arr->y] = 'P';
		str_arr->arr[str_arr->x + 1][str_arr->y] = '0';
	}
	str_arr->score++;
}

void	change_img_s(t_arr *str_arr)
{
	if (str_arr->exit == 1)
	{
		str_arr->x++;
		check_ducky(str_arr);
		str_arr->arr[str_arr->x][str_arr->y] = 'P';
		str_arr->arr[str_arr->x - 1][str_arr->y] = 'E';
		str_arr->exit = 0;
	}
	else
	{
		str_arr->x++;
		check_ducky(str_arr);
		str_arr->arr[str_arr->x][str_arr->y] = 'P';
		str_arr->arr[str_arr->x - 1][str_arr->y] = '0';
	}
	str_arr->score++;
}

void	change_img_d(t_arr *str_arr)
{
	if (str_arr->exit == 1)
	{
		str_arr->y++;
		check_ducky(str_arr);
		str_arr->arr[str_arr->x][str_arr->y - 1] = 'E';
		str_arr->arr[str_arr->x][str_arr->y] = 'P';
		str_arr->exit = 0;
	}
	else
	{
		str_arr->y++;
		check_ducky(str_arr);
		str_arr->arr[str_arr->x][str_arr->y - 1] = '0';
		str_arr->arr[str_arr->x][str_arr->y] = 'P';
	}
	str_arr->score++;
}

void	change_img_a(t_arr *str_arr)
{
	if (str_arr->exit == 1)
	{
		str_arr->y--;
		check_ducky(str_arr);
		str_arr->arr[str_arr->x][str_arr->y + 1] = 'E';
		str_arr->arr[str_arr->x][str_arr->y] = 'P';
		str_arr->exit = 0;
	}
	else
	{
		str_arr->y--;
		check_ducky(str_arr);
		str_arr->arr[str_arr->x][str_arr->y + 1] = '0';
		str_arr->arr[str_arr->x][str_arr->y] = 'P';
	}
	str_arr->score++;
}
