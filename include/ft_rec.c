/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 12:23:15 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/16 10:39:37 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_printdir(char **str, char *flag, char *path)
{
	size_t	i;

	i = 0;
	while (str[i] != NULL)
	{
		if (ft_strspn("a", flag) == 1)
			ft_display_all(str[i], flag, path);
		else if (str[i][0] != '.')
			ft_display_all(str[i], flag, path);
		i++;
	}
}

static void	ft_recd(char **str, char *s, char *flag)
{
	size_t	i;
	char	*path;

	i = 1;
	while (str[i] != 0)
	{
		path = ft_pathname(s, str[i]);
		if (isdir(path) \
				&& ft_strcmp(str[i], ".") != 0 \
				&& ft_strcmp(str[i], "..") != 0 \
				&& str[i][0] != '.' \
				&& ft_islink(path) == 0)
		{
			ft_printf("\n%s:\n", path);
			ft_displayrec(path, flag);
		}
		i++;
		free(path);
	}
}

void		ft_displayrec(char *ss, char *flag)
{
	char	**s;

	s = ft_arrydirlist(ss, ft_chksort(flag));
	if (s == 0)
		return ;
	if (ft_strspn("atr", flag) == 3)
		s = ft_sortarryr(s);
	if (ft_strspn("lR", flag) == 2)
		ft_longdisplay(ss, flag);
	else
		ft_printdir(s, flag, ss);
	ft_recd(s, ss, flag);
	ft_freearry(s);
}
