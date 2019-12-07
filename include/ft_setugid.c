/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setugid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 13:49:23 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/17 13:50:36 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				setugid(char *path, char *dirname)
{
	struct stat		filestat;
	char			*s;

	s = ft_pathname(path, dirname);
	if (lstat(s, &filestat) < 0)
		return ;
	ft_printf("%d", (long)filestat.st_ino);
	ft_printf("%4d%2s", filestat.st_blocks / 2, " ");
	ft_printf("%s\t", dirname);
	free(s);
}

void				setgids(char *path, char *dirname)
{
	struct stat		filestat;
	struct group	*grp;
	char			*s;
	char			*temp;

	s = ft_pathname(path, dirname);
	if (lstat(s, &filestat) < 0)
		return ;
	if ((grp = getgrgid(filestat.st_gid)) == 0)
		return ;
	ft_printf("%d  ", (long)filestat.st_ino);
	ft_printf("%d ", filestat.st_blocks / 2);
	temp = ft_permission(s);
	ft_printf("%s ", temp);
	free(temp);
	ft_printf("%d ", ft_filelink(s));
	ft_printf("%s ", grp->gr_name);
	ft_printf("%d ", ft_filesize(s));
	temp = ft_filetimes2(s);
	ft_printf("%s ", temp);
	free(temp);
	ft_printf("%s\n", path);
	free(s);
}

void				stickybit(char *path)
{
	char			**arr;
	int				i;
	struct stat		filestat;
	long			d;
	char			*s;

	i = 0;
	d = 0;
	s = 0;
	arr = ft_arrydirlist(path, 't');
	while (arr[i])
	{
		s = ft_pathname(path, arr[i++]);
		if (lstat(s, &filestat) < 0)
			return ;
		d += filestat.st_blocks / 2;
		free(s);
	}
	i = 0;
	ft_printf("total %d\n", d);
	while (arr[i])
	{
		if (arr[i][0] != '.')
			setugid(path, arr[i]);
		i++;
	}
	ft_freearry(arr);
	ft_printf("\n");
}
