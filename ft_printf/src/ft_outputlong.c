/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outputlong.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 12:29:36 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/14 12:35:52 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_outpl(long long i, int space, char c, char hex)
{
	if (space >= 0)
	{
		givespace(ft_intlen(i), space, c);
		ft_putstr(ft_longtoa_base(i, 16, hex));
	}
	else
	{
		ft_putstr(ft_longtoa_base(i, 16, hex));
		givespace(ft_intlen(i), space, c);
	}
}

static void		ft_outplh(long long i, int space, char c)
{
	if (space >= 0)
	{
		givespace(ft_intlen(i), space, c);
		ft_putnbrlong(i);
	}
	else
	{
		ft_putnbrlong(i);
		givespace(ft_intlen(i), space, c);
	}
}

void			ft_outputlong(va_list args, int space, char c)
{
	long long	i;

	if (c == 'l')
	{
		i = va_arg(args, long);
		ft_outplh(i, space, c);
	}
	else
	{
		i = va_arg(args, long long);
		ft_outplh(i, space, c);
	}
}

void			ft_outputlonghex(va_list args, int space, char hex, char c)
{
	long long	i;

	if (c == 'l')
	{
		i = va_arg(args, long);
		ft_outpl(i, space, c, hex);
	}
	else
	{
		i = va_arg(args, long long);
		ft_outpl(i, space, c, hex);
	}
}
