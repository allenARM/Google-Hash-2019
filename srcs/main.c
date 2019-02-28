#include "include.h"

void			error(char *reason)
{
	ft_printf("Error: %s\n", reason);
	exit(0);
}

void			print_info(t_info *info)
{
	int			i;
	int			j;

	i = 0;
	ft_printf("number of photos = %d\n\n", info->number_of_photos);
	while (info->input[i])
	{
		ft_printf("Photo %d:\n", i);
		ft_printf("index = %d\n", info->input[i]->index);
		ft_printf("position = %d --- ", info->input[i]->position);
		if (info->input[i]->position == 1)
			ft_printf("Horizontal\n");
		else
			ft_printf("Vertical\n");
		ft_printf("number_of_tags = %d\n\n", info->input[i]->number_of_tags);
		j = 0;
		ft_printf("Tags:\n");
		while (info->input[i]->tags[j])
		{
			ft_printf(" - %s\n", info->input[i]->tags[j]);
			++j;
		}
		ft_printf("\n");
		++i;
	}
}

int				main()
{
	t_info		info;

	ft_bzero(&info, sizeof(t_info));
	reading(&info);
	print_info(&info);
}