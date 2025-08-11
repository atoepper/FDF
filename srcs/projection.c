/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoepper <atoepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:53:58 by atoepper          #+#    #+#             */
/*   Updated: 2024/04/29 16:40:32 by atoepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

t_vec	rot(t_vec vec, t_vec rot, t_vec offset, t_vec zoom)
{
	t_vec	p;
	t_vec	temp;

	temp.x = zoom.x * vec.x;
	temp.y = zoom.x * vec.y;
	p.x = (cos(rot.z) * temp.x - sin(rot.z) * temp.y);
	p.y = (sin(rot.z) * temp.x + cos(rot.z) * temp.y);
	p.z = vec.z * zoom.z;
	temp = p;
	p.x = cos(rot.y) * temp.x + sin(rot.y) * temp.z;
	p.z = -sin(rot.y) * temp.x + cos(rot.y) * temp.z;
	temp = p;
	p.y = cos(rot.x) * temp.y - sin(rot.x) * temp.z;
	p.z = sin(rot.x) * temp.y + cos(rot.x) * temp.z;
	p.x += offset.x;
	p.y += offset.y;
	p.color = vec.color;
	return (p);
}

int	transformation(t_map *map)
{
	t_index	i;

	i.y = -1;
	while (++i.y < map->max.y)
	{
		i.x = -1;
		while (++i.x < map->max.x)
		{
			map->proj[i.y][i.x] = rot(map->transf[i.y][i.x],
					map->rot, map->center, map->zoom);
		}
	}
	return (0);
}
