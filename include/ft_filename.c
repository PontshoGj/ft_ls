/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filename.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 12:30:41 by pmogwere          #+#    #+#             */
/*   Updated: 2019/08/26 12:43:22 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			*ft_filename(char *str)
{
	char			*s;
	char			*temp;
	struct stat		fileStat;
	struct group	*grp;
	struct passwd	*name;

	if (lstat(str, &fileStat) < 0)
		return (0);
	if ((name = getpwuid(fileStat.st_uid)) == 0)
		return (0);
	if ((grp = getgrgid(fileStat.st_gid)) == 0)
		return (0);
	s = (char *)malloc(sizeof(char) * ft_strlen(name->pw_name) + ft_strlen(grp->gr_name) + 3);
	temp = s;
	s = ft_strjoin(name->pw_name, "  ");
	free((char *)temp);
	temp = s;
	s = ft_strjoin(s, grp->gr_name);
	free((char *)temp);
	return (s);
}
