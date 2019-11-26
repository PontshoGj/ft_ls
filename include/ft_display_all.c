/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 13:08:53 by pmogwere          #+#    #+#             */
/*   Updated: 2019/08/26 13:10:04 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_display_all(char *str, char *flag, char *path)
{
	if (ft_strspn("l", flag) == 1)
		ft_display_long(str, path);
	else
		ft_printf("%s\n", str);
}
