#include "../incl/fdf.h"

int	add_rows_to_map(t_map *map, size_t len)
{
	map->h = add_row(map->h, map->max.y, len);
	map->col = add_row(map->col, map->max.y, len);
	if (!map->h || !map->col)
		return (ft_putstr_fd("Fatal error in add_row\n", 2), FAILURE);
	return (SUCCESS);
}

static int parse_token(t_map *map, char **raw, int pos)
{
	if (!raw)
		return (FAILURE);
	map->col[map->max.y][pos - 1] = pos;
	map->h[map->max.y][pos - 1] = pos;
	return(SUCCESS);
}

static int check_line_len(t_map *map, int len)
{
	if ((map->max.x != 0 && map->max.x != len))
	{
		ft_putstr_fd("Parse error in line ", 2);
		ft_putnbr_fd(map->max.y, 2);
		ft_putstr_fd(": wrong line length\n", 2);
		return (FAILURE);
	}
	if (map->max.x == 0)
		map->max.x = len;
	return (SUCCESS);
}

static int parse_line(char *line, t_map *map)
{
	char	**raw;
	int		len;

	raw = ft_split(line, ' ');
	if (!raw)
		return (ft_putstr_fd("Fatal error in ft_split\n", 2), FAILURE);
	len = arr_size(raw);
	if (check_line_len(map, len) == FAILURE || 
		add_rows_to_map(map, len) == FAILURE)
		return (free_raw(&raw), FAILURE);
	while (len >= 0)
		if (parse_token(map, raw, len--) == FAILURE)
			return (free_raw(&raw), FAILURE);
	map->max.y++;
	free_raw(&raw);
	return (SUCCESS);
}

int parse_map (int fd, t_map *map)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (parse_line(line, map) == FAILURE)
			return(free(line), FAILURE);
		free(line);
		line = get_next_line(fd);
	}
	free (line);
	close (fd);
	return (SUCCESS);
}