/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chkvali.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 15:25:46 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/18 15:26:07 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	chkvali(char *flag)
{
	if (ft_strcmp(flag, "stickybit") == 0 ||\
		ft_strcmp(flag, "setuid") == 0 || ft_strcmp(flag, "setgid") == 0)
		return (1);
	return (0);
}
