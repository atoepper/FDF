/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoepper <atoepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:37:29 by atoepper          #+#    #+#             */
/*   Updated: 2025/12/11 12:33:31 by atoepper         ###   ########.fr       */
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
	while (++i < map->max.y)
	{
		if (map->proj != NULL && map->proj[i])
			free(map->proj[i]);
		if (map->h != NULL && map->h[i])
			free(map->h[i]);
		if (map->col != NULL && map->col[i])
			free(map->col[i]);
	}
	free_map_arr(map);
}

long	**add_row(long **arr, int old_rows, int new_cols)
{
	long	**new_arr;
	int		i;

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

void	free_raw(char ***raw)
{
	int		i;
	char	**tmp;

	if (!raw || !*raw)
		return ;
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

void	free_fd(char *line, int fd)
{
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
