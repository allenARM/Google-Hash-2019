#include "include.h"

int			size_array(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
		++i;
	return (i);
}