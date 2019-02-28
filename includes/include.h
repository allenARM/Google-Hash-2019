
#ifndef INCLUDE_H
#define INCLUDE_H

#include "libft/libft.h"


typedef struct	s_image
{
	int			index;
	int			position;	// 1 - horizontal, 0 - vertical
	int			number_of_tags;
	char		**tags;
}				t_image;

typedef	struct	s_info
{
	int			number_of_photos;
	t_image		*input;
	//Will be output thing
}

void			initialize_images(t_info *info);

#endif
