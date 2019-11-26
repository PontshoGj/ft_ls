/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 11:02:24 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/17 13:55:16 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		chkfd(char **dir)
{
	char		**s;

	s = dir;
	if (!*dir)
		return ;
	checkfiledir(*s);
	if (*s++)
		chkfd(s);
}

static void		printdir(char **dir, char *flag)
{
	int			i;

	i = 0;
	if (!*dir)
	{
		ft_display_dir(".", flag);
		return ;
	}
	if (ft_strspn(flag, "t"))
		dir = ft_sortarryr2(dir);
	if (ft_strspn(flag, "r"))
		dir = ft_sortarryt(dir, ".");
	chkfd(dir);
	while (dir[i])
	{
		if (isdir(dir[i]) || isfile(dir[i]))
			ft_display_dir(dir[i], flag);
		i++;
	}
	ft_printf("\n");
}

static void		ls(int argc, char **argv)
{
	int			i;
	int			j;
	char		*s;
	char		*temp;

	i = 1;
	j = 0;
	s = ft_strnew(1);
	if (argc == 1)
		ft_display_dir(".", s);
	if (argc > 1)
	{
		while (i < argc && argv[i][0] == '-')
		{
			if (argv[i][0] == '-' && checkfl(argv[i]))
			{
				temp = s;
				s = ft_strjoin(s, ++argv[i]);
				free(temp);
			}
			i++;
		}
		printdir(argv + i, s);
	}
	free(s);
}

int				main(int ac, char **av)
{
	ls(ac, av);
	sleep(10);
	return (0);
}
