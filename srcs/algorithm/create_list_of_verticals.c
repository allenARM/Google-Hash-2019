#include "include.h"

t_images_vertical		*find_all_verticals(t_info *info, int i, t_images_vertical *list)
{
	int		j;

	j = i;
	while (info->input[j])
	{
		if (info->input[j]->position == 0)
			list = add_images_vertical(list, info->input[i], info->input[j]);
		++j;
	}
	return (list);
}

t_images_vertical		*create_list_of_verticals(t_info *info)
{
	int		i;
	t_images_vertical *list;

	i = 0;
	list = NULL;
	while (info->input[i])
	{
		if (info->input[i]->position == 0)
			list = find_all_verticals(info, i, list);
		++i;
	}	
	return (list);
}