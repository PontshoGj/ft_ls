/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outputunsignedlong.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 12:52:59 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/14 14:36:53 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_outpul(long long i, int space, char hex)
{
	if (space >= 0)
	{
		givespace(ft_intlen(i), space, ' ');
		ft_putstr(ft_longtoa_base(i, 8, hex));
	}
	else
	{
		ft_putstr(ft_longtoa_base(i, 8, hex));
		givespace(ft_intlen(i), space, ' ');
	}
}

static void		ft_outpull(long long i, int space)
{
	if (space >= 0)
	{
		givespace(ft_intlen(i), space, ' ');
		ft_putnbrlong(i);
	}
	else
	{
		ft_putnbrlong(i);
		givespace(ft_intlen(i), space, ' ');
	}
}

void			ft_outputunsignedlong(va_list args, int space, char c)
{
	long long	i;

	if (c == 'l')
	{
		i = va_arg(args, long);
		ft_outpull(i, space);
	}
	else
	{
		i = va_arg(args, unsigned long long);
		ft_outpull(i, space);
	}
}

void			ft_outputunsignedlonghex(va_list args, \
		int space, char hex, char c)
{
	long long	i;

	if (c == 'l')
	{
		i = va_arg(args, unsigned long);
		ft_outpul(i, space, hex);
	}
	else
	{
		i = va_arg(args, unsigned long long);
		ft_outpul(i, space, hex);
	}
}
