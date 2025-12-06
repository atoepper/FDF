/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoepper <atoepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:49:18 by atoepper          #+#    #+#             */
/*   Updated: 2025/12/06 14:46:30 by atoepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

// void	ch_zoom(int k, t_map *map)
// {
// 	if (k == 61)
// 	{
// 		map->zoom.x += 0.2;
// 		map->zoom.z += 0.1;
// 	}
// 	else if (k == 45)
// 	{
// 		map->zoom.x -= 0.2;
// 		map->zoom.z -= 0.1;
// 	}
// }

// void	ch_rot(int k, t_map *map)
// {
// 	if (k == XK_Left)
// 		map->rot.z += PI / 40;
// 	else if (k == XK_Right)
// 		map->rot.z -= PI / 40;
// 	else if (k == XK_Up)
// 		map->rot.x += atan(1 / sqrt(2)) / 20;
// 	else if (k == XK_Down)
// 		map->rot.x -= atan(1 / sqrt(2)) / 20;
// }

// void	ch_center(int k, t_map *map)
// {
// 	if (k == 'a')
// 		map->center.x -= WIDTH / 200;
// 	if (k == 'd')
// 		map->center.x += WIDTH / 200;
// 	if (k == 's')
// 		map->center.y += HEIGHT / 200;
// 	if (k == 'w')
// 		map->center.y -= HEIGHT / 200;
// }

// void	ch_scale(int k, t_map *map)
// {
// 	if (k == XK_Page_Up)
// 		map->zoom.z += (HEIGHT / (40 * (abs(map->max_z - map->min_z)) + 0.5));
// 	else if (k == XK_Page_Down)
// 		map->zoom.z -= (HEIGHT / (40 * (abs(map->max_z - map->min_z)) + 0.5));
// }

// int	key_hook(int k, t_map *map)
// {
// 	if (k == XK_Escape && map->img.mlx)
// 		close_window(map);
// 	if ((k == 45 || k == 61) && map->img.mlx)
// 		ch_zoom(k, map);
// 	else if (k == XK_Left || k == XK_Right || k == XK_Up || k == XK_Down)
// 		ch_rot(k, map);
// 	else if (k == 'a' || k == 'w' || k == 's' || k == 'd')
// 		ch_center(k, map);
// 	else if ((k == XK_Page_Down || k == XK_Page_Up) && map->img.mlx)
// 		ch_scale(k, map);
// 	else if ((k == XK_x || k == XK_z) && map->img.mlx)
// 		ch_scale_xy(k, map);
// 	clear_window(map);
// 	transformation(map);
// 	draw_map(map->img, map);
// 	mlx_put_image_to_window(map->img.mlx, map->img.win, map->img.mlx_img, 0, 0);
// 	return (0);
// }

// int		mouse_hook(int m, t_map *map)
// {
// 	clear_window(map);
// 	if (m == 5)
// 	{
// 		printf("adress: %f\n", map->zoom.x);
// 		map->zoom.x += 0.2;
// 		map->zoom.z += 0.1;
// 		return (0);
// 	}
// 	else if (m == 4)
// 	{
// 		printf("scroll up\n");
// 		map->zoom.x -= 0.2;
// 		map->zoom.z -= 0.1;
// 	}
// 	transformation(map);
// 	draw_map(map->img, map);
// 	mlx_put_image_to_window(map->img.mlx, map->img.win, map->img.mlx_img, 0, 0);
// 	return (0);
// }

int	close_window(t_map *map)
{
	cleanup(map);
	exit(EXIT_SUCCESS);
	return (0);
}

int	main_loop(t_map *map)
{
	(void)map;
	// static double	timestamp = 0;
	// static double	timestamp_move = 0;

	// if (get_timestamp() - timestamp_move > 1.0 / (double)data->sps)
	// {
	// 	move(data);
	// 	rotate(data);
	// 	timestamp_move = get_timestamp();
	// }
	// if (get_timestamp() - timestamp > 1.0 / (double)data->fps)
	// {
	// 	clear_window(data);
	// 	update_window(data);
	// 	timestamp = get_timestamp();
	// }
	return (SUCCESS);
}

void	set_hooks(t_map *map)
{
	mlx_hook(map->win, DestroyNotify, StructureNotifyMask,
		&close_window, map);
	// mlx_hook(data->win, KeyRelease, KeyReleaseMask, &key_release, data);
	// mlx_hook(data->win, KeyPress, KeyPressMask, &key_press, data);
	mlx_loop_hook(map->mlx, &main_loop, map);
}