/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortarry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 13:00:14 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/02 12:51:51 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		**ft_sortarryt(char **s, char *path)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = 0;
	i = 0;
	j = 0;
	while (s[j] != 0)
	{
		//printf("%s %l\n", s[j],fnanotime(ft_pathname(path, s[j])));
		//printf("%s\n", ft_filetimes(ft_pathname(path, s[j])));
		
		while (s[i] != 0)
		{
			if (ft_strcmp(ft_filetimes(ft_pathname(path, s[j])),\
				ft_filetimes(ft_pathname(path, s[i]))) > 0)
			{
				//printf("%s\n", fnanotime(ft_pathname(path, s[j])));
				if (fnanotime(ft_pathname(path, s[j])) >\
				fnanotime(ft_pathname(path, s[j])))
					continue;
				else{
					str = s[j];
					s[j] = s[i];
					s[i] = str;
				}
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (s);
}

char		**ft_sortarryr(char **s)
{
	char	**str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[j] != 0)
		j++;
	str = (char **)malloc(sizeof(char *) * (j + 1));
	str[j--] = 0;
	while (s[i])
		str[i++] = s[j--];
	return (str);
}

char		**ft_sortarry(char **s)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = 0;
	i = 0;
	j = 0;
	while (s[j] != 0)
	{
		while (s[i] != 0)
		{
			if (ft_strcmp(s[j], s[i]) < 0)
			{
				str = s[j];
				s[j] = s[i];
				s[i] = str;
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (s);
}
