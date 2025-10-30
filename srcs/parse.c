/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoepper <atoepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:49:14 by atoepper          #+#    #+#             */
/*   Updated: 2025/10/30 17:02:45 by atoepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

// static char	*connect_lines(char *s1, char *s2)
// {
// 	char	*line;
// 	char	*tmp;

// 	tmp = ft_strjoin(s1, " ");
// 	line = ft_strjoin(tmp, s2);
// 	free(tmp);
// 	free(s1);
// 	free(s2);
// 	return (line);
// }

// int	read_map(int fd, t_map *map)
// {
// 	char	*line;
// 	bool	first_line;

// 	first_line = true;
// 	map->max.y = 0;
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		if (first_line)
// 		{
// 			map->raw = ft_strdup(line);
// 			map->max.x = parse_line(line);
// 			free(line);
// 		}
// 		else if (map->max.x != parse_line(line))
// 			return (free_fail(line, fd));
// 		if (!first_line)
// 			map->raw = connect_lines(map->raw, line);
// 		line = get_next_line(fd);
// 		first_line = false;
// 		map->max.y++;
// 	}
// 	close(fd);
// 	free(line);
// 	return (1);
// }

// int	parse_line(char *line)
// {
// 	unsigned int	i;
// 	int				len;

// 	i = 0;
// 	len = 0;
// 	while (line[i] && line[i] != '\n')
// 	{
// 		if (ft_isdigit(line[i]))
// 		{
// 			if (parse_digit(line, &i) == false)
// 				return (0);
// 			len++;
// 		}
// 		else if (line[i] == '-' && line[i + 1] && ft_isdigit(line[i + 1]))
// 			i++;
// 		else if (line[i] == ' ')
// 			i++;
// 		else
// 			return (0);
// 	}
// 	return (len);
// }

// bool	parse_digit(char *s, unsigned int *i)
// {
// 	if (!*i || ((s[*i - 1]) == ' ') || (s[*i - 1] == '-'))
// 		++*i;
// 	else
// 		return (false);
// 	while (s[*i] && ft_isdigit(s[*i]))
// 		++*i;
// 	if (s[*i] == ',')
// 	{
// 		if (s[*i + 1] && s[*i + 2] && s[*i + 1] == '0' && s[*i + 2] == 'x')
// 		{
// 			*i += 3;
// 			if (parse_color(s, i) == false)
// 				return (false);
// 		}
// 		else
// 			return (false);
// 	}
// 	return (true);
// }

// bool	parse_color(char *s, unsigned int *i)
// {
// 	size_t		n;

// 	n = 0;
// 	while (s[*i + n] && (ft_isdigit(s[*i + n]) || (s[*i + n] >= 'A'
// 				&& s[*i + n] <= 'F') || (s[*i + n] >= 'a' && s[*i + n] <= 'f')))
// 		++n;
// 	if (n > 8)
// 		return (false);
// 	*i += n;
// 	return (true);
// }
