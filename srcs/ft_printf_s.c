/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 11:58:26 by kgricour          #+#    #+#             */
/*   Updated: 2018/02/14 15:30:06 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int	ft_printf_s(char **new_str, int i, va_list vl, char *opt)
{
	char *tmp;
	char *str;

	str = va_arg(vl, char *);
	tmp = *new_str;
	if (str == NULL)
		str = "(null)";
	else if (ft_strchr(opt, 'S'))
		str = ft_putwstr((wchar_t *)str);
	if (ft_strchr(opt, '.'))
		ft_precision((char **)&str, opt);
	ft_add_space((char **)&str, opt);
	*new_str = ft_strjoin(ft_strsub(*new_str, 0, i), str);
	ft_strdel(&tmp);
	return (ft_strlen(str));
}
