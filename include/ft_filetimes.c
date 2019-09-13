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
char	*fnanotime(char *str)
{
	struct stat fileStat;
	struct timespec filetime;
	char	*s;

	if (lstat(str, &fileStat) < 0)
		return (0);
	filetime = fileStat.st_mtimespec;
	s = ft_strjoin(ftime(str), " ");
	//s = ft_strjoin(s, ft_longtoa_base(filetime.tv_nsec, 10, 'c'));
	return (s);
}

char		*ft_filetimes(char *str)
{
	char	**strarray;
	char	*strtime;
	char	*temp;
	char	*sub;

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

/*int main(void)
{
	printf("%d", ft_strcmp(fnanotime("a.out"), fnanotime("ft_ls")));
	return 0;
}*/