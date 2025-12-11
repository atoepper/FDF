/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoepper <atoepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:42:21 by atoepper          #+#    #+#             */
/*   Updated: 2025/12/11 12:44:00 by atoepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

void	print_2d_arr(long **arr, size_t x, size_t y)
{
	size_t	i;
	size_t	j;

	if (!arr)
	{
		ft_printf("Empty Array\n");
		return ;
	}
	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			ft_printf("%d\t", arr[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

int	arr_size(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
		i++;
	return (i);
}

void	print_map(t_map *map)
{
	t_index	i;

	if (map->max_z && map->min_z)
		ft_printf("min-z: %d, max_z: %d\n", map->min_z, map->max_z);
	if (map->max.x && map->max.y)
		ft_printf("max.x: %d, max.y: %d\n", map->max.x, map->max.y);
	printf("ZOOM: x: %f, y: %f, z: %f\n", map->zoom.x, map->zoom.y,
		map->zoom.z);
	printf("ROTATION: x: %f, y: %f, z: %f\n", map->rot.x, map->rot.y,
		map->rot.z);
	printf("OFFSET: x: %f, y: %f, z: %f\n", map->offset.x, map->offset.y,
		map->offset.z);
	printf("Projection:\n");
	i.y = -1;
	while (++i.y < map->max.y)
	{
		i.x = -1;
		while (++i.x < map->max.x)
		{
			print_vector(map->proj[i.y][i.x]);
		}
		ft_printf("\n");
	}
}
