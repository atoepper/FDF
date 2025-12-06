/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoepper <atoepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:49:22 by atoepper          #+#    #+#             */
/*   Updated: 2025/12/06 14:51:36 by atoepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

// int	close_window(t_map *map)
// {
// 	mlx_destroy_image(map->img.mlx, map->img.mlx_img);
// 	mlx_destroy_window(map->img.mlx, map->img.win);
// 	mlx_destroy_display(map->img.mlx);
// 	free(map->img.mlx);
// 	free_map(map);
// 	exit (0);
// 	return (0);
// }

// void	clear_window(t_map *map)
// {
// 	mlx_destroy_image(map->img.mlx, map->img.mlx_img);
// 	map->img.mlx_img = mlx_new_image(map->img.mlx, WIDTH, HEIGHT);
// 	map->img.addr = mlx_get_data_addr(map->img.mlx_img, &map->img.bpp,
// 			&map->img.line_length, &map->img.endian);
// }

void	create_window(t_map *map)
{
	map->win = mlx_new_window(map->mlx,
			WIDTH, HEIGHT, "FDF - A wireframe model");
	if (map->win == NULL)
		exit_on_error(map, "Window creation failed");
}

int	start_mlx(t_map *map)
{
	map->mlx = mlx_init();
	if (map->mlx == NULL)
		exit_on_error(map, "Mlx creation failed");
	return (SUCCESS);
}

int	fdf(t_map *map)
{
	(void)map;
	start_mlx(map);
	// init_map(map);
	// draw_map(map->img, map);

	// put_pixel(map->img, WIDTH/2, HEIGHT/2, create_trgb(0, 255, 0, 0));
	// mlx_put_image_to_window(map->img.mlx, map->img.win, map->img.mlx_img, 0, 0);
	create_window(map);
	set_hooks(map);
	mlx_loop(map->mlx);
	// cleanup(map);
	return (0);
}
