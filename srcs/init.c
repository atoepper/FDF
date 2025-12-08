/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoepper <atoepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:39:19 by atoepper          #+#    #+#             */
/*   Updated: 2025/12/08 14:51:56 by atoepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

static void	import_colors(t_map *map)
{
	t_index	i;

	while (++i.y < map->max.y)
	{
		i.x = -1;
		while (++i.x < map->max.x)
			map->proj[i.y][i.x].z = map->col[i.y][i.x];
	}	
}

static void	calculate_default_zoom(t_map *map)
{
	// h = rot_rect_h(PI / 4, map->max.x, map->max.y);
	/* calculate zoom factor */
	
	// map->zoom.x = (HEIGHT - 50) / h;
	// if (map->zoom.x * hypotenuse(map->max.x, map->max.y)
	// 	> WIDTH - hypotenuse(map->max.x, map->max.y))
	// 	map->zoom.x = WIDTH - hypotenuse(map->max.x, map->max.y);
	// map->zoom.z = map->zoom.x / 2;	
}

static void	set_default(t_map *map)
{
	double	h;

	map->center.x = WIDTH / 2;
	map->center.y = HEIGHT / 2;
	map->center.z = 0;
	map->offset = map->center;
	map->rot.x = (atan(1 / sqrt(2)));
	map->rot.y = (0);
	map->rot.z = (PI / 4);
	calculate_default_zoom(map);
}

static void	malloc_projection(t_map *map)
{
	int	y;

	map->proj = malloc(sizeof(t_vec *) * map->max.y);
	if (!map->proj)
		exit_on_error(map, "Fatal error: malloc fail");
	y = 0;
	while (y < map->max.y)
	{
		map->proj[y] = malloc(sizeof(t_vec) * map->max.x);
		if (!map->proj[y++])
			exit_on_error(map, "Fatal error: malloc fail");
	}
}

int	init_map(t_map *map)
{
	t_index	i;

	malloc_projection(map);
	set_default(map);
	import_colors(map);
	project_map(map);
	return (SUCCESS);
}
