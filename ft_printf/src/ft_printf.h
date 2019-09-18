/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 13:40:09 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/14 13:41:20 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
void	outint(char s, va_list args, int i, char zeros);
void	outcharst(char s, va_list args, int i, int length);
void	outuint(char s, va_list args, char hex, int *j);
void	outdoub(char s, va_list args, int size, int z);
void	printstr(char s, va_list args);
void	printxx(char *s, va_list args);
void	prints(int i, char *str, va_list args, char j);
void	printhandler(char **str, va_list args);
void	padd(char **str, va_list args);
void	paddfloat(char **str, va_list args);
void	floatpre(char **str, va_list args, int i);
void	givespace(int i, int space, char give);
void	ft_printlong(char **s, va_list args, int space);
void	ft_outputlong(va_list args, int space, char c);
void	ft_outputlonghex(va_list args, int space, char hex, char c);
void	ft_outputshort(va_list args, int space, char c);
void	ft_outputshorthex(va_list args, int space, char hex, char c);
void	ft_outputshortoct(va_list args, int space, char hex, char c);
void	ft_outputunsignedshort(va_list args, int space, char c);
void	ft_outputunsignedlong(va_list args, int space, char c);
void	ft_outputunsignedlonghex(va_list args, int space, char hex, char c);
void	ft_printshort(char **s, va_list args, int space);
void	ft_addplus(char **s, va_list args);
void	ft_outputshortun(va_list args, int space, char c);
void	ft_nbr(int n, int num);
char	*ft_nbrstr(int n, int num);
void	ft_nbr2(int n, int num);
#endif
