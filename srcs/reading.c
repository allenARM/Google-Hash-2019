#include "include.h"

void	check_for_h_and_v(t_info *info, char *line)
{
	if (line[0] == 'H' || line[0] == 'V')
	{
		if (line[0] == 'H')
			info->input.position = 1;
		else
			info->input.position = 0;
	}
	else
		error("Wrong input of horizontal or vertial photo");
}

void	reading(t_info *info)
{
	char	*line;
	int		i;

	get_next_line(1, &line);
	check_for_number_of_images(line, info);
	ft_strdel(line);

	i = 0;
	while (get_next_line(1, &line) > 0)
	{
		check_for_h_and_v(info, line);
		
		ft_strdel(line);
	}
}
