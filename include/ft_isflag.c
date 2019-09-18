/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isflag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 11:06:45 by pmogwere          #+#    #+#             */
/*   Updated: 2019/08/26 12:48:21 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	checkflags(char c)
{
	int		i;
	char	s[6];

	i = 0;
	s[0] = 'l';
	s[1] = 'R';
	s[2] = 'a';
	s[3] = 't';
	s[4] = 'r';
	s[5] = '-';
	while (i < 6)
	{
		if (c == s[i++])
			return (1);
	}
	return (0);
}

char		ft_isflag(char *s)
{
	int		i;

	i = 1;
	if (s[0] == '-')
	{
		if (ft_strcmp(s, "-stickybit") == 0 || ft_strcmp(s, "-setuid") == 0 ||\
		ft_strcmp(s, "-setgid") == 0)
			return (0);
		else if (ft_strlen(s) > 1)
		{
			while (s[i])
			{
				if (checkflags(s[i]) == 0)
					return (s[i]);
				i++;
			}
		}
	}
	return (0);
}
