/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkfiledir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 13:58:21 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/17 13:58:24 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	checkfiledir(char *s)
{
	if (isdir(s) || isfile(s))
		return (1);
	ft_printf("ls: %s: No such file or directory\n", s);
	return (0);
}
