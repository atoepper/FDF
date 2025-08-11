/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoepper <atoepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:49:22 by atoepper          #+#    #+#             */
/*   Updated: 2024/11/25 10:37:39 by atoepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

int	close_window(t_map *map)
{
	mlx_destroy_image(map->img.mlx, map->img.mlx_img);
	mlx_destroy_window(map->img.mlx, map->img.win);
	mlx_destroy_display(map->img.mlx);
	free(map->img.mlx);
	free_map(map);
	exit (0);
	return (0);
}

void	clear_window(t_map *map)
{
	mlx_destroy_image(map->img.mlx, map->img.mlx_img);
	map->img.mlx_img = mlx_new_image(map->img.mlx, WIDTH, HEIGHT);
	map->img.addr = mlx_get_data_addr(map->img.mlx_img, &map->img.bpp,
			&map->img.line_length, &map->img.endian);
}

int	start_mlx(t_map *map)
{
	map->img.mlx = mlx_init();
	if (map->img.mlx == NULL)
		return (-1);
	map->img.win = mlx_new_window(map->img.mlx,
			WIDTH, HEIGHT, "FdF - a 3D project");
	if (map->img.win == NULL)
		return (-1);
	map->img.mlx_img = mlx_new_image(map->img.mlx, WIDTH, HEIGHT);
	if (map->img.mlx_img == NULL)
		return (-1);
	map->img.addr = mlx_get_data_addr(map->img.mlx_img, &map->img.bpp,
			&map->img.line_length, &map->img.endian);
	return (0);
}

void	set_hooks(t_map *map)
{
	mlx_loop_hook(map->img.mlx, &handle_no_event, map);
	mlx_hook(map->img.win, DestroyNotify, StructureNotifyMask,
		&close_window, map);
	mlx_key_hook(map->img.win, key_hook, map);
}

int	fdf(t_map *map)
{
	if (start_mlx(map) == -1)
		return (-1);
	init_map(map);
	// draw_map(map->img, map);

	put_pixel(map->img, WIDTH/2, HEIGHT/2, create_trgb(0, 255, 0, 0));
	mlx_put_image_to_window(map->img.mlx, map->img.win, map->img.mlx_img, 0, 0);
	set_hooks(map);
	mlx_loop(map->img.mlx);
	return (0);
}
