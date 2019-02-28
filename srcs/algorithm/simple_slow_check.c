#include "include.h"

int			simple_slow_check(char **one, char **two)
{
	int		i;
	int		j;
	int		one_left_sum;
	int		two_left_sum;
	int		common_sum;

	one_left_sum = 0;
	two_left_sum = 0;
	common_sum = 0;
	i = 0;
	j = 0;

	while (one[i])
	{
		j = 0;
		while (two[j])
		{
			if (!ft_strcmp(one[i], two[j]))
				++common_sum;
			++j;
		}
		++i;
	}
	one_left_sum = i - common_sum;
	two_left_sum = j - common_sum;
	if (one_left_sum > common_sum && two_left_sum > common_sum)
		return (common_sum);
	if (common_sum > one_left_sum && two_left_sum > one_left_sum)
		return (one_left_sum);
	return (two_left_sum);
}