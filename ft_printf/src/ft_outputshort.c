/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outputshort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 12:36:25 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/14 12:37:38 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_outputshort(va_list args, int space, char c)
{
	long long	i;

	(void)space;
	if (c == 'l')
		i = va_arg(args, int);
	else
		i = va_arg(args, long long);
	ft_putnbrlong(i);
}
