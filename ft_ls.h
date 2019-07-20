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
char    *ft_joinfiled(char *str);
void	ft_dellst(void *elem, size_t size);
void    ft_display_recursive(const char *str);
void    ft_display_all(char *str);
void    ft_display_long(char *str);
void    ft_display_long_all(char *str);
void    ft_display_dir(char *str);
#endif