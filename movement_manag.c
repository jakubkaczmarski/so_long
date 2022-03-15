/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_manag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:13:29 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/03/15 20:15:20 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void draw_to_window(t_arr *str_arr, int num, int cords_x, int cords_y)
{
    mlx_image_to_window(str_arr->mlx,
				str_arr->img_arr[num], cords_x, cords_y);
}