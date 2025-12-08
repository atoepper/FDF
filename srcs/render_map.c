#include "../incl/fdf.h"

void	draw_map(t_img img, t_map *map)
{
	t_index	i;

	i.y = -1;
	while (++i.y < map->max.y)
	{
		i.x = -1;
		while (++i.x < map->max.x)
		{
			if (i.y < map->max.y - 1)
				draw_line(img, map->proj[i.y][i.x], map->proj[i.y + 1][i.x]);
			if (i.x < map->max.x - 1)
				draw_line(img, map->proj[i.y][i.x], map->proj[i.y][i.x + 1]);
		}
	}
}
