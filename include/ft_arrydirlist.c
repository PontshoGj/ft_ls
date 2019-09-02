/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrydirlist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 12:36:56 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/02 12:42:15 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char				**ft_sorttype(char **s, char type, char *path)
{
	if (type == 'r')
		return (ft_sortarryr(s));
	else if (type == 't')
		return (ft_sortarryt(s, path));
	return (ft_sortarry(s));
}

char				**ft_arrydirlist(char *p, char c)
{
	DIR				*d;
	struct dirent	*dir;
	size_t			i;
	char			**s;

	i = 0;
	if (!(s = (char **)malloc(sizeof(char *) * (ft_dirnum(p) + 1))))
		return (0);
	if ((d = opendir(p)))
	{
		while ((dir = readdir(d)))
		{
			if (ft_strcmp(dir->d_name, ".") == 0)
				s[i++] = ft_strdup(".");
			else
				s[i++] = ft_strdup((const char *)dir->d_name);
		}
		closedir(d);
		s[i] = 0;
		return (ft_sorttype(s, c, p));
	}
	printf("ls: Data: Permission denied\n");
	return (0);
}
