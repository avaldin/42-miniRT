
#include "libft.h"
#include "structure.h"

void	_free_axis(t_coord ***axis, int i, int j)
{
	while (i > -1)
	{
		while (j > 0)
			free(axis[i][j--]);
		free(axis[i]);
		i--;
	}
	free(axis);
}