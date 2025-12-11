/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoepper <atoepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:49:22 by atoepper          #+#    #+#             */
/*   Updated: 2025/12/11 12:43:00 by atoepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

t_img	*create_image(t_map *map, int width, int height)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (img == NULL)
		exit_on_error(map, "fatal: malloc error");
	img->mlx_img = mlx_new_image(map->mlx, width, height);
	if (img == NULL)
		exit_on_error(map, "Image creation failed");
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp,
			&img->line_length, &img->endian);
	return (img);
}

void	clear_window(t_map *map)
{
	mlx_destroy_image(map->mlx, map->img_map->mlx_img);
	map->img_map->mlx_img = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	map->img_map->addr = mlx_get_data_addr(map->img_map->mlx_img,
			&map->img_map->bpp, &map->img_map->line_length,
			&map->img_map->endian);
}

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
	ft_printf("Start mlx...\n");
	start_mlx(map);
	ft_printf("Init map...\n");
	init_map(map);
	map->img_map = create_image(map, WIDTH,
			HEIGHT);
	ft_printf("Create first view...\n");
	draw_map(map->img_map, map);
	create_window(map);
	ft_printf("Render first view...\n");
	mlx_put_image_to_window(map->mlx, map->win, map->img_map->mlx_img, 0, 0);
	ft_printf("Set hooks...\n");
	set_hooks(map);
	ft_printf("Start loop...\n");
	mlx_loop(map->mlx);
	return (0);
}
