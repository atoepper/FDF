/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoepper <atoepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:04:32 by atoepper          #+#    #+#             */
/*   Updated: 2024/04/17 15:05:47 by atoepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

int	add_shade(double shade, int color)
{
	double	shadei;

	if (shade >= 1 || shade <= 0)
		return (color);
	shadei = 1 - shade;
	return (get_t(color) << 24
		| (int)(shadei * get_r(color)) << 16
		| (int)(shadei * get_g(color)) << 8
		| (int)(shadei * get_b(color)));
}

int	gradient(float x, float y, t_vec a, t_vec b)
{
	float	fraction;

	if (abs(difx(a, b)) > abs(dify(a, b)))
	{
		fraction = (a.x != b.x) * ((x - (float)a.x)
				/ ((float)b.x - (float)a.x));
	}
	else
	{
		fraction = (a.y != b.y) * ((y - (float)a.y)
				/ ((float)b.y - (float)a.y));
	}
	return (create_trgb(get_t(a.color),
			get_r(a.color) + (get_r(b.color) - get_r(a.color)) * fraction,
			get_g(a.color) + (get_g(b.color) - get_g(a.color)) * fraction,
			get_b(a.color) + (get_b(b.color) - get_b(a.color)) * fraction)
	);
}
