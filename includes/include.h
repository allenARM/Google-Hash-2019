#ifndef INCLUDE_H
#define INCLUDE_H

#include "../libft/libft.h"


typedef struct		s_image
{
	int				index;
	int				index_extra;
	int				position;	// 1 - horizontal, 0 - vertical
	int				number_of_tags;
	char			**tags;
}					t_image;

typedef	struct		s_images_vertical
{
	int				index1;
	int				index2;
	int				number_of_tags;
	char			**tags;
	struct s_images_vertical *next;
}					t_images_vertical;

typedef struct		s_list
{
	char			*tag;
	struct s_list 	*next;
}					t_list;

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
char				**unique_tags(t_image *one, t_image *two);
t_image				**sort_images(t_image **list);
t_images_vertical	*create_list_of_verticals(t_info *info);
int					size_array(char **arr);
t_images_vertical		*add_images_vertical(t_images_vertical *list, t_image *one, t_image *two);

#endif
