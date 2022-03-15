/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:02:29 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/03/15 20:37:06 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	rewrite_map(t_arr *str_arr)
{
	int	i;
	int	j;
	int	cords_x;
	int	cords_y;

	i = 0;
	j = 0;
	cords_x = 0;
	cords_y = 0;
	while (str_arr->arr[i])
	{
		j = 0;
		cords_x = 0;
		while (str_arr->arr[i][j])
		{
			if (str_arr->arr[i][j] == '1')
			{
				mlx_image_to_window(str_arr->mlx,
					str_arr->img_arr[2], cords_x, cords_y);
			}
			else if (str_arr->arr[i][j] == '0')
			{
				mlx_image_to_window(str_arr->mlx,
					str_arr->img_arr[3], cords_x, cords_y);
			}
			else if (str_arr->arr[i][j] == 'P')
			{
				mlx_image_to_window(str_arr->mlx,
					str_arr->img_arr[3], cords_x, cords_y);
				mlx_image_to_window(str_arr->mlx,
					str_arr->img_arr[0], cords_x, cords_y);
			}
			else if (str_arr->arr[i][j] == 'E')
			{
				mlx_image_to_window(str_arr->mlx,
					str_arr->img_arr[4], cords_x, cords_y);
			}
			else if (str_arr->arr[i][j] == 'C')
			{
				mlx_image_to_window(str_arr->mlx,
					str_arr->img_arr[3], cords_x, cords_y);
				mlx_image_to_window(str_arr->mlx,
					str_arr->img_arr[1], cords_x, cords_y);
			}
			else if (str_arr->arr[i][j] == 'Q')
			{
				mlx_image_to_window(str_arr->mlx,
					str_arr->img_arr[3], cords_x, cords_y);
				mlx_image_to_window(str_arr->mlx,
					str_arr->img_arr[5], cords_x, cords_y);
			}
			j++;
			cords_x += 150;
		}
		cords_y += 150;
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
	{
		ft_printf("Score %d\n", str_arr->score);
		if (str_arr->arr[str_arr->x - 1][str_arr->y] != '1')
		{
			if (str_arr->arr[str_arr->x - 1][str_arr->y] == 'E' &&
					str_arr->duck_count == 0)
			{
				exit_clean(str_arr);
				return ;
			}
			else if (!(str_arr->arr[str_arr->x - 1][str_arr->y] == 'E'
				&& str_arr->duck_count != 0))
			{
				str_arr->x--;
				check_ducky(str_arr);
				str_arr->arr[str_arr->x][str_arr->y] = 'P';
				str_arr->arr[str_arr->x + 1][str_arr->y] = '0';
				str_arr->img_arr[0]->instances[0].y -= 150;
				rewrite_map(str_arr);
				str_arr->score++;
			}
			else
			{
				ft_printf("Duck number %d\n", str_arr->duck_count);
				ft_printf("You need to pick up duckies first plz :)\n");
				return ;
			}
		}
	}
	if (key.key == MLX_KEY_S && key.action == 1)
	{
		ft_printf("Score %d\n", str_arr->score);
		if (str_arr->arr[str_arr->x + 1][str_arr->y] != '1')
		{
			if (str_arr->arr[str_arr->x + 1][str_arr->y] == 'E'
				&& str_arr->duck_count == 0)
			{
				exit_clean(str_arr);
				return ;
			}
			else if (!(str_arr->arr[str_arr->x + 1][str_arr->y] == 'E'
				&& str_arr->duck_count != 0))
			{
				str_arr->x++;
				check_ducky(str_arr);
				str_arr->arr[str_arr->x][str_arr->y] = 'P';
				str_arr->arr[str_arr->x - 1][str_arr->y] = '0';
				str_arr->img_arr[0]->instances[0].y -= 150;
				rewrite_map(str_arr);
				str_arr->score++;
			}
			else
			{
				ft_printf("Duck number %d\n", str_arr->duck_count);
				ft_printf("You need to pick up duckies first plz :)\n");
				return ;
			}
		}
	}
	if (key.key == MLX_KEY_D && key.action == 1)
	{
		ft_printf("Score %d\n", str_arr->score);
		if (str_arr->arr[str_arr->x][str_arr->y + 1] != '1')
		{
			if (str_arr->arr[str_arr->x][str_arr->y + 1] == 'E'
				&& str_arr->duck_count == 0)
			{
				exit_clean(str_arr);
				return ;
			}
			else if (!(str_arr->arr[str_arr->x][str_arr->y + 1] == 'E'
				&& str_arr->duck_count != 0))
			{
				str_arr->y++;
				check_ducky(str_arr);
				str_arr->img_arr[0]->instances[0].x += 150;
				str_arr->arr[str_arr->x][str_arr->y - 1] = '0';
				str_arr->arr[str_arr->x][str_arr->y] = 'P';
				rewrite_map(str_arr);
				str_arr->score++;
			}
			else
			{
				ft_printf("Duck number %d\n", str_arr->duck_count);
				ft_printf("You need to pick up duckies first plz :)\n");
				return ;
			}
		}
	}
	if (key.key == MLX_KEY_A && key.action == 1)
	{
		ft_printf("Score %d\n", str_arr->score);
		if (str_arr->arr[str_arr->x][str_arr->y - 1] != '1')
		{
			if (str_arr->arr[str_arr->x][str_arr->y - 1] == 'E'
				&& str_arr->duck_count == 0)
			{
				exit_clean(str_arr);
				return ;
			}
			else if (!(str_arr->arr[str_arr->x][str_arr->y - 1] == 'E'
				&& str_arr->duck_count != 0))
			{
				str_arr->y--;
				check_ducky(str_arr);
				str_arr->score++;
				str_arr->arr[str_arr->x][str_arr->y + 1] = '0';
				str_arr->arr[str_arr->x][str_arr->y] = 'P';
				str_arr->img_arr[0]->instances[0].x -= 150;
				rewrite_map(str_arr);
			}
			else
			{
				ft_printf("Duck number %d\n", str_arr->duck_count);
				ft_printf("You need to pick up duckies first plz :)\n");
			}
		}
	}
}

int	main(void)
{
	int			lines_count;
	int			fd;
	t_arr		*str_arr;
	mlx_keyfunc	sm;

	lines_count = 0;
	fd = open("map.ber", O_RDONLY);
	if(fd <= 0)
	{
		ft_printf("Error\n");
		return 0;	
	}
	lines_count = count_lines(fd);
	fd = open("map.ber", O_RDONLY);
	str_arr = malloc(sizeof(t_arr));
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
	if (error_check(str_arr) == 0)
		return (0);
	str_arr->mlx = mlx_init(
			150 * ft_strlen(str_arr->arr[0]),
			150 * lines_count + 100, "MLX42", true);
	init_text(str_arr);
	rewrite_map(str_arr);
	find_ducks(str_arr);
	ft_printf("Duck number %d\n", str_arr->duck_count);
	if (!str_arr->mlx)
		exit(EXIT_FAILURE);
	sm = &move_hook;
	mlx_key_hook(str_arr->mlx, sm, str_arr);
	mlx_loop(str_arr->mlx);
	clean_textures(str_arr);
	return (EXIT_SUCCESS);
}
