/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 10:39:09 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/17 13:57:53 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		displaysr(char *s, char *flag)
{
	if (ft_strspn("R", flag))
		ft_displayrec(s, flag);
}

static void		displaysa(char *s, char *flag)
{
	if (ft_strspn("a", flag))
		ft_display_all(s, flag, "");
}

static void		displays(char *s, char *flag)
{
	if (ft_strspn("a", flag))
		displaysa(s, flag);
	else if (s[0] != '.')
		ft_display_all(s, flag, ".");
}

static void		prin(char *str, char *flag)
{
	if (ft_strspn("R", flag) && isdir(str))
	{
		displaysr(str, flag);
		ft_printf("\n\n");
	}
	else if (ft_strspn("l", flag) && isdir(str))
		ft_longdisplay(str, flag);
	else if (isfile(str))
		ft_display_all(str, flag, ".");
	else if (ft_strcmp(flag, "stickybit") == 0)
		stickybit(str);
	else if (ft_strcmp(flag, "setuid") == 0)
	{
		setugid(".", str);
		ft_printf("\n");
	}
	else if (ft_strcmp(flag, "setgid") == 0)
		setgids(".", str);
}

void			ft_display_dir(char *str, char *flag)
{
	int			i;
	char		**arrlist;
	static int	j;

	i = 0;
	if (!j)
		j = 0;
	if (((ft_strspn("l", flag) || ft_strspn("R", flag)) \
		&& isdir(str)) || isfile(str) || chkvali(flag))
	{
		prin(str, flag);
		j++;
	}
	else if (isdir(str))
	{
		arrlist = ft_arrydirlist(str, ft_chksort(flag));
		if (ft_strspn("tr", flag) == 2)
			arrlist = ft_sortarryr(arrlist);
		if (j != 0)
			ft_printf("\n%s:\n", str);
		while (arrlist[i] != 0)
			displays(arrlist[i++], flag);
		ft_printf("\n");
		ft_freearry(arrlist);
	}
}
