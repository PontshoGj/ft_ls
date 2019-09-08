/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_long.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 13:06:54 by pmogwere          #+#    #+#             */
/*   Updated: 2019/08/26 13:07:17 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_display_long(char *str, char *path)
{
	char *strpath;
	char *s;

	strpath = ft_pathname(path, str); 
	ft_printf("%s", ft_permission(strpath));
	ft_printf("%4d ", ft_filelink(strpath));
	s = ft_filename(strpath);
	ft_printf("%4s", s);
	free(s);
	ft_printf("%7d", ft_filesize(strpath));
	s = ft_filetimes(strpath);
	ft_printf("%13s", s);
	free(s);
	ft_printf(" %s", str);
	if (ft_filetype(strpath) == 'l')
	{
		s = ft_getlink(strpath);
		ft_printf(" -> %s", s);
	}
	ft_printf("\n");
	free(strpath);
}
