#include "ft_ls.h"

void        ft_swaplst(t_list *lst, int first, int second)
{
    t_list *lfirst;
    t_list *lsecond;
    char *temp;
    int i;

    lfirst = lst;
    lsecond = lst;
    temp = 0;
    i = 1;
    while (lfirst->next != 0 && i++ < first)
        lfirst = lfirst->next;
    i = 1;
    while (lsecond->next != 0 && i++ < second)
        lsecond = lsecond->next;
    temp = (char *)lfirst->content;
    lfirst = lsecond->content;
    lfirst->content_size = ft_strlen((char *)lfirst->content);
    ft_strdel((char **)(&lsecond->content));
    lsecond->content = &temp;
    lsecond->content_size = ft_strlen((char *)lsecond->content);
    ft_strdel(&temp);
}