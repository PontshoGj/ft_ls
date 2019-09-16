/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 11:02:24 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/16 10:36:26 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	checkfl(char *str)
{
	char	s;

	if (!(s = ft_isflag(str)))
		return (1);
	ft_printf("ft_ls: illegal option -- %c\nusage: ft_ls [-Ralrt] \
			[file ...]\n", s);
	exit(1);
}

static int	checkfiledir(char *s)
{
	if (isdir(s) || isfile(s))
		return (1);
	ft_printf("ls: %s: No such file or directory\n", s);
	return (0);
}

static void	printdir(char **dir, char *flag)
{
	int		i;

	i = 0;
	if (!*dir)
	{
		ft_display_dir(".", flag);
		return ;
	}
	ft_sortarry(dir);
	while (dir[i])
	{
		if (checkfiledir(dir[i]) == 0)
			dir[i] = "NULL";
		i++;
	}
	i = 0;
	while (dir[i])
	{
		if (ft_strcmp(dir[i], "NULL"))
			ft_display_dir(dir[i], flag);
		i++;
	}
}

void		ls(int argc, char **argv)
{
	int		i;
	int		j;
	char	*s;
	char	*temp;

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

int			main(int ac, char **av)
{
	ls(ac, av);
	//sleep(20);
	return (0);
}
