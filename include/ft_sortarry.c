/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortarry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 13:00:14 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/14 11:37:45 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		swap(char **s, char **s2)
{
	char	*str;

	str = *s;
	*s = *s2;
	*s2 = str;
}

char		**ft_sortarryt(char **s, char *path)
{
	char	*str;
	char	*path1;
	char	*path2;
	size_t	i;
	size_t	j;

	str = 0;
	i = 0;
	j = 0;
	while (s[j] != 0)
	{
		path1 = ft_pathname(path, s[j]);
		while (s[i] != 0)
		{
			path2 = ft_pathname(path, s[i]);
			if (fsectime(path1) > fsectime(path2))
				swap(&s[j], &s[i]);
			else if (fsectime(path1) == fsectime(path2))
			{
				if (ft_strcmp(s[j], s[i]))
					swap(&s[i], &s[j]);
			}
			free(path2);
			i++;
		}
		free(path1);
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
	free(s);
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
				swap(&s[j], &s[i]);
			i++;
		}
		i = 0;
		j++;
	}
	return (s);
}
