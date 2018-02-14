/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:36:40 by kgricour          #+#    #+#             */
/*   Updated: 2018/02/14 23:49:53 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_printf_ss(char **new_str, int i, va_list vl, char *opt)
{

	opt = opt-1; //a suppr
	*new_str = ft_freejoin(ft_strsub(*new_str, 0, i), va_arg(vl, char *), 2);
}

int		ft_printf_c(char **new_str, int i, va_list vl, char *opt)
{
	char	*c_to_s;
	int	len;

	c_to_s = NULL;
	if (ft_strchr(opt, 'c'))
	{
		c_to_s = ft_strnew(2);
		c_to_s[0] = va_arg(vl, int);
		c_to_s[1] = '\0';
	}
	else if (ft_strchr(opt, 'C'))
		c_to_s = ft_putwchar((wchar_t)va_arg(vl, int));
	if (c_to_s[0] == 0)
	{
		c_to_s[0] = '\1';
		len = 1;
	}
	else
		len = ft_strlen(c_to_s);
	ft_add_space((char **)&c_to_s,opt);
	*new_str = ft_freejoin(ft_strsub(*new_str, 0, i), c_to_s, 0);
	return (len);
}

char	*ft_get_opt(char *s)
{
	char	*opt;
	int		i;
	int		k;
	const char *format;
	
	format = "scSbpdDiouUXxC%";
	i = 1;
	k = 1;
	while (!ft_strchr(format, s[i]) && s[i] != '\0')
		i++;
	i++;
	opt = ft_strnew(i);
	while (k < i)
	{
		opt[k-1] = s[k];
		k++;
	}
	
	return (opt);
}

int		ft_check_valide_conv(char *s, int *j)
{
	const char *format;
	const char *flags;
	
	format = "scSbpdDiouUXxC%";
	flags = "#-+jz hl.";

	while (s[*j])
	{
		if (ft_strchr(format, s[*j]))
			return (1);
		else if (ft_strchr(flags, s[*j]) || ft_isdigit(s[*j]))
			*j += 1;
		else
			return (0);
	}
	return (0);
}

char	*ft_find_conv(char *new_str, int *i, int j, va_list vl)
{
	char	*opt;
	const char	*flag_base;

	opt = ft_get_opt(new_str + *i);	
	flag_base = "XxOoUubp";
	if (new_str[*i + j + 1] == '%')
		*i += ft_printf_pct(&new_str, opt, *i);
	else if (new_str[*i + j + 1] == 's' || new_str[*i + j + 1] == 'S')
		*i += ft_printf_s(&new_str, *i, vl, opt);
	else if (new_str[*i + j + 1] == 'c' || new_str[*i + j + 1] == 'C')
		*i += ft_printf_c(&new_str, *i, vl, opt);
	else if (new_str[*i + j + 1] == 'd' || new_str[*i + j + 1] == 'i')
		*i += ft_printf_id(&new_str, *i, vl, opt);
	else if (new_str[*i + j + 1] == 'D')
		*i += ft_printf_ld(&new_str, *i, vl, opt);
	else if (ft_strchr(flag_base, new_str[*i + j + 1]))
		*i += ft_printf_xobup(&new_str, *i, vl, opt);
	return (new_str);
}

int		ft_printf(const char *format, ...)
{
	va_list	vl;
	int		i;
	int		j;
	char	*new_str;
	char	*tmp;

	new_str = ft_strdup(format);
	tmp = ft_strnew(0);
	i = 0;
	va_start(vl, format);
	while (new_str[i])
	{
		j = 0;
		if (new_str[i] == '%')
		{
			
			if (ft_check_valide_conv(&new_str[i + j + 1], &j) == 1)
			{
				tmp = ft_strsub(new_str, i + j + 2, ft_strlen(new_str));
				new_str = ft_freejoin(ft_find_conv(new_str, &i, j, vl), tmp, 1);
				i--;
			}
			else if (ft_check_valide_conv(&new_str[i + j + 1], &j) == 0)
			{
				tmp = ft_strsub(new_str, i + j + 1, ft_strlen(new_str));
				ft_add_space(&tmp, ft_strsub(new_str, i + 1, i + j));
				new_str = ft_freejoin(ft_strsub(new_str, 0, i ), tmp, 1);
				i--;
			}
		}
		i++;
	}
	va_end(vl);
	i = 0;
	while (new_str[i])
	{
		if (new_str[i] == '\1')
		{
			ft_putchar(0);
		}
		else
			ft_putchar(new_str[i]);
		i++;
	}
	return (ft_strlen(new_str));
}
