/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_id.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 15:33:36 by kgricour          #+#    #+#             */
/*   Updated: 2018/02/08 16:55:59 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int        ft_printf_id(char **new_str, int i, va_list vl, char *opt)
{
	char    *tmp;
	char    *tmp2;
	char	*adr;

	tmp = *new_str;
	if ((adr = ft_strchr(opt, 'h')) && ft_strchr(adr + 1, 'h'))
		tmp2 = ft_itoa((char)va_arg(vl, int));
	else if ((adr = ft_strchr(opt, 'l')) && ft_strchr(adr + 1, 'l'))
		tmp2 = ft_itoa(va_arg(vl, long long int));
	else if (ft_strchr(opt, 'h'))
		tmp2 = ft_itoa((short int)va_arg(vl, int));
	else if (ft_strchr(opt, 'l'))
		tmp2 = ft_itoa(va_arg(vl, long int));
	else if (ft_strchr(opt, 'j'))
		tmp2 = ft_itoa(va_arg(vl, intmax_t));
	else if (ft_strchr(opt, 'z'))
		tmp2 = ft_itoa(va_arg(vl, size_t));
	else
		tmp2 = ft_itoa(va_arg(vl, int));
	if (opt[0] == '0' && ft_strchr(opt, '+') != NULL)
	{
		ft_add_space((char **)&tmp2, opt);
		tmp2 = ft_strjoin("+", tmp2);
	}
	else if (tmp2[0] != '-' && ft_strchr(opt, '+') != NULL)
	{
		tmp2 = ft_strjoin("+", tmp2);
		ft_add_space((char **)&tmp2, opt);
	}
	else
		ft_add_space((char **)&tmp2, opt);
	*new_str = ft_strjoin(ft_strsub(*new_str, 0, i), tmp2);
	ft_strdel(&tmp);
	return (ft_strlen(tmp2));
}
