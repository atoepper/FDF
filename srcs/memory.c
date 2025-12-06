/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoepper <atoepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:37:29 by atoepper          #+#    #+#             */
/*   Updated: 2025/12/06 10:28:16 by atoepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

void	free_map_arr(t_map *map)
{
	if (map->proj)
		free(map->proj);
	if (map->h)
		free(map->h);
	if (map->col)
		free(map->col);
}

void	free_map(t_map *map)
{
	int	i;

	if (map->raw)
		free(map->raw);
	i = -1;
	print_map(map);
	while (++i < map->max.y)
	{
		ft_printf("Debug free i: %d\n", i);
		if (map->proj != NULL && map->proj[i])
			free(map->proj[i]);
		if (map->h != NULL && map->h[i])
			free(map->h[i]);
		if (map->col != NULL && map->col[i])
			free(map->col[i]);
	}
	free_map_arr(map);
}


// int	malloc_map(t_map *map)
// {
// 	t_index	i;

// 	map->proj = (t_vec **)malloc(sizeof(t_vec *) * map->max.y);
// 	map->h = (double **)malloc(sizeof(double *) * map->max.y);
// 	map->col = (long **)malloc(sizeof(long *) * map->max.y);
// 	if (!map->proj || !map->h || !map->col)
// 		return (0);
// 	i.y = -1;
// 	while (++i.y < map->max.y)
// 	{
// 		map->proj[i.y] = (t_vec *)malloc(sizeof(t_vec) * map->max.x);
// 		map->h[i.y] = (double *)malloc(sizeof(double) * map->max.x);
// 		map->col[i.y] = (long *)malloc(sizeof(long) * map->max.x);
// 		if (!map->proj[i.y] || !map->h[i.y]
// 			|| !map->col[i.y])
// 			return (0);
// 	}
// 	return (1);
// }

// int	free_fail(char *line, int fd)
// {
// 	while (line)
// 	{
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// 	return (0);
// }

long **add_row(long **arr, int old_rows, int new_cols)
{
	long **new_arr;
	int i;

	new_arr = malloc(sizeof(long *) * (old_rows + 2));
	if (!new_arr)
		return (NULL);
	i = 0;
	while (i < old_rows)
	{
		new_arr[i] = arr[i];
		i++;
	}
	new_arr[old_rows] = malloc(sizeof(long) * new_cols);
	if (!new_arr[old_rows])
		return (free(new_arr), NULL);
	new_arr[old_rows + 1] = NULL;
	free(arr);
	return (new_arr);
}

void free_raw(char ***raw)
{
    int i;
    char **tmp;

    if (!raw || !*raw)
        return;

    tmp = *raw;
    i = 0;
    while (tmp[i])
    {
        free(tmp[i]);
        tmp[i++] = NULL;
    }
    free(tmp);
    *raw = NULL;
}

void free_fd(char *line, int fd)
{
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
}