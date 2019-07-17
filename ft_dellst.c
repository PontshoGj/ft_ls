#include "ft_ls.h"

void	ft_dellst(void *elem, size_t size)
{
	if (!elem)
		return ;
	free(elem);
	(void)size;
}