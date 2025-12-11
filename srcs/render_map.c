/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoepper <atoepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:29:23 by atoepper          #+#    #+#             */
/*   Updated: 2025/12/11 12:30:39 by atoepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

void	draw_map(t_img *img, t_map *map)
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

void	update_window(t_map *map)
{
	draw_map(map->img_map, map);
	mlx_put_image_to_window(map->mlx, map->win,
		map->img_map->mlx_img, 0, 0);
}
