#include "include.h"

t_images_vertical		*add_images_vertical(t_images_vertical *list, t_image *one, t_image *two)
{
	t_images_vertical *new;
	t_images_vertical *begin;

	if (!list)
	{
		list = (t_images_vertical *)malloc(sizeof(t_images_vertical));
		list->index1 = one->index;
		list->index2 = two->index;
		list->tags = unique_tags(one, two);
		list->number_of_tags = size_array(list->tags);
		list->next = NULL;
		return (list);
	}
	begin = list;
	new = (t_images_vertical *)malloc(sizeof(t_images_vertical));
	new->index1 = one->index;
	new->index2 = two->index;
	list->tags = unique_tags(one, two);
	list->number_of_tags = size_array(new->tags);
	while (list->next)
		list = list->next;
	list->next = new;
	return (begin);
}