#include "ft_ls.h"

void        ft_swaplst(t_list **lst, int first, int second)
{
    t_list *lfirst;
    t_list *lsecond;
    char *temp;
    int i;

    lfirst = *lst;
    lsecond = *lst;
    temp = 0;
    i = 1;
    while (lfirst != 0 && i++ < first)
        lfirst = lfirst->next;
	i = 1;
    while (lsecond != 0 && i++ < second)
	    lsecond = lsecond->next;
	temp = (char *)lfirst->content;
    lfirst->content = (char *)lsecond->content;
    lfirst->content_size = lsecond->content_size;
    lsecond->content = temp;
    lsecond->content_size = lfirst->content_size;
}