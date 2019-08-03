#include "ft_ls.h"

void    ft_lstsort(t_list **lst)
{
    t_list *lfirst;
    t_list *lsecond;
    int i;
    int j;

    lfirst = *lst;
    lsecond = 0;
    i = 1;
    j = 1;
    while (lfirst->next != 0)
    {
        lsecond = lfirst->next;
        while (lsecond != 0)
        {
			j++;
            if (ft_strcmp((char *)lfirst->content, (char *)lsecond->content) > 0)
                ft_swaplst(lst, i, j);
            lsecond = lsecond->next;
        }
        j = 1;
        i++;
        lfirst = lfirst->next;
    }
}