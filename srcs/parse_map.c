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
	char **token;

	if (!raw)
		return (FAILURE);
	token = ft_split(raw[pos - 1], ',');
	if (!token)
		return (ft_putstr_fd("Fatal error in ft_split\n", 2), FAILURE);
	if (is_numeric(token[0]))
		map->h[map->max.y][pos - 1] = ft_atoi(token[0]);
	else
		return (free_raw(&token), FAILURE);
	if (arr_size(token) == 1)
		map->col[map->max.y][pos - 1] = 0;
	else if (arr_size(token) == 2) 
	{
		if (is_color(token[1]))
			map->col[map->max.y][pos - 1] = get_color(token[1]);
		else
			return (free_raw(&token), FAILURE);
	}
	if (arr_size(token) > 2)
		return (free_raw(&token), FAILURE);
	free_raw(&token);
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
	while (len > 0)
	{
		if (parse_token(map, raw, len--) == FAILURE)
		{
			ft_putstr_fd("Parse error: malformed line\n", 2);
			return (free_raw(&raw), FAILURE);
		}
	}
	map->max.y++;
	free_raw(&raw);
	return (SUCCESS);
}

int parse_map (int fd, t_map *map)
{
	char	*line;
	char	*trimmed;

	line = get_next_line(fd);
	while (line)
	{
		trimmed = ft_strtrim(line, "\n");
		if (parse_line(trimmed, map) == FAILURE)
		{
			free(trimmed);
			free_fd(line, fd);
			return(FAILURE);
		}
		free(trimmed);
		free(line);
		line = get_next_line(fd);
	}
	free (line);
	close (fd);
	return (SUCCESS);
}