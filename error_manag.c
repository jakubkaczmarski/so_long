/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:36:04 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/03/20 17:34:10 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	fd_check(char *str, int *fd)
{
	if (ft_strcmp(&str[ft_strlen(str) - 4], ".ber") != 0)
	{
		ft_printf("Filename broken\n");
		return (1);
	}
	*fd = 0;
	*fd = open(str, O_RDONLY);
	if (*fd <= 0)
	{
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

int	check_for_err(t_arr *str_arr)
{
	if (!str_arr->xpm[0] || !str_arr->xpm[1] || !str_arr->xpm[2]
		|| !str_arr->xpm[4] || !str_arr->xpm[5])
	{
		ft_printf ("No images in the directory fix it plz");
		return (-1);
	}
	return (0);
}
