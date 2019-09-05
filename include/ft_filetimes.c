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
	//char **stra;
	//char *s;
	//long	filetime;
	struct timespec fileStat;

	if (timespec(str, &fileStat) < 0)
		return (0);
	//filetime = fileStat.tv_nsec;
	
	//stra = ft_strsplit(filetime, ' ');
	//s = ft_strsub(stra[3], 5, ft_strlen(stra[3]));
	//s = stra[3];
	return (fileStat.tv_nsec);
}

char		*ft_filetimes(char *str)
{
	char	**strarray;
	char	*strtime;

	strarray = ft_strsplit(ftime(str), ' ');
	strtime = ft_strcat(strarray[1], " ");
	strtime = ft_strjoin(strtime, strarray[2]);
	strtime = ft_strcat(strtime, " ");
	strtime = ft_strjoin(strtime, ft_strsub(strarray[3], 0, 5));
	return (strtime);
}
