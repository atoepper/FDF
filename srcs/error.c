#include "../incl/fdf.h"

void	exit_on_error(t_map *map, char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	cleanup(map);
	exit(EXIT_FAILURE);
}