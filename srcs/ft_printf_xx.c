/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 18:51:33 by kgricour          #+#    #+#             */
/*   Updated: 2018/02/08 18:33:26 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_xx(char **new_str, int i, va_list vl, char *opt)
{	
	char    *tmp;
	char    *tmp2;
	char	*adr;

	tmp = *new_str;
	if ((adr = ft_strchr(opt, 'h')) && ft_strchr(adr + 1, 'h'))
		tmp2 = ft_putadr((unsigned long long)(char)va_arg(vl, int), opt, 1);
	else if ((adr = ft_strchr(opt, 'l')) && ft_strchr(adr + 1, 'l'))
		tmp2 = ft_putadr((unsigned long long)va_arg(vl, long long int), opt, 16);
	else if (ft_strchr(opt, 'h'))
		tmp2 = ft_putadr((unsigned long long)(short int)va_arg(vl, int), opt, 3);
	else if (ft_strchr(opt, 'l'))
		tmp2 = ft_putadr((unsigned long long)va_arg(vl, long int), opt, 16);
	else if (ft_strchr(opt, 'j'))
		tmp2 = ft_putadr((unsigned long long)va_arg(vl, intmax_t), opt, 16);
	else if (ft_strchr(opt, 'z'))
		tmp2 = ft_putadr((unsigned long long)va_arg(vl, size_t), opt, 16);
	else
		tmp2 = ft_putadr(va_arg(vl, int), opt, 7);
	*new_str = ft_strjoin(ft_strsub(*new_str, 0, i), tmp2);
	ft_strdel(&tmp);
	return (ft_strlen(tmp2));
}
