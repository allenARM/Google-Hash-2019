#include "include.h"

void	reading(t_info *info)
{
	char	*line;
	int		i;

	get_next_line(1, &line);
	check_for_number_of_images();
	i = 0;

	while (get_next_line(1, &line) > 0)
	{
		if (line[0] == 'H' || line[0] == 'V')
		{
			if (line == 0)
		}
		ft_strdel(line);
	}
}
