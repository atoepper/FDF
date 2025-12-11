/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoepper <atoepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:07:13 by atoepper          #+#    #+#             */
/*   Updated: 2025/12/11 12:29:10 by atoepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

static int	open_file(int argc, char **argv)
{
	int	fd;

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

int	main(int argc, char **argv)
{
	int		fd;
	t_map	map;

	ft_printf("Open file...\n");
	fd = open_file(argc, argv);
	ft_bzero(&map, sizeof(map));
	ft_printf("Parse file...\n");
	if (parse_map(fd, &map) == FAILURE)
		return (free_map(&map), EXIT_FAILURE);
	ft_printf("Parsing successful\n");
	if (fdf(&map) == FAILURE)
	{
		ft_putendl_fd("Window's creation failed", 2);
		free_map(&map);
		return (free_map(&map), EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
