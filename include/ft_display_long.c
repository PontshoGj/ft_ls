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

	strpath = ft_pathname(path, str);
	printf("%s", ft_permission(strpath));
	printf("%4d ", ft_filelink(strpath));
	printf("%4s", ft_filename(strpath));
	printf("%7d", ft_filesize(strpath));
	printf("%13s", ft_filetimes(strpath));
	printf(" %s\n", str);
}
