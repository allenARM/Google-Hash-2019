#include "include.h"

void			initialize_images(t_info *info)
{
	int			i;

	i = 0;
	info->input = (t_image **)malloc(sizeof(t_image *) * info->number_of_photos + 1);
	while (i < info->number_of_photos)
	{
		// ft_bzero(&info->input[i], sizeof(t_image));
		info->input[i] = (t_image *)malloc(sizeof(t_image ));
		info->input[i]->index = 0;
		info->input[i]->position = 0;	// 1 - horizontal, 0 - vertical
		info->input[i]->number_of_tags = 0;
		info->input[i]->tags = NULL;
		++i;
	}
	info->input[i] = NULL;
}

t_image		**sort_images(t_image **list)
{
	int		i;
	int		tmp;
	char	**tmp1;

	i = 0;
	while (list[i] && list[i + 1])
	{
		if (list[i]->number_of_tags > list[i + 1]->number_of_tags)
		{
			tmp = list[i]->number_of_tags;
			list[i]->number_of_tags = list[i + 1]->number_of_tags;
			list[i + 1]->number_of_tags = tmp;

			tmp = list[i]->position;
			list[i]->position = list[i + 1]->position;
			list[i + 1]->position = tmp;

			tmp = list[i]->number_of_tags;
			list[i]->number_of_tags = list[i + 1]->number_of_tags;
			list[i + 1]->number_of_tags = tmp;

			tmp1 = list[i]->tags;
			list[i]->tags = list[i + 1]->tags;
			list[i + 1]->tags = tmp1;			
		}
		else
			++i;
	}
	return (list);
}