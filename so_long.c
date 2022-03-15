/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 22:07:50 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/03/15 18:00:38 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*g_img;
mlx_image_t	*image;
mlx_image_t	*image2;
mlx_image_t	*image3;
mlx_image_t	*image4;
mlx_image_t	*image5;
mlx_image_t	*image6;

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
				{
					return (0);
				}
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
	char	wall;
	int		i;
	int		j;

	wall = '1';
	i = ft_strlen(arr[0]) - 1;
	j = 0;
	while (arr[0][j])
	{
		if (arr[0][j] != wall)
			return (-1);
		j++;
	}
	j = 0;
	while (arr[j])
	{
		if (arr[j][0] != wall)
			return (-1);
		if (arr[j][i] != wall)
			return (-1);
		j++;
	}
	i = 0;
	while (arr[j - 1][i])
	{
		if (arr[j - 1][i] != wall)
			return (-1);
		i++;
	}
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

void	delete_img(t_arr *str_arr)
{
	mlx_delete_image(str_arr->mlx, image);
	mlx_delete_image(str_arr->mlx, image2);
	mlx_delete_image(str_arr->mlx, image3);
	mlx_delete_image(str_arr->mlx, image4);
	mlx_delete_image(str_arr->mlx, image5);
	mlx_delete_image(str_arr->mlx, image6);
}

void	init_text(t_arr *str_arr)
{
	str_arr->xpm[0] = mlx_load_xpm42("water.xpm42");
	str_arr->xpm[1] = mlx_load_xpm42("sand.xpm42");
	str_arr->xpm[2] = mlx_load_xpm42("final_gopher.xpm42");
	str_arr->xpm[3] = mlx_load_xpm42("exit.xpm42");
	str_arr->xpm[4] = mlx_load_xpm42("duck_knife_out.xpm42");
	str_arr->xpm[5] = mlx_load_xpm42("beaver.xpm42");
	image3 = mlx_texture_to_image(str_arr->mlx, &str_arr->xpm[0]->texture);
	image4 = mlx_texture_to_image(str_arr->mlx, &str_arr->xpm[1]->texture);
	image = mlx_texture_to_image(str_arr->mlx, &str_arr->xpm[2]->texture);
	image5 = mlx_texture_to_image(str_arr->mlx, &str_arr->xpm[3]->texture);
	image2 = mlx_texture_to_image(str_arr->mlx, &str_arr->xpm[4]->texture);
	image6 = mlx_texture_to_image(str_arr->mlx, &str_arr->xpm[5]->texture);
}

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
				mlx_image_to_window(str_arr->mlx, image3, cords_x, cords_y);
			}
			else if (str_arr->arr[i][j] == '0')
			{
				mlx_image_to_window(str_arr->mlx, image4, cords_x, cords_y);
			}
			else if (str_arr->arr[i][j] == 'P')
			{
				mlx_image_to_window(str_arr->mlx, image4, cords_x, cords_y);
				mlx_image_to_window(str_arr->mlx, image, cords_x, cords_y);
			}
			else if (str_arr->arr[i][j] == 'E')
			{
				mlx_image_to_window(str_arr->mlx, image5, cords_x, cords_y);
			}
			else if (str_arr->arr[i][j] == 'C')
			{
				mlx_image_to_window(str_arr->mlx, image4, cords_x, cords_y);
				mlx_image_to_window(str_arr->mlx, image2, cords_x, cords_y);
			}
			else if (str_arr->arr[i][j] == 'Q')
			{
				mlx_image_to_window(str_arr->mlx, image4, cords_x, cords_y);
				mlx_image_to_window(str_arr->mlx, image6, cords_x, cords_y);
			}
			j++;
			cords_x += 150;
		}
		cords_y += 150;
		i++;
	}
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
	delete_img(str_arr);
	free_all(str_arr);
	mlx_close_window(str_arr->mlx);
}

void	move_hook(mlx_key_data_t key, void *param)
{
	t_arr   *str_arr;

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
			else if (!(str_arr->arr[str_arr->x - 1][str_arr->y] == 'E' &&
									str_arr->duck_count != 0))
			{
				str_arr->x--;
				check_ducky(str_arr);
				str_arr->arr[str_arr->x][str_arr->y] = 'P';
				str_arr->arr[str_arr->x + 1][str_arr->y] = '0';
				image->instances[0].y -= 150;
				rewrite_map(str_arr);
				str_arr->score++;
			}
			else
			{
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
				str_arr->arr[str_arr->x][str_arr->y] = 'P';
				check_ducky(str_arr);
				str_arr->arr[str_arr->x - 1][str_arr->y] = '0';
				image->instances[0].y += 150;
				rewrite_map(str_arr);
				str_arr->score++;
			}
			else
			{
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
				image->instances[0].x += 150;
				str_arr->arr[str_arr->x][str_arr->y - 1] = '0';
				str_arr->arr[str_arr->x][str_arr->y] = 'P';
				rewrite_map(str_arr);
				str_arr->score++;
			}
			else
			{
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
				image->instances[0].x -= 150;
				// delete_img(str_arr);
				rewrite_map(str_arr);
			}
			else
			{
				ft_printf("You need to pick up duckies first plz :)\n");
			}
		}
	}
}

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

int	main(void)
{
	int			lines_count;
	int			fd;
	t_arr		*str_arr;
	mlx_keyfunc	sm;

	lines_count = 0;
	fd = open("map.ber", O_RDONLY);
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
	if (check_lenght(str_arr->arr) == -1 || check_signs(str_arr->arr, 'C') == 0
		|| check_signs(str_arr->arr, 'P') == 0
		|| check_signs(str_arr->arr, 'E') == 0
		|| check_walls(str_arr->arr) == -1
		|| check_if_right_characs(str_arr->arr) == -1)
	{
		ft_printf("\nError");
		ft_printf("Map Problem\n");
		return (0);
	};

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
	mlx_delete_texture(&str_arr->xpm[0]->texture);
	mlx_delete_texture(&str_arr->xpm[1]->texture);
	mlx_delete_texture(&str_arr->xpm[2]->texture);
	mlx_delete_texture(&str_arr->xpm[3]->texture);
	mlx_delete_texture(&str_arr->xpm[4]->texture);
	mlx_delete_texture(&str_arr->xpm[5]->texture);
	return (EXIT_SUCCESS);
}
