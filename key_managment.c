/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_managment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:46:38 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/03/16 14:52:45 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	manage_w(t_arr *str_arr)
{
	if (str_arr->arr[str_arr->x - 1][str_arr->y] != '1')
	{
		if (str_arr->arr[str_arr->x - 1][str_arr->y] == 'E' &&
				str_arr->duck_count == 0)
		{
			exit_clean(str_arr);
			return (-1);
		}
		else if (!(str_arr->arr[str_arr->x - 1][str_arr->y] == 'E'
			&& str_arr->duck_count != 0))
			change_img_t(str_arr);
		else
			manage_exit_w(str_arr);
		rewrite_map(str_arr);
		display_score(str_arr);
	}
	return (0);
}

int	manage_s(t_arr *str_arr)
{
	if (str_arr->arr[str_arr->x + 1][str_arr->y] != '1')
	{
		if (str_arr->arr[str_arr->x + 1][str_arr->y] == 'E'
			&& str_arr->duck_count == 0)
		{
			exit_clean(str_arr);
			return (-1);
		}
		else if (!(str_arr->arr[str_arr->x + 1][str_arr->y] == 'E'
			&& str_arr->duck_count != 0))
			change_img_s(str_arr);
		else
			manage_exit_s(str_arr);
		rewrite_map(str_arr);
		display_score(str_arr);
	}
	return (0);
}

int	manage_d(t_arr *str_arr)
{
	if (str_arr->arr[str_arr->x][str_arr->y + 1] != '1')
	{
		if (str_arr->arr[str_arr->x][str_arr->y + 1] == 'E'
			&& str_arr->duck_count == 0)
		{
			exit_clean(str_arr);
			return (-1);
		}
		else if (!(str_arr->arr[str_arr->x][str_arr->y + 1] == 'E'
			&& str_arr->duck_count != 0))
			change_img_d(str_arr);
		else
			manage_exit_d(str_arr);
		rewrite_map(str_arr);
		display_score(str_arr);
	}
	return (0);
}

int	manage_a(t_arr *str_arr)
{
	if (str_arr->arr[str_arr->x][str_arr->y - 1] != '1')
	{
		if (str_arr->arr[str_arr->x][str_arr->y - 1] == 'E'
			&& str_arr->duck_count == 0)
		{
			exit_clean(str_arr);
			return (-1);
		}
		else if (!(str_arr->arr[str_arr->x][str_arr->y - 1] == 'E'
			&& str_arr->duck_count != 0))
			change_img_a(str_arr);
		else
			manage_exit_a(str_arr);
	}
	rewrite_map(str_arr);
	display_score(str_arr);
	return (0);
}
