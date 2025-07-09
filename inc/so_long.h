/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakunwar <nakunwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 22:29:06 by nakunwar          #+#    #+#             */
/*   Updated: 2025/07/08 20:00:55 by nakunwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include <unistd.h>

# ifdef __APPLE__
#  include "../minilibx-mac/mlx.h"
#  define W_UP 13
#  define S_DOWN 1
#  define A_LEFT 0
#  define D_RIGHT 2
#  define ESC 53
# endif

# define PIXEL 64

typedef struct s_img
{
	void			*wall;
	void			*way;
	void			*cup;
	void			*exitd;
	void			*enemy;
	void			*pr;
	void			*pl;
	void			*ple;
	void			*pu;
	void			*pd;
}					t_img;

typedef struct s_map
{
	char			**map;
	int				x;
	int				y;
}					t_map;

typedef struct s_main
{
	void			*mlx;
	void			*win;
	int				p_x;
	int				p_y;
	int				cup_count;
	int				movecount;
	int				playercount;
	int				exitcount;
	int				tmp;
	int				exitflag;
	t_map			*map;
	t_img			*img;
}					t_main;

t_main				*main_init(char *path);
char				**map_init(char *path, t_main *main);
void				ft_map_check(t_main *main);
void				draw_map(t_main *main);
void				xpm_to_img(t_main *main);
int					key_event(int key, t_main *main);
int					render_image(t_main *main);
void				write_move_count(t_main *main);
void				ft_error(char *errorcode, t_main *main);
void				*ft_calloc(size_t count, size_t size);
size_t				ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_itoa(int n);
int					ft_destroy(t_main *main);

#endif