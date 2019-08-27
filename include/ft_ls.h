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

char    *ft_permission(char *filename);
int     ft_filelink(char *str);
int     ft_filesize(char *str);
char    *ft_filetimes(char *str);
char    *ft_filename(char *str);
void    ft_display_all(char *str, char * flag, char *path);
void	ft_dellst(void *elem, size_t size);
void    ft_display_long(char *str);
void    ft_display_dir(char *str, char *flag);
void    ft_display_long_all(char *str);
char	ft_isflag(char *s);
char    *ft_pathname(char *str,char *dirname);
int     isdir(char *s);
void    ft_displayrec(char *s, char *flag);
int     isfile(char *s);
int		ft_islink(char *s);
char	**ft_sortarry(char **s);
char	**ft_sortarryr(char **s);
char	**dirlist(char *p);
size_t 	ft_dirnum(char *path);
char	**ft_arrydirlist(char *p);
#endif
