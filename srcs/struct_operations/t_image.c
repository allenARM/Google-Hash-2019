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
