#include "ft_ls.h"

t_list      *ft_newlstelem(char *str)
{
    t_list	*elem;
    
	if (!(elem = ft_lstnew((const char *)str, ft_strlen(str))))
    {
        printf("Error");
		return (0);
    }
    return (elem);
}