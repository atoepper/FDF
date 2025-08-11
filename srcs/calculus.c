/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoepper <atoepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:32:18 by atoepper          #+#    #+#             */
/*   Updated: 2024/04/17 15:03:41 by atoepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

double	hypotenuse(double a, double b)
{
	return (sqrt(a * a + b * b));
}

double	rot_rect_h(double alpha, double length, double width)
{
	return (2 * fabs((sin(alpha)
				* length + cos(alpha) * width)) - length);
}

int	difx(t_vec a, t_vec b)
{
	return (b.x - a.x);
}

int	dify(t_vec a, t_vec b)
{
	return (b.y - a.y);
}

int	ft_round(double x)
{
	return ((int)(x + 0.5));
}
