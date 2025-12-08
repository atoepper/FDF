/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoepper <atoepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:53:58 by atoepper          #+#    #+#             */
/*   Updated: 2025/12/08 14:37:45 by atoepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

static void		translate(t_map *map, t_index i)
{
	t_vec	offset;

	offset = map->offset;
	map->proj[i.y][i.x].x += offset.x;
	map->proj[i.y][i.x].y += offset.y;
	map->proj[i.y][i.x].z += offset.z;
}

static void		rotate(t_map *map, t_index i)
{
	t_vec	rot;
	t_vec	temp;

	rot = map->rot;
	temp = map->proj[i.y][i.x];
	map->proj[i.y][i.x].x = (cos(rot.z) * temp.x - sin(rot.z) * temp.y);
	map->proj[i.y][i.x].y = (sin(rot.z) * temp.x + cos(rot.z) * temp.y);
	temp = map->proj[i.y][i.x];
	map->proj[i.y][i.x].x = cos(rot.y) * temp.x + sin(rot.y) * temp.z;
	map->proj[i.y][i.x].z = -sin(rot.y) * temp.x + cos(rot.y) * temp.z;
	temp = map->proj[i.y][i.x];
	map->proj[i.y][i.x].y = cos(rot.x) * temp.y - sin(rot.x) * temp.z;
	map->proj[i.y][i.x].z = sin(rot.x) * temp.y + cos(rot.x) * temp.z;
}

static void		zoom(t_map *map, t_index i)
{
	map->proj[i.y][i.x].x *= map->zoom.x;
	map->proj[i.y][i.x].y *= map->zoom.y;
	map->proj[i.y][i.x].z *= map->zoom.z;
}

static void		map_to_cartesian(t_map *map, t_index i)
{
	map->proj[i.y][i.x].x = ((double)i.x
			- (((double)map->max.x - 1) / 2));
	map->proj[i.y][i.x].y = ((double)i.y
			- (((double)map->max.y - 1) / 2));
	map->proj[i.y][i.x].z = map->h[i.y][i.x];
}

int	project_map(t_map *map)
{
	t_index	i;

	i.y = -1;
	while (++i.y < map->max.y)
	{
		i.x = -1;
		while (++i.x < map->max.x)
		{
			map_to_cartesian(map, i);
			zoom(map, i);
			rotate(map, i);
			translate(map, i);
		}
	}
	return (0);
}
