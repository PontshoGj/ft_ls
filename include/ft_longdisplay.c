/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longdisplay.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 10:56:29 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/14 11:01:03 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			block(char *str, char *flag)
{
	char		**arrlist;
	int			i;
	long long	filetime;
	struct stat	filestat;
	char		*temp;

	i = 0;
	filetime = 0;
	arrlist = ft_arrydirlist(str, ft_chksort(flag));
	while (arrlist[i] != 0)
	{
		temp = ft_pathname(str, arrlist[i]);
		if (lstat(temp, &filestat) < 0)
			return ;
		if (ft_strspn("a", flag) == 1)
			filetime += filestat.st_blocks;
		else if (arrlist[i][0] != '.')
			filetime += filestat.st_blocks;
		i++;
		free((char *)temp);
	}
	ft_freearry(arrlist);
	ft_printf("total %d\n", filetime);
}

void			ft_longdisplay(char *path, char *flag)
{
	char		**arrlist;
	int			i;

	i = 0;
	block(path, flag);
	arrlist = ft_arrydirlist(path, ft_chksort(flag));
	while (arrlist[i] != 0)
	{
		if (ft_strspn("a", flag) == 1)
			ft_display_long(arrlist[i], path);
		else if (arrlist[i][0] != '.')
			ft_display_long(arrlist[i], path);
		i++;
	}
	ft_freearry(arrlist);
}
