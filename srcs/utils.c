#include "../incl/fdf.h"

void	print_2d_arr(long **arr, size_t x, size_t y)
{
	size_t	i;
	size_t	j;

	if (!arr)
	{
		ft_printf("Empty Array\n");
		return;
	}
	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			ft_printf("%d\t", arr[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

int	arr_size(char **arr)
{
	int i = 0;

	if (!arr)
		return (0);
	while (arr[i])
		i++;
	return (i);
}