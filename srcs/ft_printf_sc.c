/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 11:58:26 by kgricour          #+#    #+#             */
/*   Updated: 2018/02/28 18:52:18 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_putwstr(wchar_t *s)
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

static void		ft_apply_opt(char *opt, char **str, int *space)
{
	char	*ptr_trash;

	if (ft_strchr(opt, 'S') || ft_strchrstr("ls", opt, '&'))
		*str = ft_putwstr((wchar_t *)*str);
	if (ft_strchr(opt, '.'))
		ft_precision((char **)str, opt);
	if (ft_check_point(opt, *str))
	{
		ptr_trash = *str;
		ft_add_space(str, opt);
		*space = 1;
		if (ft_strchr(opt, 'S') || ft_strchrstr("ls", opt, '&'))
			ft_strdel(&ptr_trash);
	}
}

int				ft_printf_s(char **new_str, int i, va_list vl, char *opt)
{
	char	*str;
	char	*del;
	int		len;
	int		space;

	str = va_arg(vl, char *);
	space = 0;
	if (str == NULL)
	{
		del = ft_strsub(*new_str, 0, i, 1);
		*new_str = ft_freejoin(del, "(null)", 0);
		len = 6;
		return (len);
	}
	ft_apply_opt(opt, &str, &space);
	len = ft_strlen(str);
	del = ft_strsub(*new_str, 0, i, 1);
	if (ft_strchr(opt, 'S') || ft_strchrstr("ls", opt, '&') || space == 1)
		*new_str = ft_freejoin(del, str, 2);
	else
		*new_str = ft_freejoin(del, str, 0);
	return (len);
}

void			ft_wchar_to_str(char **c_to_s, va_list vl)
{
	if ((*c_to_s = ft_putwchar((wchar_t)va_arg(vl, int))) == 0)
	{
		*c_to_s = ft_strnew(1);
		*c_to_s[0] = '\0';
	}
}

int				ft_printf_c(char **new_str, int i, va_list vl, char *opt)
{
	char	*c_to_s;
	char	*ptr_trash;
	char	*del;
	int		len;

	len = 0;
	c_to_s = ft_strnew(1);
	if (ft_strchr(opt, 'C') || ft_strchrstr("lc", opt, '&'))
	{
		ft_strdel(&c_to_s);
		ft_wchar_to_str(&c_to_s, vl);
	}
	else if (ft_strchr(opt, 'c'))
		c_to_s[0] = va_arg(vl, int);
	(c_to_s[0] == '\0') ? c_to_s[0] = '\1' : c_to_s[0];
	len = ft_strlen(c_to_s);
	if (ft_check_point(opt, c_to_s))
	{
		ptr_trash = c_to_s;
		ft_add_space((char **)&c_to_s, opt);
		ft_strdel(&ptr_trash);
	}
	del = ft_strsub(*new_str, 0, i, 1);
	*new_str = ft_freejoin(del, c_to_s, 2);
	return (len);
}
