#ifndef FT_LS_H
#define FT_LS_H

# include "libft/libft.h"
# include <dirent.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>

struct stat fileStat;

char    *ft_permission(char *filename);
int     ft_filelink(char *str);
int     ft_filesize(char *str);
char    *ft_filetimes(char *str);
char    *ft_filename(char *str);
void    ft_display_all(char *str);
void	ft_dellst(void *elem, size_t size);
void    ft_display_recursive(const char *str);
void    ft_joinfiled(char *str, char *flag);
void    ft_display_dir(char *str);
void    ft_lstsort(t_list **lst);
void    ft_swaplst(t_list **lst, int first, int second);
t_list  *ft_lstrev(t_list *lst);
#endif
