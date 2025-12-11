/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoepper <atoepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:49:18 by atoepper          #+#    #+#             */
/*   Updated: 2025/12/11 13:44:03 by atoepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

static void	move_with_key(int k, t_map *map)
{
	if (k == 'a')
		map->mov.xmove = -1;
	else if (k == 'd')
		map->mov.xmove = 1;
	if (k == 'w')
		map->mov.ymove = -1;
	else if (k == 's')
		map->mov.ymove = 1;
}

void	move_map(t_map *map)
{
	map->rot.z += map->mov.z_rotate * PI / 10;
	if (map->rot.z >= PI * 2)
		map->rot.z -= PI * 2;
	map->rot.x += map->mov.x_rotate * PI / 10;
	if (map->rot.x >= PI * 2)
		map->rot.x -= PI * 2;
	map->offset.x += map->mov.xmove;
	map->offset.y += map->mov.ymove;
	map->zoom.x += map->mov.zoom;
	map->zoom.y += map->mov.zoom;
	// map->zoom.z += map->mov.zoom;
}

int	key_release(int k, t_map *map)
{
	(void)k;
	(void)map;
	if (k == 'a')
		map->mov.xmove = 0;
	else if (k == 'd')
		map->mov.xmove = 0;
	if (k == 'w')
		map->mov.ymove = 0;
	else if (k == 's')
		map->mov.ymove = 0;
	if (k == XK_Left)
		map->mov.z_rotate = 0;
	else if (k == XK_Right)
		map->mov.z_rotate = 0;
	if (k == XK_Up)
		map->mov.x_rotate = 0;
	else if (k == XK_Down)
		map->mov.x_rotate = 0;
	if (k == '-')
		map->mov.zoom = 0;
	else if (k == '=')
		map->mov.zoom = 0;
	return (0);
}

int	key_press(int k, t_map *map)
{
	if (k == XK_Escape && map->mlx)
		close_window(map);
	if (k == 'a' || k == 'd' || k == 'w' || k == 's')
		move_with_key(k, map);
	if (k == XK_Left)
		map->mov.z_rotate = 1;
	else if (k == XK_Right)
		map->mov.z_rotate = -1;
	if (k == XK_Up)
		map->mov.x_rotate = 1;
	else if (k == XK_Down)
		map->mov.x_rotate = -1;
	if (k == '-')
		map->mov.zoom = -1;
	else if (k == '=')
		map->mov.zoom = 1;
	return (SUCCESS);
}

void	set_hooks(t_map *map)
{
	mlx_hook(map->win, DestroyNotify, StructureNotifyMask,
		&close_window, map);
	mlx_hook(map->win, KeyRelease, KeyReleaseMask, &key_release, map);
	mlx_hook(map->win, KeyPress, KeyPressMask, &key_press, map);
	mlx_loop_hook(map->mlx, &main_loop, map);
}
