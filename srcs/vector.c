/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoepper <atoepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:44:11 by atoepper          #+#    #+#             */
/*   Updated: 2025/12/11 12:44:12 by atoepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

void	set_vector(t_vec *v, double x, double y, double z)
{
	v->x = x;
	v->y = y;
	v->z = z;
}

void	print_vector(t_vec v)
{
	printf("x: %fy: %fz: %f, color: %ld ", v.x, v.y, v.z, v.color);
}
