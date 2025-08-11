/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoepper <atoepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:07:13 by atoepper          #+#    #+#             */
/*   Updated: 2024/04/29 16:40:55 by atoepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

void	arg_check(int argc, char **argv, int *fd)
{
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
	*fd = open(argv[1], O_RDONLY);
	if (*fd == -1)
	{
		ft_putendl_fd("Cannot open file", 2);
		exit (EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	t_map	map;

	arg_check(argc, argv, &fd);
	if (!read_map(fd, &map))
		ft_putendl_fd("Invalid map", 2);
	if (!malloc_map(&map))
		ft_putendl_fd("Memory allocation failed", 2);
	else
	{
		get_height_color(&map, map.raw);
		if (fdf(&map) == -1)
		{
			ft_putendl_fd("Window's creation failed", 2);
			free_map(&map);
			return (1);
		}
	}
	return (0);
}
