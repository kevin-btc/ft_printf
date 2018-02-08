/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:22:02 by kgricour          #+#    #+#             */
/*   Updated: 2018/02/08 13:01:37 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_x(char **new_str, int i, va_list vl, char *opt)
{	
	char    *tmp;
	char    *tmp2;

	tmp = *new_str;
	if (ft_strchr(opt, 'h') && ft_strchr(opt + 1, 'h'))
		tmp2 = ft_putadr((uintmax_t)(char)va_arg(vl, int), opt);
	else if (ft_strchr(opt, 'l') && ft_strchr(opt + 1, 'l'))
		tmp2 = ft_putadr((uintmax_t)va_arg(vl, long long int), opt);
	else if (ft_strchr(opt, 'h'))
		tmp2 = ft_putadr((uintmax_t)(short int)va_arg(vl, int), opt);
	else if (ft_strchr(opt, 'l'))
		tmp2 = ft_putadr((uintmax_t)va_arg(vl, long int), opt);
	else if (ft_strchr(opt, 'j'))
		tmp2 = ft_putadr((uintmax_t)va_arg(vl, intmax_t), opt);
	else if (ft_strchr(opt, 'z'))
		tmp2 = ft_putadr((uintmax_t)va_arg(vl, size_t), opt);
	else
		tmp2 = ft_putadr((uintmax_t)va_arg(vl, int), opt);
	ft_add_space((char **)&tmp2, opt);
	*new_str = ft_strjoin(ft_strsub(*new_str, 0, i), tmp2);
	ft_strdel(&tmp);
	return (ft_strlen(tmp2));
}
