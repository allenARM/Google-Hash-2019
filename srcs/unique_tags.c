#include "include.h"

t_list	*add_list(t_list *list, char *data)
{
	t_list	*new;
	t_list	*head;

	if (!list)
	{
		list = malloc(sizeof(t_list));
		list->tag = data;
		list->next = NULL;
	}
	head = list;
	while (list->next)
		list = list->next;

	new = malloc(sizeof(t_list));
	new->tag = data;
	new->next = NULL;
	list->next = new;
	return (head);
}

char	**copy_tags(char **str, int num)
{
	int		i;
	char	**tags;

	tags = (char**)malloc(sizeof(char*) * (num + 1));
	i = 0;
	while (str[i])
	{
		tags[i] = ft_strdup(str[i]);
		i++;
	}
	tags[i] = NULL;
	return (tags);
}

int		check_tag(t_list *list, char *str)
{
	while (list)
	{
		if (!ft_strcmp(str, list->tag))
			return (1);
		list = list->next;
	}
	return (0);
}

void	clean_list(t_list *list)
{
	if (list->next)
		clean_list(list->next);
	ft_strdel(list->tag);
	free(list);
}

char	**uniqie_tags(t_image *one, t_image *two)
{
	char	**tags;
	t_list	*list;
	t_list	*head;
	int		i;

	list = NULL;
	if (!one)
		tags = copy_tags(one->tags, one->number_of_tags);
	else if (!two)
		tags = copy_tags(two->tags, two->number_of_tags);
	else if (!one && !two)
		error("Both images cannot be empty");

	tags = (char**)malloc(sizeof(char*)\
		* (two->number_of_tags + one->number_of_tags + 1));

	i = 0;
	while (one->tags[i])
		t_list = add_list(list, one->tags[i++]);

	i = 0;
	while (two->tags[i])
	{
		if (check_tag(list, two->tags[i]) == 0)
			list = add_list(list, two->tags[i]);
		i++;
	}

	i = 0;
	head = list;
	while (list)
	{
		tags[i] = ft_strdup(list->tag);
		list = list->next;
		i++;
	}
	tags[i] = NULL;
	clean_list(head);
}
