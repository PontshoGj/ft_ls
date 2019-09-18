/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 12:22:00 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/14 12:23:57 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_outsint(int i, int space, char zeros, char s)
{
	if (s == 'c')
	{
		givespace(1, space, zeros);
		ft_putchar(i);
	}
	else
	{
		givespace((int)ft_intlen(i), space, zeros);
		ft_putnbr(i);
	}
}

void			outint(char s, va_list args, int space, char zeros)
{
	int			i;

	i = va_arg(args, int);
	if (s == '+' && i > 0)
		ft_putchar('+');
	if (space >= 0)
		ft_outsint(i, space, zeros, s);
	if (space < 0)
	{
		if (s == 'c')
		{
			ft_putchar(i);
			givespace(1, space, zeros);
		}
		else
		{
			ft_putnbr(i);
			givespace((int)ft_intlen(i), space, zeros);
		}
	}
}
