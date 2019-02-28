#include "include.h"

t_slide		*add_slide(t_slide *list, t_image *one, t_image *two)
{
	t_slide *new;
	t_slide *begin;

	if (!list)
	{
		list = (t_slide *)malloc(sizeof(t_slide));
		list->image1 = one->index;
		list->image2 = two->index;
		// list->final_tags = 
		return (list);
	}
	begin = list;
	new = (t_slide *)malloc(sizeof(t_slide));
	new->image1 = one->index;
	new->image2 = two->index;
	// list->final_tags = 
	while (list->next)
		list = list->next;
	list->next = new;
	return (begin);
}

int			size_slide(t_slide *list)
{
	int		i;

	i = 0;
	while (list)
	{
		++i;
		list = list->next;
	}
	return (i);
}