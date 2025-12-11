/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoepper <atoepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:30:55 by atoepper          #+#    #+#             */
/*   Updated: 2025/12/11 12:39:46 by atoepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

static void	clean_image(t_map *map, t_img *img)
{
	if (img)
	{
		if (img->mlx_img)
			mlx_destroy_image(map->mlx, img->mlx_img);
		free(img);
		img = NULL;
	}
}

void	cleanup(t_map *map)
{
	printf("\ndo cleanup\n");
	clean_image(map, map->img_map);
	if (map->win)
		mlx_destroy_window(map->mlx, map->win);
	if (map->mlx)
	{
		mlx_destroy_display(map->mlx);
		free(map->mlx);
	}
	free_map(map);
}

int	close_window(t_map *map)
{
	cleanup(map);
	exit(EXIT_SUCCESS);
	return (SUCCESS);
}
