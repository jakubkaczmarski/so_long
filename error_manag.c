/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:36:04 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/03/16 15:35:05 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	fd_check(int *fd)
{
	*fd = 0;
	*fd = open("map.ber", O_RDONLY);
	if (*fd <= 0)
	{
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}

int	line_check(int lines_count)
{
	if (lines_count == -1)
	{
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}

void	display_score(t_arr *str_arr)
{
	str_arr->str = ft_itoa(str_arr->score);
	mlx_delete_image(str_arr->mlx, str_arr->img_arr[6]);
	str_arr->img_arr[6] = mlx_put_string(str_arr->mlx, str_arr->str, 1, 1);
	free(str_arr->str);
}
