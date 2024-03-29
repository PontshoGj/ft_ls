/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 10:54:42 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/18 17:32:12 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"
# include "../ft_printf/src/ft_printf.h"
# include <dirent.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <sys/xattr.h>
# include <unistd.h>

char	*ft_permission(char *filename);
int		ft_filelink(char *str);
int		ft_filesize(char *str);
char	*ft_filetimes(char *str);
char	*ft_filename(char *str);
void	ft_display_all(char *str, char *flag, char *path);
void	ft_dellst(void *elem, size_t size);
void	ft_display_long(char *str, char *pth);
void	ft_display_dir(char *str, char *flag);
void	ft_display_long_all(char *str);
char	ft_isflag(char *s);
char	*ft_pathname(char *str, char *dirname);
int		isdir(char *s);
void	ft_displayrec(char *s, char *flag);
int		isfile(char *s);
int		ft_islink(char *s);
char	**ft_sortarry(char **s);
char	**ft_sortarryr(char **s);
char	**ft_sortarryr2(char **s);
char	**ft_sortarryt(char **s, char *path);
char	**dirlist(char *p);
size_t	ft_dirnum(char *path);
char	**ft_arrydirlist(char *p, char c);
char	ft_chksort(char *flag);
char	ft_filetype(char *path);
char	chkxattr(char *path);
char	*ftime(char *str);
long	fnanotime(char *str);
long	fsectime(char *str);
void	ft_longdisplay(char *path, char *flag);
char	*ft_getlink(char *path);
void	ft_freearry(char **s);
char	ft_stb(struct stat filestat);
int		checkfiledir(char *s);
int		checkfl(char *str);
void	setugid(char *path, char *dirname);
void	setgids(char *path, char *dirname);
void	stickybit(char *path);
char	*ft_filetimes2(char *str);
int		chkvali(char *flag);
void	swap(char **s, char **s2);
int		freepath(char *s);
#endif
