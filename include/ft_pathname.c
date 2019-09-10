/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathname.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 12:54:55 by pmogwere          #+#    #+#             */
/*   Updated: 2019/08/26 12:56:26 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*ft_pathname(char *str, char *dirname)
{
	char	*s;
	char	*temp;

	s = ft_strnew(1);
	temp = s;
	s = ft_strjoin(s, str);
	free(temp);
	if (s[ft_strlen(s)] != '/')
	{
		temp = s;
		s = ft_strjoin(s, "/");
		free(temp);
	}
	temp = s;
	s = ft_strjoin(s, dirname);
	free(temp);
	return (s);
}
