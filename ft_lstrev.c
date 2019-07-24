#include "ft_ls.h"

 t_list       *ft_lstrev(t_list *lst)
 {
    t_list *p;
    t_list *q;

    p = 0;
    q = 0;
    if (lst->next == 0)
        return (p = lst);
    p = ft_lstrev(lst->next);
    ft_lstadd(&q, p);
    return (q);
    //(*lst) = (*lst)->next;
 }