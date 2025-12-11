/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoepper <atoepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:46:49 by atoepper          #+#    #+#             */
/*   Updated: 2025/12/11 12:40:49 by atoepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

int	main_loop(t_map *map)
{
	static double	timestamp = 0;

	if (get_timestamp() - timestamp > 1.0 / 20)
	{
		move_map(map);
		project_map(map);
		clear_window(map);
		update_window(map);
		timestamp = get_timestamp();
	}
	return (SUCCESS);
}
