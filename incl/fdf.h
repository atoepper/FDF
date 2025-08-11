/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoepper <atoepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:12:50 by atoepper          #+#    #+#             */
/*   Updated: 2024/04/29 17:03:57 by atoepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdbool.h>

# define HEIGHT 1080
# define WIDTH	1920

# define PI 3.141592

typedef struct	s_argb
{
	float		a;
	float		r;
	float		g;
	float		b;
}				t_argb;

typedef struct s_img
{
	void	*mlx;
	void	*win;
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_index
{
	int	x;
	int	y;
}				t_index;

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
	long	color;
}				t_vec;

typedef struct s_map
{
	t_img	img;
	char	*raw;
	t_index	max;
	short	max_z;
	short	min_z;
	t_vec	zoom;
	t_vec	rot;
	t_vec	offset;
	t_vec	center;
	t_vec	**transf;
	t_vec	**proj;
	double	**h;
	long	**col;
	long	**col_mod;
	bool	colored;
}				t_map;

/* parse */
int			read_map(int fd, t_map *map);
int			parse_line(char *line);
bool		parse_digit(char *s, unsigned *i);
bool		parse_color(char *s, unsigned *i);

/* fdf */
int		close_window(t_map *map);
int		fdf(t_map *map);
void	clear_window(t_map *map);

/* colors_basic */
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
int		create_trgb(int t, int r, int g, int b);

/* colors */
int		add_shade(double shade, int color);
int		gradient(float x, float y, t_vec a, t_vec b);

/* drawing */
void	put_pixel(t_img img, int x, int y, int color);
void	draw_line(t_img img, t_vec a, t_vec b);
void	draw_map(t_img img, t_map *map);

/* hooks */
int		key_hook(int k, t_map *map);
int		handle_no_event(void *map);
void	ch_scale_xy(int k, t_map *map);

/* calculus */
double	rot_rect_h(double alpha, double length, double width);
double	hypotenuse(double a, double b);
int		difx(t_vec a, t_vec b);
int		dify(t_vec a, t_vec b);
int		ft_round(double x);

/* projection */
int		transformation(t_map *map);
t_vec	rot(t_vec vec, t_vec rot, t_vec offset, t_vec zoom);

/* memory */
int		malloc_map(t_map *map);
void	free_map(t_map *map);
int		free_fail(char *line, int fd);
void	free_map_arr(t_map *map);

/* init */
void	get_height_color(t_map *map, char *raw);
long	get_colors(t_map *map, char **raw);
int		init_map(t_map *map);
void	set_default(t_map *map);

/* main */

/* test */
void	print_map(t_map *map);

#endif