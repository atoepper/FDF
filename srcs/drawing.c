/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoepper <atoepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:12:01 by atoepper          #+#    #+#             */
/*   Updated: 2024/04/29 13:36:49 by atoepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

void	put_pixel(t_img img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x <= WIDTH && y >= 0 && y <= HEIGHT)
	{
		dst = img.addr + (y * img.line_length + x * (img.bpp / 8));
		*(int *)dst = color;
	}
}

static void	small_slope(t_img img, t_vec a, t_vec b)
{
	int	p;
	int	i;
	int	x;
	int	y;

	i = 0;
	x = a.x;
	y = a.y;
	p = 2 * abs(dify(a, b)) - abs(difx(a, b));
	put_pixel(img, x, y, a.color);
	while (i < abs(difx(a, b)))
	{
		x += (difx(a, b) >= 0) - (difx(a, b) < 0);
		if (p <= 0)
			p = p + 2 * abs(dify(a, b));
		else
		{
			y -= (dify(a, b) < 0) - (dify(a, b) >= 0);
			p = p + 2 * abs(dify(a, b)) - 2 * abs(difx(a, b));
		}
		put_pixel(img, x, y, gradient(x, y, a, b));
		i++;
	}
}

static void	big_slope(t_img img, t_vec a, t_vec b)
{
	int	p;
	int	i;
	int	x;
	int	y;

	i = 0;
	x = a.x;
	y = a.y;
	p = 2 * abs(difx(a, b)) - abs(dify(a, b));
	put_pixel(img, a.x, a.y, a.color);
	while (i < abs(dify(a, b)))
	{
		y -= (dify(a, b) < 0) - (dify(a, b) >= 0);
		if (p < 0)
			p = p + 2 * abs(difx(a, b));
		else
		{
			x += (difx(a, b) >= 0) - (difx(a, b) < 0);
			p = p + 2 * abs(difx(a, b)) - 2 * abs(dify(a, b));
		}
		put_pixel(img, x, y, gradient(x, y, a, b));
		i++;
	}
}

void	draw_line(t_img img, t_vec a, t_vec b)
{
	if (abs(difx(a, b)) > abs(dify(a, b)))
		small_slope(img, a, b);
	else
		big_slope(img, a, b);
}

void	draw_map(t_img img, t_map *map)
{
	t_index	i;

	i.y = -1;
	while (++i.y < map->max.y)
	{
		i.x = -1;
		while (++i.x < map->max.x)
		{
			if (i.y < map->max.y - 1)
				draw_line(img, map->proj[i.y][i.x], map->proj[i.y + 1][i.x]);
			if (i.x < map->max.x - 1)
				draw_line(img, map->proj[i.y][i.x], map->proj[i.y][i.x + 1]);
		}
	}
}
