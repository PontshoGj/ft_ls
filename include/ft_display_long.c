/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_long.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 13:06:54 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/14 10:34:02 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_display_long(char *str, char *path)
{
	char *strpath;
	char *temp;

	strpath = ft_pathname(path, str);
	temp = ft_permission(strpath);
	ft_printf("%s", temp);
	free((char *)temp);
	ft_printf("%4d ", ft_filelink(strpath));
	temp = ft_filename(strpath);
	ft_printf("%4s", temp);
	free((char *)temp);
	ft_printf("%7d", ft_filesize(strpath));
	temp = ft_filetimes(strpath);
	ft_printf("%13s", temp);
	free((char *)temp);
	ft_printf(" %s", str);
	if (ft_filetype(strpath) == 'l')
	{
		temp = ft_getlink(strpath);
		ft_printf(" -> %s", temp);
		free((char *)temp);
	}
	ft_printf("\n");
	free((char *)strpath);
}
