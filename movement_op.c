/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:40:22 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/03/16 14:48:39 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	manage_exit_a(t_arr *str_arr)
{
	str_arr->exit = 1;
	str_arr->y--;
	check_ducky(str_arr);
	str_arr->img_arr[0]->instances[0].x -= 150;
	str_arr->arr[str_arr->x][str_arr->y + 1] = '0';
	str_arr->arr[str_arr->x][str_arr->y] = 'X';
	rewrite_map(str_arr);
	str_arr->score++;
	ft_printf("Duck number %d\n", str_arr->duck_count);
	ft_printf("You need to pick up duckies first plz :)\n");
}

void	manage_exit_d(t_arr *str_arr)
{
	str_arr->exit = 1;
	str_arr->y++;
	check_ducky(str_arr);
	str_arr->img_arr[0]->instances[0].x += 150;
	str_arr->arr[str_arr->x][str_arr->y - 1] = '0';
	str_arr->arr[str_arr->x][str_arr->y] = 'X';
	rewrite_map(str_arr);
	str_arr->score++;
	ft_printf("Duck number %d\n", str_arr->duck_count);
	ft_printf("You need to pick up duckies first plz :)\n");
}

void	manage_exit_s(t_arr *str_arr)
{
	str_arr->exit = 1;
	str_arr->x++;
	check_ducky(str_arr);
	str_arr->arr[str_arr->x][str_arr->y] = 'X';
	str_arr->arr[str_arr->x - 1][str_arr->y] = '0';
	str_arr->img_arr[0]->instances[0].y += 150;
	str_arr->score++;
	ft_printf("Duck number %d\n", str_arr->duck_count);
	ft_printf("You need to pick up duckies first plz :)\n");
}

void	manage_exit_w(t_arr *str_arr)
{
	str_arr->exit = 1;
	str_arr->x--;
	check_ducky(str_arr);
	str_arr->arr[str_arr->x][str_arr->y] = 'X';
	str_arr->arr[str_arr->x + 1][str_arr->y] = '0';
	str_arr->img_arr[0]->instances[0].y -= 150;
	str_arr->score++;
	ft_printf("Duck number %d\n", str_arr->duck_count);
	ft_printf("You need to pick up duckies first plz :)\n");
}
