/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoepper <atoepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:39:19 by atoepper          #+#    #+#             */
/*   Updated: 2024/04/29 16:39:03 by atoepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

void	set_default(t_map *map)
{
	double	h;

	map->center.x = WIDTH / 2;
	map->center.y = HEIGHT / 2;
	map->center.z = 0;
	map->rot.x = (atan(1 / sqrt(2)));
	map->rot.y = (0);
	map->rot.z = (PI / 4);
	h = rot_rect_h(PI / 4, map->max.x, map->max.y);
	map->zoom.x = (HEIGHT - 50) / h;
	if (map->zoom.x * hypotenuse(map->max.x, map->max.y)
		> WIDTH - hypotenuse(map->max.x, map->max.y))
		map->zoom.x = WIDTH - hypotenuse(map->max.x, map->max.y);
	map->zoom.z = map->zoom.x / 2;
}

int	init_map(t_map *map)
{
	t_index	i;

	i.y = -1;
	while (++i.y < map->max.y)
	{
		i.x = -1;
		while (++i.x < map->max.x)
		{
			map->transf[i.y][i.x].x = ((double)i.x
					- (((double)map->max.x - 1) / 2));
			map->transf[i.y][i.x].y = ((double)i.y
					- (((double)map->max.y - 1) / 2));
			map->transf[i.y][i.x].z = map->h[i.y][i.x];
		}
	}
	set_default(map);
	transformation(map);
	return (0);
}

long	get_colors(t_map *map, char **raw)
{
	size_t	n;
	int		c;

	n = 0;
	if (!*raw || **raw != ',')
		return (0xaaaaaa);
	*raw += 3;
	while (*(*raw + n) && (ft_ishex(*(*raw + n))))
		n++;
	c = ft_hextoi(*raw, n);
	*raw += n;
	map->colored = true;
	return (c);
}

void	get_height_color(t_map *map, char *raw)
{
	t_index	i;

	map->min_z = 0;
	map->max_z = 0;
	i.y = -1;
	while (++i.y < map->max.y)
	{
		i.x = -1;
		while (++i.x < map->max.x)
		{
			while (*raw && (*raw == ' ' || *raw == '\n'))
				++raw;
			map->h[i.y][i.x] = ft_atoi(raw);
			if (map->h[i.y][i.x] > map->max_z)
				map->max_z = map->h[i.y][i.x];
			if (map->h[i.y][i.x] < map->min_z)
				map->min_z = map->h[i.y][i.x];
			while (*raw && (ft_isdigit(*raw) || *raw == '-'))
				++raw;
			map->transf[i.y][i.x].color = get_colors(map, &raw);
		}
	}
}
