/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filetimes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 12:26:46 by pmogwere          #+#    #+#             */
/*   Updated: 2019/08/26 12:28:31 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ftime(char *str)
{
	char	*filetime;
	struct stat fileStat;

	if (lstat(str, &fileStat) < 0)
		return (0);
	filetime = ctime(&fileStat.st_mtime);
	return (filetime);
}
long	fnanotime(char *str)
{
	struct stat fileStat;
	struct timespec filetime;

	if (lstat(str, &fileStat) < 0)
		return (0);
	filetime = fileStat.st_mtimespec;
	
	return (filetime.tv_nsec);
}

char		*ft_filetimes(char *str)
{
	char	**strarray;
	char	*strtime;
	char 	*temp;

	strarray = ft_strsplit(ftime(str), ' ');
	strtime = ft_strcat(strarray[1], " ");
	temp = strtime;
	strtime = ft_strjoin(strtime, strarray[2]);
	free(temp);
	temp = strtime;
	strtime = ft_strcat(strtime, " ");
	strtime = ft_strjoin(strtime, ft_strsub(strarray[3], 0, 5));
	free(temp);
	ft_free2d(strarray);
	return (strtime);
}
