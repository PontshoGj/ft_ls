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

void			setugid(char *path, char *dirname)
{
	struct stat	filestat;
	char *s;

	s = ft_pathname(path, dirname);
	if (lstat(s, &filestat) < 0)
		return ;
	printf("%ld", (long)filestat.st_ino);
	printf("%4lld%2s", filestat.st_blocks / 2, " "); //nedd to fix
	printf("%s\n", dirname);
}

void		setgids(char *path, char *dirname)
{
	struct stat	filestat;
	char *s;

	s = ft_pathname(path, dirname);
	if (lstat(s, &filestat) < 0)
		return ;
	ft_printf("%ld  ", (long)filestat.st_ino);
	ft_printf("%lld ", filestat.st_blocks / 2);
	ft_printf("%s ", ft_permission(s));
	ft_printf("%d ", ft_filelink(s));
	ft_printf("%s ", ft_filetimes(s));
	ft_printf("%s\n", path);
}

void	stickybit(char *path, char *dirname)
{
	char 	**arr;
	int i;

	i = 0;
	arr = ft_arrydirlist(path, ' ');
	while (arr[i])
		setugid(path, arr[i++]);	
}
int				main(int ac, char **av)
{
	char *s;

	s = av[1];
	if (!s)
		s = ".";
	//setugid(s);
	//setgids(s);
	stickybit(s, s);
	return (0);
}
