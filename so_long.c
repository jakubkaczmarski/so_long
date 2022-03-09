/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 22:07:50 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/03/09 19:11:54 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

mlx_image_t	*g_img;
mlx_image_t *image;
mlx_image_t *image2;
mlx_image_t *image3;
mlx_image_t *image4;
mlx_image_t *image5;
mlx_image_t *image6;
//0 == Empty space
//1 == Wall
//C == Collectible
//E == Exit
//P == player's starting position

int check_lenght(char **arr)
{
	int i = 0;
	while(arr[i])
	{
		if(arr[i][ft_strlen(arr[i]) - 1] == '\n')
			arr[i][ft_strlen(arr[i]) - 1] = '\0';
			i++;
	}
	i = 0;
	int size = 0;
	size = ft_strlen(arr[i]);
	// i++;
	if(size == 0)
		return -1;
	while(arr[i])
	{
		if(size != ft_strlen(arr[i]))
		{
			return -1;
		}
		i++;
	}
	return 1;
}
int check_signs(char **arr, char symbol)
{	
	int i = 0;
	int appeared = 0;
	int j = 0;
	while(arr[i])
	{
		j = 0;
		while(arr[i][j])
		{
			if(arr[i][j] == symbol)
			{
				appeared++;
				if(symbol != 'C' && appeared == 2)
				{
					return 0;
				}
				
			}
			j++;
		}
		i++;	
	}
	if(appeared == 0)
		return 0;

	return 1;
}
int check_if_right_characs(char **arr)
{
	int i = 0;
	int j = 0;
	while(arr[i])
	{
		j = 0;
		while(arr[i][j])
		{
			if(arr[i][j] != '1' && arr[i][j] != '0' && arr[i][j] != 'C' && arr[i][j] != 'P' && arr[i][j] != 'Q' && arr[i][j] != 'E')
			{
				return -1;
			}
			j++;
		}
		i++;
	}
	return 1;
}
int check_walls(char **arr)
{
	char wall = '1';
	int i = ft_strlen(arr[0]) - 1;
	int j = 0;
	while(arr[0][j])
	{
		if(arr[0][j] != wall)
			return -1;
		j++;
	}
	j = 0;
	//2
	while(arr[j])
	{
		if(arr[j][0] != wall)
			return -1;
		if(arr[j][i] != wall)
			return -1;
		j++;
	}
	i = 0;
	while(arr[j - 1][i])
	{
		if(arr[j - 1][i] != wall)
			return -1;
		i++;
	}
	return 0;
}
//Get valid map input
//Use get next line to get each line of the map
//Add each line to the 
void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;

	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
	{
		mlx_close_window(param);
		// free()
	}
	if (mlx_is_key_down(param, MLX_KEY_W))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(param, MLX_KEY_S))
	{
		image->instances[0].y += 5;
		// image->instances[0].	
	}
	if (mlx_is_key_down(param, MLX_KEY_A))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(param, MLX_KEY_D))
	{
		image->instances[0].x += 5;
		return ;
	}

	
	if (mlx_is_key_down(param, MLX_KEY_UP))
		image2->instances[0].y -= 5;
	if (mlx_is_key_down(param, MLX_KEY_DOWN))
	{
		image2->instances[0].y += 5;
		// image->instances[0].	
	}
	if (mlx_is_key_down(param, MLX_KEY_LEFT))
		image2->instances[0].x -= 5;
	if (mlx_is_key_down(param, MLX_KEY_RIGHT))
		image2->instances[0].x += 5;
}
void free_all(char **arr)
{
	int i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
int	main(void)
{
	mlx_t	*mlx;
	int lines_count = 0;
	int fd = open("map.ber",O_RDONLY);
	while(get_next_line(fd))
	{	
		lines_count++;
	}
	close(fd);
	fd = open("map.ber",O_RDONLY);
	char **arr = malloc(sizeof(char *) * lines_count + 1);
	lines_count = 0;
	arr[lines_count] = get_next_line(fd);
	while(arr[lines_count])
	{	
		lines_count++;
		arr[lines_count] = get_next_line(fd);
		
	}
	lines_count = 0;
	while(arr[lines_count])
	{
		// ft_printf("%s", arr[lines_count]);
		lines_count++;
	}
	if(check_lenght(arr) == -1 || check_signs(arr, 'C') == 0 || check_signs(arr, 'P') == 0 || check_signs(arr, 'E') == 0 || check_walls(arr) == -1 || check_if_right_characs(arr) == -1)
	{
		ft_printf("\nError");
		ft_printf("Map Problem\n");
		return 0;
	};
	
	mlx = mlx_init(150 * ft_strlen(arr[0]), 150 * lines_count, "MLX42", true);
	//Current coordinates
	int i = 0;
	int j = 0;
	int cords_x = 0;
	int cords_y = 0;
	xpm_t* xpm;
	while(arr[i])
	{
		j = 0;
		cords_x = 0;
		while(arr[i][j])
		{
			if(arr[i][j] == '1')
			{
				xpm = mlx_load_xpm42("water.xpm42");
				image3 = mlx_texture_to_image(mlx, &xpm->texture);
				mlx_image_to_window(mlx, image3, cords_x, cords_y);
			}else if(arr[i][j] == '0')
			{
				xpm = mlx_load_xpm42("sand.xpm42");
				image4 = mlx_texture_to_image(mlx, &xpm->texture);
				mlx_image_to_window(mlx, image4, cords_x, cords_y);
			}else if(arr[i][j] == 'P')
			{
				xpm = mlx_load_xpm42("sand.xpm42");
				image4 = mlx_texture_to_image(mlx, &xpm->texture);
				mlx_image_to_window(mlx, image4, cords_x, cords_y);
				xpm = mlx_load_xpm42("final_gopher.xpm42");
				image = mlx_texture_to_image(mlx, &xpm->texture);
				mlx_image_to_window(mlx, image, cords_x, cords_y);
			}else if(arr[i][j] == 'E')
			{
				xpm = mlx_load_xpm42("exit.xpm42");
				image5 = mlx_texture_to_image(mlx, &xpm->texture);
				mlx_image_to_window(mlx, image5, cords_x, cords_y);
			}else if(arr[i][j] == 'C')
			{
				xpm = mlx_load_xpm42("sand.xpm42");
				image4 = mlx_texture_to_image(mlx, &xpm->texture);
				mlx_image_to_window(mlx, image4, cords_x, cords_y);
				xpm = mlx_load_xpm42("ducky.xpm42");
				image2 = mlx_texture_to_image(mlx, &xpm->texture);
				mlx_image_to_window(mlx, image2, cords_x, cords_y);
			}else if(arr[i][j] == 'Q')
			{
				xpm = mlx_load_xpm42("sand.xpm42");
				image4 = mlx_texture_to_image(mlx, &xpm->texture);
				mlx_image_to_window(mlx, image4, cords_x, cords_y);
				xpm = mlx_load_xpm42("beaver.xpm42");
				image6 = mlx_texture_to_image(mlx, &xpm->texture);
				mlx_image_to_window(mlx, image6, cords_x, cords_y);
			}
			j++;
			cords_x += 150;
		}
		cords_y += 150;
		i++;
	}
	//Check if there are other characters in the map TODO
	//Swap Arr[el]
	if (!mlx)
		exit(EXIT_FAILURE);
	
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free_all(arr);
	//150 for each thing
	//150 * 35
	return (EXIT_SUCCESS);
}
