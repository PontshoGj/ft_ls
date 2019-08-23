#ifndef FT_LS_H
#define FT_LS_H

# include "../libft/libft.h"
# include <dirent.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>

struct stat fileStat;

typedef	struct	tt_list
{
	void			*content;
    char            *time;
	size_t			content_size;
	struct tt_list	*next;
}       ls_list;

char    *ft_permission(char *filename);
int     ft_filelink(char *str);
int     ft_filesize(char *str);
char    *ft_filetimes(char *str);
char    *ft_filename(char *str);
void    ft_display_all(char *str, char * flag);
void	ft_dellst(void *elem, size_t size);
void    ft_display_long(char *str);
void    ft_display_dir(char *str, char *flag);
void    ft_display_long_all(char *str);
void    ft_lstsort(t_list **lst);
void    ft_swaplst(t_list **lst, int first, int second);
t_list  *ft_lstrev(t_list *lst);
char     ft_isflag(char *s);
void    ft_lstrevsort(t_list **lst);
t_list  *ft_dirlst(char *path);
t_list  *ft_newlstelem(char *str);
char    *ft_pathname(char *str,char *dirname);
int     isdir(char *s);
void    disp(char *s);
int     isfile(char *s);
t_list  *ft_dirlstname(char *path);
#endif
