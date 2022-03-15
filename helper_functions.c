/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:27:18 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/03/15 20:10:38 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_signs(char **arr, char symbol)
{
	int	i;
	int	appeared;
	int	j;

	i = 0;
	appeared = 0;
	j = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == symbol)
			{
				appeared++;
				if (symbol != 'C' && appeared == 2)
					return (0);
			}
			j++;
		}
		i++;
	}
	if (appeared == 0)
		return (0);
	return (1);
}

int	check_if_right_characs(char **arr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] != '1' && arr[i][j] != '0' && arr[i][j] != 'C'
				&& arr[i][j] != 'P' && arr[i][j] != 'Q' && arr[i][j] != 'E')
			{
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_walls(char **arr)
{
	int		i;
	int		j;

	i = ft_strlen(arr[0]) - 1;
	j = 0;
	while (arr[0][j])
		if (arr[0][j++] != '1')
			return (-1);
	j = 0;
	while (arr[j])
	{
		if (arr[j][0] != '1')
			return (-1);
		if (arr[j++][i] != '1')
			return (-1);
	}
	i = 0;
	while (arr[j - 1][i])
		if (arr[j - 1][i++] != '1')
			return (-1);
	return (0);
}

void	find_goopher(t_arr *str_arr, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str_arr->arr[i])
	{
		j = 0;
		while (str_arr->arr[i][j])
		{
			if (str_arr->arr[i][j] == 'P')
			{
				*x = i;
				*y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	find_ducks(t_arr *str_arr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str_arr->arr[i])
	{
		j = 0;
		while (str_arr->arr[i][j])
		{
			if (str_arr->arr[i][j] == 'C')
			{
				str_arr->duck_count++;
			}
			j++;
		}
		i++;
	}
}
