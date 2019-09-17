/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkfl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 13:53:09 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/17 13:53:51 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			checkfl(char *str)
{
	char	s;

	if (!(s = ft_isflag(str)))
		return (1);
	ft_printf("ft_ls: illegal option -- %c\nusage: ft_ls [-Ralrt] \
			[file ...]\n", s);
	exit(1);
}
