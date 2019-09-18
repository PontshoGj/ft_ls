/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 13:15:37 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/14 13:18:02 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *str, ...)
{
	va_list	args;

	va_start(args, str);
	while (*str != 0)
	{
		if (*str == '%')
		{
			str++;
			printhandler((char **)&str, args);
		}
		else
			ft_putchar(*str);
		str++;
	}
	va_end(args);
	return (0);
}
