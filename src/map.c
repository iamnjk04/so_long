/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakunwar <nakunwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 23:29:06 by nakunwar          #+#    #+#             */
/*   Updated: 2025/07/08 20:00:14 by nakunwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	map2(t_main *main, int height, int width, char *buffer)
{
	int		y;
	int		x;

	y = 0;
	while (y < height)
	{
		x = 0;
		main->map->map[y] = ft_calloc((width + 1), sizeof(char));
		while (x < width)
		{
			if (buffer[(y * (width + 1) + x)] == 'E')
				main->exitcount++;
			else if (buffer[y * (width + 1) + x] == 'P')
			{
				main->playercount++;
				main->p_x = x;
				main->p_y = y;
			}
			else if (buffer[(y * (width + 1) + x)] == 'C')
				main->cup_count++;
			main->map->map[y][x] = buffer[(y * (width + 1) + x)];
			x++;
		}
		main->map->map[y++][x] = '\0';
	}
}

static void	map(char *buffer, t_main *main)
{
	int		height;
	int		width;
	int		i;

	main->exitcount = 0;
	main->playercount = 0;
	main->cup_count = 0;
	height = 0;
	i = 0;
	while (buffer[i] != 0)
		if (buffer[i++] == '\n')
			height++;
	if (buffer[i - 1] != '\n')
		height++;
	i = 0;
	while (buffer[i] != '\n' && buffer[i] && buffer[i] != EOF)
		i++;
	width = i;
	main->map->map = ft_calloc((height + 1), sizeof(char *));
	map2(main, height, width, buffer);
	main->map->x = width;
	main->map->y = height;
}

char	**map_init(char *path, t_main *main)
{
	char	*buffer;
	int		i;
	int		bytes;
	int		fd;

	buffer = ft_calloc(10000, sizeof(char));
	fd = open(path, O_RDONLY);
	i = 0;
	bytes = 1;
	buffer[0] = '\0';
	while (bytes)
	{
		bytes = read(fd, &buffer[i++], 1);
		if (bytes == -1)
			ft_destroy(main);
	}
	buffer[i] = '\0';
	map(buffer, main);
	free(buffer);
	close(fd);
	return (main->map->map);
}
