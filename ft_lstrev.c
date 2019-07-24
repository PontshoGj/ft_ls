#include "ft_ls.h"

 void       ft_lstrev(t_list *lst)
 {
     t_list *p;
     t_list *q;

     p = lst;
     if (p->next== 0)
     {
         lst = p;
         return;
     }
    ft_lstrev(p);
    q = p->next;
    q->next = p;
    p->next = 0;
 }