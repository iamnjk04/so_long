/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakunwar <nakunwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 22:29:06 by nakunwar          #+#    #+#             */
/*   Updated: 2025/07/08 20:01:37 by nakunwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_error(char *errorcode, t_main *main)
{
	errno = 2;
	while (*errorcode)
		write(2, errorcode++, 1);
	write(2, "\n", 1);
	if (main)
		ft_destroy(main);
	exit(1);
}

void	xpm_to_img(t_main *main)
{
	main->img->pr = mlx_xpm_file_to_image(
			main->mlx, "./textures/right.xpm", &main->tmp, &main->tmp);
	main->img->pl = main->img->pr;
	main->img->ple = mlx_xpm_file_to_image(
			main->mlx, "./textures/left.xpm", &main->tmp, &main->tmp);
	main->img->pu = mlx_xpm_file_to_image(
			main->mlx, "./textures/back.xpm", &main->tmp, &main->tmp);
	main->img->pd = mlx_xpm_file_to_image(
			main->mlx, "./textures/front.xpm", &main->tmp, &main->tmp);
	main->img->way = mlx_xpm_file_to_image(
			main->mlx, "./textures/way.xpm", &main->tmp, &main->tmp);
	main->img->wall = mlx_xpm_file_to_image(
			main->mlx, "./textures/wall.xpm", &main->tmp, &main->tmp);
	main->img->exitd = mlx_xpm_file_to_image(
			main->mlx, "./textures/exit.xpm", &main->tmp, &main->tmp);
	main->img->enemy = mlx_xpm_file_to_image(
			main->mlx, "./textures/ronaldo.xpm", &main->tmp, &main->tmp);
	main->img->cup = mlx_xpm_file_to_image(
			main->mlx, "./textures/ballondor.xpm", &main->tmp, &main->tmp);
	if (main->img->pr == NULL || main->img->ple == NULL
		|| main->img->wall == NULL || main->img->pd == NULL
		|| main->img->way == NULL || main->img->pu == NULL
		|| main->img->exitd == NULL || main->img->cup == NULL
		|| main->img->pl == NULL)
		ft_error("Error\nImage initialization failed", main);
}

t_main	*main_init(char *path)
{
	t_main	*main;

	main = ft_calloc(1, sizeof(t_main));
	main->map = ft_calloc(1, sizeof(t_map));
	main->img = ft_calloc(1, sizeof(t_img));
	main->cup_count = 0;
	main->movecount = 0;
	main->map->map = map_init(path, main);
	main->mlx = mlx_init();
	if (main->mlx == NULL)
		ft_error("Error\nMlx initialization failed", main);
	xpm_to_img(main);
	main->win = mlx_new_window(main->mlx,
			main->map->x * PIXEL, main->map->y * PIXEL, "so_long");
	return (main);
}

void	check_files(void)
{
	if (access("textures/wall.xpm", F_OK | R_OK) == -1
		|| access("textures/way.xpm", F_OK | R_OK) == -1
		|| access("textures/ballondor.xpm", F_OK | R_OK) == -1
		|| access("textures/left.xpm", F_OK | R_OK) == -1
		|| access("textures/right.xpm", F_OK | R_OK) == -1
		|| access("textures/back.xpm", F_OK | R_OK) == -1
		|| access("textures/front.xpm", F_OK | R_OK) == -1
		|| access("textures/ronaldo.xpm", F_OK | R_OK) == -1
		|| access("textures/exit.xpm", F_OK | R_OK) == -1)
	{
		errno = 2;
		perror("Error\nFailed reading image file");
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_main		*main;

	if (argc != 2 || access(argv[1], F_OK | R_OK) == -1
		|| !ft_strncmp(argv[1] + ft_strlen(argv[1]) - 5, ".ber", 4))
	{
		errno = 2;
		perror("Error\nUsage: ./so_long maps/map.ber\n wrong map (.ber) file");
		exit(1);
	}
	check_files();
	main = main_init(argv[1]);
	ft_map_check(main);
	draw_map(main);
	mlx_hook(main->win, 2, 1, key_event, main);
	mlx_hook(main->win, 17, 0, ft_destroy, main);
	mlx_loop_hook(main->mlx, render_image, main);
	mlx_loop(main->mlx);
	return (0);
}
