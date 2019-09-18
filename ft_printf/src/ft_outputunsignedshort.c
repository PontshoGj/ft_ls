/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outputunsignedshort.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 12:56:44 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/14 12:59:03 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_outpsh(short j, int space)
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

static void		ft_outpshh(short j, int space)
{
	if (space >= 0)
	{
		givespace(ft_intlen(j), space, ' ');
		ft_nbr(j, 3);
	}
	else
	{
		ft_nbr(j, 3);
		givespace(ft_intlen(j), space, ' ');
	}
}

void			ft_outputunsignedshort(va_list args, int space, char c)
{
	long long	i;
	short		j;

	(void)space;
	if (c == 'h')
	{
		i = va_arg(args, int);
		j = (short)i;
		j = (unsigned char)j;
		ft_outpshh(j, space);
		return ;
	}
	i = va_arg(args, unsigned long long);
	j = (unsigned short)i;
	ft_outpsh(j, space);
}
