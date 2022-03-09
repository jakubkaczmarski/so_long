/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:00:31 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/03/08 23:00:32 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_buffjoin(char **line, char *buff)
{
	char	*retline;
	int		counter;
	int		index;

	if (!*line || !(buff))
		return ;
	index = 0;
	counter = 0;
	index = strlen(line[0]) + strlen(buff) + 1;
	retline = ft_calloc(index, sizeof(char));
	index = 0;
	while (line[0][counter])
	{
		retline[counter] = line[0][counter];
		counter++;
	}
	free((void *)(line[0]));
	while ((buff[index] != '\n') && buff[index])
	{
		retline[counter++] = buff[index++];
	}
	if (buff[index] == '\n')
		retline[counter] = '\n';
	line[0] = retline;
}

static void	ft_movetonextnewline(char *buff)
{
	int	lenghtofwholebuff;
	int	linelenght;
	int	leftbuff;

	lenghtofwholebuff = strlen(buff);
	linelenght = lenghtofwholebuff - strlen(ft_strrchr(buff, '\n') + 1);
	leftbuff = lenghtofwholebuff - linelenght;
	ft_memmove(buff, &buff[linelenght], leftbuff);
	ft_memset(&buff[leftbuff], '\0', linelenght);
}

static char	*lastlinethingy(char **line, char *buff)
{
	ft_buffjoin(line, buff);
	ft_memset(buff, '\0', 1);
	return (*line);
}

static char	*returnfree(char *line)
{
	free(line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	int			status;

	if (fd < 0)
		return (NULL);
	line = ft_calloc(1, sizeof(char));
	while (!ft_strrchr(buff, '\n'))
	{
		if (*buff)
			ft_buffjoin(&line, buff);
		status = read(fd, buff, BUFFER_SIZE);
		if (status <= 0 && !(*line))
			return (returnfree(line));
		buff[status] = '\0';
		if (!ft_strrchr(buff, '\n') && status < BUFFER_SIZE)
			return (lastlinethingy(&line, buff));
	}
	ft_buffjoin(&line, buff);
	ft_movetonextnewline(buff);
	return (line);
}
