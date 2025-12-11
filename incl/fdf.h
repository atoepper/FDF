/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoepper <atoepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:12:50 by atoepper          #+#    #+#             */
/*   Updated: 2025/12/11 14:42:04 by atoepper         ###   ########.fr       */
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
# include <sys/time.h>
# include <fcntl.h>
# include <stdbool.h>

# define SUCCESS 0
# define FAILURE 1

# define HEIGHT 1080
# define WIDTH	1920

# define PI		3.141592

typedef struct s_argb
{
	float		a;
	float		r;
	float		g;
	float		b;
}				t_argb;

typedef struct s_img
{
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

typedef struct s_move
{
	double	xmove;
	double	ymove;
	int		z_rotate;
	int		x_rotate;
	double	zoom;
	double	zscale;
}				t_move;

typedef struct s_map
{
	void	*mlx;
	void	*win;
	t_img	*img_map;
	char	*raw;
	short	max_z;
	short	min_z;
	t_index	max;
	t_move	mov;
	t_vec	zoom;
	t_vec	rot;
	t_vec	offset;
	t_vec	center;
	t_vec	**proj;
	long	**h;
	long	**col;
	bool	colored;
}				t_map;

/* calculus */
double	rot_rect_h(double alpha, double length, double width);
double	hypotenuse(double a, double b);
int		difx(t_vec a, t_vec b);
int		dify(t_vec a, t_vec b);
int		ft_round(double x);

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
void	put_pixel(t_img *img, int x, int y, int color);
void	draw_line(t_img *img, t_vec a, t_vec b);

/* error */
void	exit_on_error(t_map *map, char *str);

/* endmap */
void	cleanup(t_map *map);
int		close_window(t_map *map);

/* fdf */
int		fdf(t_map *map);
void	clear_window(t_map *map);
t_img	*create_image(t_map *map, int width, int height);
int		start_mlx(t_map *map);

/* hooks */
void	set_hooks(t_map *map);
void	move_map(t_map *map);

/* init */
int		init_map(t_map *map);

/* loop */
int		main_loop(t_map *map);

/* memory */
void	free_map(t_map *map);
void	free_map_arr(t_map *map);
void	free_raw(char ***raw);
long	**add_row(long **arr, int old_rows, int new_cols);
void	free_fd(char *line, int fd);

/* parse_map */
int		parse_map(int fd, t_map *map);

/* parse_utils */
bool	is_numeric(char *s);
bool	is_color(char *s);
int		get_color(char *s);

/* projection */
int		project_map(t_map *map);

/* render_map */
void	draw_map(t_img *img, t_map *map);
void	update_window(t_map *map);

/* test */
void	print_map(t_map *map);

/* time */
double	get_timestamp(void);

/* utils */
void	print_2d_arr(long **arr, size_t x, size_t y);
int		arr_size(char **arr);
void	print_map(t_map *map);

/* vector */
void	set_vector(t_vec *v, double x, double y, double z);
void	print_vector(t_vec v);

#endif
