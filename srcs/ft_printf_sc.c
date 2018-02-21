/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 11:58:26 by kgricour          #+#    #+#             */
/*   Updated: 2018/02/21 12:44:20 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_putwstr(wchar_t *s)
{
	char	*new_str;
	char	*tmp2;

	new_str = ft_strnew(0);
	if (s != NULL)
	{
		while (*s)
		{
			tmp2 = ft_putwchar(*s);
			new_str = ft_freejoin(new_str, tmp2, 2);
			s++;
		}
	}
	return (new_str);
}

int			ft_printf_s(char **new_str, int i, va_list vl, char *opt)
{
	char	*tmp;
	char	*str;
	char	*del;
	int		len;

	str = va_arg(vl, char *);
	tmp = *new_str;
	if (str == NULL)
		str = "(null)";
	else if (ft_strchr(opt, 'S') || ft_strchrstr("ls", opt, '&'))
		str = ft_putwstr((wchar_t *)str);
	if (ft_strchr(opt, '.'))
		ft_precision((char **)&str, opt);
	ft_add_space((char **)&str, opt);
	len = ft_strlen(str);
	del = ft_strsub(*new_str, 0, i, 0);
	*new_str = ft_freejoin(del, str, 0);
	ft_strdel(&tmp);
	return (len);
}

int			ft_printf_c(char **new_str, int i, va_list vl, char *opt)
{
	char	*c_to_s;
	int		len;

	len = 0;
	c_to_s = ft_strnew(1);
	if (ft_strchr(opt, 'C') || ft_strchrstr("lc", opt, '&'))
	{
		ft_strdel(&c_to_s);
		if ((c_to_s = ft_putwchar((wchar_t)va_arg(vl, int))) == 0)
		{
			c_to_s = ft_strnew(1);
			c_to_s[0] = '\0';
		}
	}
	else if (ft_strchr(opt, 'c'))
		c_to_s[0] = va_arg(vl, int);
	if (c_to_s[0] == '\0')
		c_to_s[0] = '\1';
	len = ft_strlen(c_to_s);
	ft_add_space((char **)&c_to_s, opt);
	*new_str = ft_freejoin(ft_strsub(*new_str, 0, i, 1), c_to_s, 2);
	return (len);
}
