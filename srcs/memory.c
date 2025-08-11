/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoepper <atoepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:37:29 by atoepper          #+#    #+#             */
/*   Updated: 2024/04/24 11:59:54 by atoepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

void	free_map_arr(t_map *map)
{
	if (map->transf)
		free(map->transf);
	if (map->proj)
		free(map->proj);
	if (map->h)
		free(map->h);
	if (map->col)
		free(map->col);
	if (map->col_mod)
		free(map->col_mod);
}

void	free_map(t_map *map)
{
	int	i;

	if (map->raw)
		free(map->raw);
	i = -1;
	while (++i < map->max.y)
	{
		if (map->transf[i])
			free(map->transf[i]);
		if (map->proj[i])
			free(map->proj[i]);
		if (map->h[i])
			free(map->h[i]);
		if (map->col[i])
			free(map->col[i]);
		if (map->col_mod[i])
			free(map->col_mod[i]);
	}
	free_map_arr(map);
}

int	malloc_map(t_map *map)
{
	t_index	i;

	map->transf = (t_vec **)malloc(sizeof(t_vec *) * map->max.y);
	map->proj = (t_vec **)malloc(sizeof(t_vec *) * map->max.y);
	map->h = (double **)malloc(sizeof(double *) * map->max.y);
	map->col = (long **)malloc(sizeof(long *) * map->max.y);
	map->col_mod = (long **)malloc(sizeof(long *) * map->max.y);
	if (!map->transf || !map->proj || !map->h || !map->col || !map->col_mod)
		return (0);
	i.y = -1;
	while (++i.y < map->max.y)
	{
		map->transf[i.y] = (t_vec *)malloc(sizeof(t_vec) * map->max.x);
		map->proj[i.y] = (t_vec *)malloc(sizeof(t_vec) * map->max.x);
		map->h[i.y] = (double *)malloc(sizeof(double) * map->max.x);
		map->col[i.y] = (long *)malloc(sizeof(long) * map->max.x);
		map->col_mod[i.y] = (long *)malloc(sizeof(long) * map->max.x);
		if (!map->transf[i.y] || !map->proj[i.y] || !map->h[i.y]
			|| !map->col[i.y] || !map->col_mod[i.y])
			return (0);
	}
	return (1);
}

int	free_fail(char *line, int fd)
{
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
