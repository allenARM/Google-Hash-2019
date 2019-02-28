#include "include.h"

void	check_for_h_and_v(t_info *info, int i, char *line)
{
	if (line[0] == 'H' || line[0] == 'V')
	{
		if (line[0] == 'H')
			info->input[i]->position = 1;
		else
			info->input[i]->position = 0;
	}
	else
		error("Wrong input of horizontal or vertial photo");
}

void	check_for_num_of_tags(t_info *info, int i, char *line)
{
	info->input[i]->number_of_tags = ft_atoi(&line[1]);
	if (info->input[i]->number_of_tags < 0\
		&& info->input[i]->number_of_tags > 100000)
		error("too many or too few tags");
}

void	reading(t_info *info)
{
	char	*line;
	int		i;

	get_next_line(0, &line);
	check_for_number_of_images(line, info);
	ft_strdel(&line);

	i = 0;
	while (get_next_line(0, &line) > 0)
	{
		check_for_h_and_v(info, i, line);
		check_for_num_of_tags(info, i, line);
		info->input[i]->tags = ft_strsplit(&line[3], ' ');
		i++;
		ft_strdel(&line);
	}
}
