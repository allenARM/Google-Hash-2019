#ifndef INCLUDE_H
#define INCLUDE_H

#include "../libft/libft.h"


typedef struct		s_image
{
	int				index;
	int				position;	// 1 - horizontal, 0 - vertical
	int				number_of_tags;
	char			**tags;
}					t_image;

typedef struct		s_slide
{
	int				image1;
	int				image2;
	char			**final_tags;
	struct s_slide	*next;
}					t_slide;

typedef	struct		s_info
{
	int				number_of_photos;
	t_image			**input;
	t_slide			*output;
}					t_info;

void				initialize_images(t_info *info);
void				check_for_number_of_images(char *line, t_info *info);
void				reading(t_info *info);
void				error(char *reason);
int					size_slide(t_slide *list);
t_slide				*add_slide(t_slide *list, t_image *one, t_image *two);
void				algorithm(t_info *info);
int					simple_slow_check(char **one, char **two);


#endif
