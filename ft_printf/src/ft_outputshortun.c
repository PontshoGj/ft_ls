/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outputshortun.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 12:48:29 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/14 12:50:36 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_outpsh(short j, int space)
{
	if (space >= 0)
	{
		givespace(ft_intlen(j), space, ' ');
		ft_nbr(j, 2);
	}
	else
	{
		ft_nbr(j, 2);
		givespace(ft_intlen(j), space, ' ');
	}
}

static void		ft_outpshh(short j, int space)
{
	if (space >= 0)
	{
		givespace(ft_intlen(j), space, ' ');
		ft_putnbr(j);
	}
	else
	{
		ft_putnbr(j);
		givespace(ft_intlen(j), space, ' ');
	}
}

void			ft_outputshortun(va_list args, int space, char c)
{
	long long	i;
	short		j;

	if (c == 'h')
	{
		i = va_arg(args, int);
		j = (short)i;
		ft_outpshh(j, space);
		return ;
	}
	i = va_arg(args, unsigned long long);
	j = (short)i;
	j = (char)j;
	ft_outpsh(j, space);
}
