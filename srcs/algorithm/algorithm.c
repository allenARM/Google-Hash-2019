#include "include.h"

void		algorithm(t_info *info)
{
	t_images_vertical		*vertical_to_horizontal;

	vertical_to_horizontal = create_list_of_verticals(info);

	int		i;
	while (vertical_to_horizontal)
	{
		i = 0;
		ft_printf("Index %d & Index %d\n", vertical_to_horizontal->index1, vertical_to_horizontal->index2);
		while (vertical_to_horizontal->tags[i])
			ft_printf("	-%s\n", vertical_to_horizontal->tags[i]);
		vertical_to_horizontal = vertical_to_horizontal->next;
	}

	info->output = NULL;
	
}