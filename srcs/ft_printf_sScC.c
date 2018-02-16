/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 11:58:26 by kgricour          #+#    #+#             */
/*   Updated: 2018/02/16 18:51:22 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_sS(char **new_str, int i, va_list vl, char *opt)
{
	char	*tmp;
	char	*str;
	int		len;

	str = va_arg(vl, char *);
	tmp = *new_str;
	if (str == NULL)
		str = "(null)";
	else if (ft_strchr(opt, 'S'))
		str = ft_putwstr((wchar_t *)str);
	if (ft_strchr(opt, '.'))
		ft_precision((char **)&str, opt);
	ft_add_space((char **)&str, opt);
	len = ft_strlen(str);
	*new_str = ft_freejoin(ft_strsub(*new_str, 0, i, 0), str, 0);
	ft_strdel(&tmp);
	return (len);
}

int     ft_printf_cC(char **new_str, int i, va_list vl, char *opt)
{
	char    *c_to_s;
	int len;

	len = 0;
	c_to_s = ft_strnew(1);
	if (ft_strchr(opt, 'c'))
		c_to_s[0] = va_arg(vl, int);
	else if (ft_strchr(opt, 'C'))
	{
		ft_strdel(&c_to_s);
		c_to_s = ft_putwchar((wchar_t)va_arg(vl, int));
	}
	if (c_to_s[0] == 0)
		c_to_s[0] = '\1';
	len = ft_strlen(c_to_s);
	ft_add_space((char **)&c_to_s, opt);
	*new_str = ft_freejoin(ft_strsub(*new_str, 0, i, 1), c_to_s, 2);
	return (len);
}
