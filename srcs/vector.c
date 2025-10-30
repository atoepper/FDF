#include "../incl/fdf.h"

void	set_vector(t_vec *v, double x, double y, double z)
{
	v->x = x;
	v->y = y;
	v->z = z;
}

void	print_vector(t_vec v)
{
	printf("x: %fy: %fz: %f", v.x, v.y, v.z);
}