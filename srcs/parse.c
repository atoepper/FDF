/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoepper <atoepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:49:14 by atoepper          #+#    #+#             */
/*   Updated: 2025/12/06 13:59:30 by atoepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

bool	is_numeric(char *s)
{
	if (!s || *s == '\0')
		return false;
	if (*s == '+' || *s == '-')
		s++;
	if (*s == '\0')
		return false;
	while (*s)
	{
		if (*s < '0' || *s > '9')
		return false;
		s++;
	}		
	return true;
}

bool	is_color(char *s)
{
	int	numlen;

	numlen = ft_strlen(s);
	if (numlen < 4 || numlen > 8)
		return false;
	if (ft_strncmp(s, "0x", 2) != 0)
		return false;
	s += 2;
	while (*s)
	{
		if (!ft_ishex(*s))
			return (false);
		s++;
	}
	return (true);
}

int		get_color(char *s)
{
	s += 2;
	return (ft_hextoi(s, 6));
}
