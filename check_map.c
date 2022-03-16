/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 22:23:30 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/03/16 14:47:06 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delete_img(t_arr *str_arr)
{
	mlx_delete_image(str_arr->mlx, str_arr->img_arr[0]);
	mlx_delete_image(str_arr->mlx, str_arr->img_arr[1]);
	mlx_delete_image(str_arr->mlx, str_arr->img_arr[2]);
	mlx_delete_image(str_arr->mlx, str_arr->img_arr[3]);
	mlx_delete_image(str_arr->mlx, str_arr->img_arr[4]);
	mlx_delete_image(str_arr->mlx, str_arr->img_arr[5]);
}

void	init_text(t_arr *str_arr)
{
	str_arr->xpm[0] = mlx_load_xpm42("water.xpm42");
	str_arr->xpm[1] = mlx_load_xpm42("sand.xpm42");
	str_arr->xpm[2] = mlx_load_xpm42("final_gopher.xpm42");
	str_arr->xpm[3] = mlx_load_xpm42("exit.xpm42");
	str_arr->xpm[4] = mlx_load_xpm42("duck_knife_out.xpm42");
	str_arr->xpm[5] = mlx_load_xpm42("beaver.xpm42");
	str_arr->img_arr[2] = mlx_texture_to_image(str_arr->mlx,
			& str_arr->xpm[0]->texture);
	str_arr->img_arr[3] = mlx_texture_to_image(str_arr->mlx,
			& str_arr->xpm[1]->texture);
	str_arr->img_arr[0] = mlx_texture_to_image(str_arr->mlx,
			& str_arr->xpm[2]->texture);
	str_arr->img_arr[4] = mlx_texture_to_image(str_arr->mlx,
			& str_arr->xpm[3]->texture);
	str_arr->img_arr[1] = mlx_texture_to_image(str_arr->mlx,
			& str_arr->xpm[4]->texture);
	str_arr->img_arr[5] = mlx_texture_to_image(str_arr->mlx,
			& str_arr->xpm[5]->texture);
	rewrite_map(str_arr);
	find_ducks(str_arr);
}

int	check_lenght(char **arr)
{
	int	i;
	int	size;

	i = 0;
	while (arr[i])
	{
		if (arr[i][ft_strlen(arr[i]) - 1] == '\n')
			arr[i][ft_strlen(arr[i]) - 1] = '\0';
		i++;
	}
	i = 0;
	size = 0;
	size = ft_strlen(arr[i]);
	if (size == 0)
		return (-1);
	while (arr[i])
	{
		if (size != ft_strlen(arr[i]))
		{
			return (-1);
		}
		i++;
	}
	return (1);
}

void	check_ducky(t_arr *str_arr)
{
	if (str_arr->arr[str_arr->x][str_arr->y] == 'C')
	{
			str_arr->duck_count--;
	}
}

void	exit_clean(t_arr *str_arr)
{
	str_arr->score++;
	ft_printf("\nYOU WON:\nYour score is %d", str_arr->score);
	free_all(str_arr);
	mlx_close_window(str_arr->mlx);
}
