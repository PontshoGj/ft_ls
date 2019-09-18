/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filetimes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 12:26:46 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/14 11:11:59 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			*ftime(char *str)
{
	struct stat	filestat;

	if (lstat(str, &filestat) < 0)
		return (0);
	return (ctime(&filestat.st_mtime));
}

long			fsectime(char *str)
{
	struct stat	filestat;

	if (lstat(str, &filestat) < 0)
		return (0);
	return (filestat.st_mtimespec.tv_sec);
}

long			fnanotime(char *str)
{
	struct stat	filestat;

	if (lstat(str, &filestat) < 0)
		return (0);
	return (filestat.st_mtimespec.tv_nsec);
}

char			*ft_filetimes2(char *str)
{
	char		**strarray;
	char		*strtime;
	char		*temp;
	char		*sub;

	strarray = ft_strsplit(ftime(str), ' ');
	temp = ft_strcat(strarray[2], " ");
	strtime = ft_strjoin(temp, strarray[1]);
	strtime = ft_strcat(strtime, " ");
	temp = strtime;
	sub = ft_strsub(strarray[3], 0, 5);
	strtime = ft_strjoin(temp, sub);
	free((char *)temp);
	free((char *)sub);
	ft_freearry(strarray);
	return (strtime);
}

char			*ft_filetimes(char *str)
{
	char		**strarray;
	char		*strtime;
	char		*temp;
	char		*sub;

	strarray = ft_strsplit(ftime(str), ' ');
	temp = ft_strcat(strarray[1], " ");
	strtime = ft_strjoin(temp, strarray[2]);
	strtime = ft_strcat(strtime, " ");
	temp = strtime;
	sub = ft_strsub(strarray[3], 0, 5);
	strtime = ft_strjoin(temp, sub);
	free((char *)temp);
	free((char *)sub);
	ft_freearry(strarray);
	return (strtime);
}
