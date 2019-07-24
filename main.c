#include "ft_ls.h"

int main(void)
{
    int i = 1;
	char 	*str[] = {"lorem", "ispum", "dolo", "sit"};
	t_list	*elem;
	t_list	*adds;

	if (!(elem = ft_lstnew(str[0], sizeof(str[0]))))
		return (0);
	while (i < 4)
	{
		if (!(adds = ft_lstnew(str[i], sizeof(str[i]))))
			return (0);
		ft_lstadd(&elem, adds);
		i++;
	}
	//ft_lstsort(&elem);
	ft_lstrev(elem);
	while (elem)
	{
		ft_putendl(elem->content);
		elem = elem->next;
	}
	return 0;
}
