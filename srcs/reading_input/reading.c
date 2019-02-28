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

void	check_for_correct_photo_pos(t_info *info, int i, char *line)
{
	info->input[i]->position = ft_atoi(&line[2]);
	if (info->input[i]->position < 0 && info->input[i]->position > 100000)
		error("too many or too few photos");
}

void	reading(t_info *info)
{
	char	*line;
	int		i;

	get_next_line(1, &line);
	check_for_number_of_images(line, info);
	ft_strdel(&line);

	i = 0;
	while (get_next_line(1, &line) > 0)
	{
		check_for_h_and_v(info, i, line);
		check_for_correct_photo_pos(info, i, line);
		check_tags(info, i, line);
		i++;
		ft_strdel(&line);
	}
}