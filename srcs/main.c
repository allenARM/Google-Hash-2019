#include "include.h"

void			error(char *reason)
{
	ft_printf("Error: %s\n", reason);
	exit(0);
}

int				main()
{
	t_info		info;

	ft_bzero(&info, sizeof(t_info));
	reading(&info);
}