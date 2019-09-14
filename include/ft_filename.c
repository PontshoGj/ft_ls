/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filename.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 12:30:41 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/14 10:35:54 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			*ft_filename(char *str)
{
	char			*s;
	char			*temp;
	struct stat		filestat;
	struct group	*grp;
	struct passwd	*name;

	if (lstat(str, &filestat) < 0)
		return (0);
	if ((name = getpwuid(filestat.st_uid)) == 0)
		return (0);
	if ((grp = getgrgid(filestat.st_gid)) == 0)
		return (0);
	s = (char *)malloc(sizeof(char) * \
			ft_strlen(name->pw_name) + ft_strlen(grp->gr_name) + 3);
	temp = s;
	s = ft_strjoin(name->pw_name, "  ");
	free((char *)temp);
	temp = s;
	s = ft_strjoin(s, grp->gr_name);
	free((char *)temp);
	return (s);
}
