/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoepper <atoepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:46:49 by atoepper          #+#    #+#             */
/*   Updated: 2024/04/29 17:09:40 by atoepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

int	handle_no_event(void *map)
{
	(void) map;
	return (0);
}

void	ch_scale_xy(int k, t_map *map)
{
	if (k == XK_x)
		map->zoom.x += 1;
	else if (k == XK_z)
		map->zoom.x -= 1;
}
