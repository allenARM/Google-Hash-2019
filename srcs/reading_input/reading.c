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
	if (info->input[i]->number_of_tags < 1\
		&& info->input[i]->number_of_tags > 100)
		error("Invalid number of tags");
	if (!line[1] || !line[2])
		error("No number of tags");
}

void	check_for_letters_and_digits(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z'))
			i++;
		else
			error("wrong tag name");
	}
	if (i > 10)
		error("leghth of tag too long");
}

void	check_for_tags(t_info *info, int i)
{
	int	j;

	j = 0;
	while (info->input[i]->tags[j])
		check_for_letters_and_digits(info->input[i]->tags[j++]);
	if (j != info->input[i]->number_of_tags)
		error("Number of tags does not match your input");
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
		if (!ft_strcmp(line, ""))
			break ;
		if (info->number_of_photos == i)
			error("The number of photos doesn't match the quantity of those");
		check_for_h_and_v(info, i, line);
		check_for_num_of_tags(info, i, line);
		if (!(info->input[i]->tags = ft_strsplit(&line[3], ' ')))
			error("No tags avalible");
		check_for_tags(info, i);
		info->input[i]->index = i;
		i++;
		ft_strdel(&line);
	}
	if (info->number_of_photos != i)
		error("The number of photos doesn't match the quantity of those");
}
