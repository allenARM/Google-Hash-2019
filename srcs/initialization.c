#include "include.h"

void			initialize_images(t_info *info)
{
	int			i;

	i = 0;
	while (i < info->number_of_photos)
	{
		ft_bzero(&info->input[i], sizeof(t_image));
		++i;
	}
}
