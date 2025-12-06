/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoepper <atoepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:07:13 by atoepper          #+#    #+#             */
/*   Updated: 2025/12/06 14:40:27 by atoepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

static int	open_file(int argc, char **argv)
{
	int fd;

	if (argc != 2)
	{
		ft_putendl_fd("Usage: <filename>", 2);
		exit (EXIT_FAILURE);
	}
	if (access(argv[1], F_OK) != 0)
	{
		ft_putendl_fd("File does not exist.", 2);
		exit (EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Cannot open file", 2);
		exit (EXIT_FAILURE);
	}
	return (fd);
}

static void bzero_map(t_map *map)
{
	map->mlx = NULL;
	map->win = NULL;
	map->img_map = NULL;
	map->max_z = 0;
	map->min_z = 0;
	map->max.x = 0;
	map->max.y = 0;
	set_vector(&map->zoom, 0, 0, 0);
	set_vector(&map->rot, 0, 0, 0);
	set_vector(&map->offset, 0, 0, 0);
	set_vector(&map->center, 0, 0, 0);
	map->raw = NULL;
	map->proj = NULL;
	map->h = NULL;
	map->col = NULL;
	map->colored = false;
}

int	main(int argc, char **argv)
{
	int		fd;
	t_map	map;

	ft_printf("Open file...\n");
	fd = open_file(argc, argv);
	ft_printf("Initialize map...\n");
	bzero_map(&map);
	ft_printf("Parse file...\n");
	if (parse_map(fd, &map) == FAILURE)
		return(free_map(&map), EXIT_FAILURE);
	ft_printf("Parsing successful\n");
	/* Debug printing */
	print_map(&map);
	ft_printf("heights\n");
	print_2d_arr(map.h, map.max.x, map.max.y);
	ft_printf("colors\n");
	print_2d_arr(map.col, map.max.x, map.max.y);
	/* mlx and main loop */
	if (fdf(&map) == FAILURE)
	{
		ft_putendl_fd("Window's creation failed", 2);
		free_map(&map);
		return (free_map(&map), EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
	
	