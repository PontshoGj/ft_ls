#include "ft_ls.h"

int	checkfl(char *str)
{
	char	s;

	if (!(s = ft_isflag(str)))
		return (1);
	ft_printf("ft_ls: illegal option -- %c\nusage: ft_ls [-Ralrt] \
			[file ...]\n", s);
	exit(1);
}