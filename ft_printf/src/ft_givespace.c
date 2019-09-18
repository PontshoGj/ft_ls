/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_givespace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 12:10:06 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/14 12:11:35 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	givespace(int i, int space, char give)
{
	if (i < space)
	{
		space -= i;
		while (space-- > 0)
		{
			if (give == '0')
				ft_putchar('0');
			else
				ft_putchar(' ');
		}
	}
	else if (space < 0 && (i * -1) > space)
	{
		space += i;
		while (space++ < 0)
		{
			if (give == '0')
				ft_putchar('0');
			else
				ft_putchar(' ');
		}
	}
}
