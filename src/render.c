/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakunwar <nakunwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 22:29:06 by nakunwar          #+#    #+#             */
/*   Updated: 2025/07/08 20:02:30 by nakunwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	render_image_split(t_main *main, int y)
{
	int	x;

	x = -1;
	while (++x < main->map->x)
	{
		if (main->map->map[y][x] == '1')
			mlx_put_image_to_window(main->mlx, main->win,
				main->img->wall, x * PIXEL, y * PIXEL);
		else if (main->map->map[y][x] == '0' || main->map->map[y][x] == 'P')
			mlx_put_image_to_window(main->mlx, main->win,
				main->img->way, x * PIXEL, y * PIXEL);
		else if (main->map->map[y][x] == 'E')
			mlx_put_image_to_window(main->mlx, main->win,
				main->img->exitd, x * PIXEL, y * PIXEL);
		else if (main->map->map[y][x] == 'C')
			mlx_put_image_to_window(main->mlx, main->win,
				main->img->cup, x * PIXEL, y * PIXEL);
		else if (main->map->map[y][x] == 'X' && (main->p_x + main->p_y) % 3)
			mlx_put_image_to_window(main->mlx, main->win,
				main->img->enemy, x * PIXEL, y * PIXEL);
		else
			mlx_put_image_to_window(main->mlx, main->win,
				main->img->way, x * PIXEL, y * PIXEL);
	}
}

int	render_image(t_main *main)
{
	int	y;

	y = 0;
	while (y < main->map->y)
	{
		render_image_split(main, y);
		y++;
	}
	mlx_put_image_to_window(main->mlx, main->win, main->img->pl,
		(main->p_x) * PIXEL, (main->p_y) * PIXEL);
	if (main->cup_count == 0
		&& main->map->map[main->p_y][main->p_x] == 'E')
		ft_destroy(main);
	else
		write_move_count(main);
	return (0);
}
