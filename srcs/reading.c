#include "include.h"

void	reading(t_info *info)
{
	char	*line;
	int		i;

	get_next_line(1, &line);
	info->num_of_images = ft_atoi(line);
	ft_strdel(line);
	if (info->num_of_images <= 100000)
		info->input = (malloc(sizeof(t_image) * info->num_of_images + 1);
	else
		make_exit() // write exit function;

	i = 0;

	while (get_next_line(1, &line) > 0)
	{
		if (!)
	}
}
