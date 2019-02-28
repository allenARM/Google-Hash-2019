#include "include.h"

int		check_for_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (-1);
	}
	return (0);
}

int		check_for_integer(char *str)
{
	if (str[0] == '-')
		if (ft_strlen(str) > 11)
			return (-1);
	if (str[0] != '-')
		if (ft_strlen(str) > 10)
			return (-1);
	if (str[0] == '-' && ft_strlen(str) == 11)
		if (ft_strcmp(str, "-2147483648") > 0)
			return (-1);
	if (str[0] != '-' && ft_strlen(str) == 10)
		if (ft_strcmp(str, "2147483647") > 0)
			return (-1);
	return (0);
}

void			check_for_number_of_images(char *line, t_info *info)
{
	if (check_for_number(line) == -1 || check_for_integer(line) == -1)
		error("Number of images is not a number");
	info->num_of_images = ft_atoi(line);
	if (info->num_of_images <= 100000 && 0 < info->num_of_images)
		initialize_images(info);
	else
		error() // write exit function;
}