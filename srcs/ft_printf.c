/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:36:40 by kgricour          #+#    #+#             */
/*   Updated: 2018/02/08 12:29:32 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_printf_ss(char **new_str, int i, va_list vl, char *opt)
{
	char *tmp;

	opt = opt-1; //a suppr
	tmp = *new_str;
	*new_str = ft_strjoin(ft_strsub(*new_str, 0, i), va_arg(vl, char *));
	ft_strdel(&tmp);
}

int		ft_printf_p(char **new_str, int i, va_list vl, char *opt)
{
	char *tmp;
	unsigned long long res;

	opt = opt -1;
	tmp = *new_str;
	res = (unsigned long long)va_arg(vl, char *);
	*new_str = ft_strjoin(ft_strsub(*new_str, 0, i), ft_putadr(res, "#"));
	ft_strdel(&tmp);
	return (ft_strlen(ft_putadr(res, "#")));
}

int		ft_printf_c(char **new_str, int i, va_list vl, char *opt)
{
	char *tmp;
	char *c_to_s;

	opt = opt -1;//a suppr
	c_to_s = ft_strnew(1);
	tmp = *new_str;
	c_to_s[0] = va_arg(vl, int);
	*new_str = ft_strjoin(ft_strsub(*new_str, 0, i), &c_to_s[0]);
	ft_strdel(&tmp);
	ft_strdel(&c_to_s);
	return (ft_strlen(c_to_s));
}

char	*ft_get_opt(char *s)
{
	char	*opt;
	int		i;
	int		k;

	i = 1;
	k = 1;
	while (s[i] != 's' && s[i] != 'c' &&/*s[i] != 'S' &&*/ s[i] != 'p' && s[i] != 'd' &&
		/*s[i] != 'D' &&*/ s[i] != 'i' &&/* s[i] != 'o' && s[i] != 'u' &&
		s[i] != 'x' && s[i] != 'X' && s[i] != 'C' &&*/
		s[i] != '%' && s[i] != '\0')
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
	while (s[*j])
	{
		if (s[*j] == 's' || s[*j] == 'c' ||/* s[*j] == 'S' ||*/ s[*j] == 'p' || s[*j] == 'd' ||
			/*s[*j] == 'D' ||*/ s[*j] == 'i' ||/* s[*j] == 'o' || s[*j] == 'u' ||
			*/s[*j] == 'X' || s[*j] == 'x' ||/* s[*j] == 'C' ||*/
			s[*j] == '%')
			return (1);
		else if (s[*j] == '#' || s[*j] == '-' || s[*j] == '+' || ft_isdigit(s[*j]) ||
			s[*j] == 'j' || s[*j] == 'z' || s[*j] == ' ' || s[*j] == 'h' ||
			s[*j] == 'l' || s[*j] == '.')
			*j += 1;
		else
		{
			*j -= 1;
			return (0);
		}
	}
	return (0);
}

char	*ft_find_conv(char *new_str, int *i, int j, va_list vl)
{
	char	*opt;
	char	*tmp;

	tmp = ft_strnew(0);
	opt = ft_get_opt(new_str + *i);
	if (new_str[*i + j + 1] == '%')
		*i += ft_printf_pct(&new_str, opt, *i);
	else if (new_str[*i + j + 1] == 's')
		*i += ft_printf_s(&new_str, *i, vl, opt);
	else if (new_str[*i + j + 1] == 'p')
		*i += ft_printf_p(&new_str, *i, vl, opt);
	else if (new_str[*i + j + 1] == 'c')
		*i += ft_printf_c(&new_str, *i, vl, opt);
	else if (new_str[*i + j + 1] == 'd' || new_str[*i + j + 1] == 'i')
		*i += ft_printf_id(&new_str, *i, vl, opt);
	else if (new_str[*i + j + 1] == 'D')
		*i += ft_printf_ld(&new_str, *i, vl, opt);
	else if (new_str[*i + j + 1] == 'x')
		*i += ft_printf_x(&new_str, *i, vl, opt);
	else if (new_str[*i + j + 1] == 'X')
		*i += ft_printf_xx(&new_str, *i, vl, opt);
	ft_strdel(&tmp);
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
				new_str = ft_strjoin(ft_find_conv(new_str, &i, j, vl), tmp);
			i--;
			}
			else if (ft_check_valide_conv(&new_str[i + j + 1], &j) == 0)
			{
				tmp = ft_strsub(new_str, i + j + 1, ft_strlen(new_str));
				new_str = ft_strjoin(ft_strsub(new_str, 0, i), tmp);
				i--;
			}
		}
		i++;
	}
	va_end(vl);
	ft_putstr(new_str);
	ft_strdel(&tmp);
	return (ft_strlen(new_str));
}
