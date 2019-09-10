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
	char 	*temp;
	char	*temp2;
	char	*path1;
	char	*path2;
	size_t	i;
	size_t	j;

	str = 0;
	i = 0;
	j = 0;
	temp = 0;
	temp2 = 0;
	while (s[j] != 0)
	{
		path1 = ft_pathname(path, s[j]);
		temp = ft_filetimes(path1);
		while (s[i] != 0)
		{
			path2 = ft_pathname(path, s[i]);
			temp2 = ft_filetimes(path2);
			if (ft_strcmp(temp, temp2) > 0) 
			{
					str = s[j];
					s[j] = s[i];
					s[i] = str;
				
			}
			/*else if (ft_strcmp(temp, temp2) < 0)
			{
					i++;
				continue;
			}*/
			/*else{
				if (fnanotime(path1) > fnanotime(path2))
				{
					str = s[j];
					s[j] = s[i];
					s[i] = str;}
			}*/
			free(path2);
			free(temp2);
			i++;
		}
		free(path1);
		free(temp);
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
