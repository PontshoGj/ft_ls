#include "ft_ls.h"

int	checkfiledir(char *s)
{
	if (isdir(s) || isfile(s))
		return (1);
	ft_printf("ls: %s: No such file or directory\n", s);
	return (0);
}
