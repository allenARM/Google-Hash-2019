#include "include.h"

void		algorithm(t_info *info)
{
	info->output = NULL;
	info->output = add_slide(info->output, info->input[1], info->input[2]);

	int		i;
	while (info->output)
	{
		i = 0;
		while (info->output->final_tags[i])
			ft_printf("%s->", info->output->final_tags[i++]);
		ft_printf("NULL\n");
		info->output = info->output->next;
	}

	ft_printf("least thing = %d\n", simple_slow_check(info->input[2]->tags, info->input[3]->tags));
}