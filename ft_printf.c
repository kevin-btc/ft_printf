/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:36:40 by kgricour          #+#    #+#             */
/*   Updated: 2018/01/20 19:14:16 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_count_space(char *opt, int nbr_letters_add)
{
	int i;
	int nbr;
	char *space;

	i = 0;
	nbr = 0;
	while (opt[i])
	{
		if (ft_isdigit(opt[i]))
		{
			if ((nbr = ft_atoi(&opt[i]) - nbr_letters_add) < 1)
				return (NULL);;
			space = ft_strnew(nbr);
			ft_memset(space, ' ', nbr);
			return (space);
		}
		i++;
	}
	return (NULL);
}

void	ft_add_space(char **tmp2, char *opt)
{
	if (ft_count_space(opt, ft_strlen(*tmp2)) != NULL)
	{
		if (ft_strchr(opt, '-'))
			*tmp2 = ft_strjoin(*tmp2, ft_count_space(opt,ft_strlen(*tmp2)));
		else 	
			*tmp2 = ft_strjoin(ft_count_space(opt,ft_strlen(*tmp2)), *tmp2);
	}
}

void	ft_printf_s(char **new_str, int i, va_list vl, char *opt)
{
	char *tmp;
	char *str;

	if (!(str = va_arg(vl, char *)))
		str = "(null)";
	opt = NULL; //a suppr
	tmp = *new_str;
	*new_str = ft_strjoin(ft_strsub(*new_str, 0, i), str);
	ft_strdel(&tmp);
}

void	ft_printf_S(char **new_str, int i, va_list vl, char *opt)
{
	char *tmp;

	opt = NULL; //a suppr
	tmp = *new_str;
	*new_str = ft_strjoin(ft_strsub(*new_str, 0, i), va_arg(vl, char *));
	ft_strdel(&tmp);
}

void	ft_printf_p(char **new_str, int i, va_list vl, char *opt)
{
	char *tmp;
	char *res;

	opt = NULL;//a suppr
	tmp = *new_str;
	res = va_arg(vl, char *);
	*new_str = ft_strjoin(ft_strsub(*new_str, 0, i), ft_putadr(res));
	ft_strdel(&tmp);
}

void	ft_printf_c(char **new_str, int i, va_list vl, char *opt)
{
	char *tmp;
	char *c_to_s;

	opt = NULL;//a suppr
	c_to_s = ft_strnew(1);
	tmp = *new_str;	
	c_to_s[0] = va_arg(vl, int);
	*new_str = ft_strjoin(ft_strsub(*new_str, 0, i), &c_to_s[0]); 
	ft_strdel(&tmp);
	ft_strdel(&c_to_s);
}

void    ft_printf_pct(char **new_str, int i, char *opt)
{
	opt = NULL;//a suppr
		*new_str = ft_strdup(ft_strsub(*new_str, 0, i + 1));
}

void	ft_printf_id(char **new_str, int i, va_list vl, char *opt)
{
	char	*tmp;
	void	*tmp2;

	tmp = *new_str;
	if (ft_strchr(opt, 'h') && ft_strchr(opt + 1, 'h'))
		tmp2 = ft_itoa((char)va_arg(vl, int));
	else if (ft_strchr(opt, 'h'))
		tmp2 = ft_itoa((short int)va_arg(vl, int));
	else if (ft_strchr(opt, 'l') && ft_strchr(opt + 1, 'l'))
		tmp2 = ft_itoa(va_arg(vl, long long int));
	else if (ft_strchr(opt, 'l'))
		tmp2 = ft_itoa(va_arg(vl, long int));
	else if (ft_strchr(opt, 'j'))
		tmp2 = ft_itoa(va_arg(vl, intmax_t));
	else if (ft_strchr(opt, 'z'))
		tmp2 = ft_itoa(va_arg(vl, size_t));
	else
		tmp2 = ft_itoa(va_arg(vl, int));
	ft_add_space((char **)&tmp2, opt);
	*new_str = ft_strjoin(ft_strsub(*new_str, 0, i), tmp2);
	ft_strdel(&tmp);
}

void	ft_printf_ld(char **new_str, int i, va_list vl, char *opt)
{
	char	*tmp;
	void	*tmp2;

	tmp = *new_str;
	if (ft_strchr(opt, 'l') && ft_strchr(opt + 1, 'l'))
		tmp2 = ft_itoa(va_arg(vl, unsigned long long int));
	else if (ft_strchr(opt, 'l'))
		tmp2 = ft_itoa(va_arg(vl, unsigned long int));
	else if (ft_strchr(opt, 'j'))
		tmp2 = ft_itoa(va_arg(vl, intmax_t));
	else if (ft_strchr(opt, 'z'))
		tmp2 = ft_itoa(va_arg(vl, size_t));
	else
		tmp2 = ft_itoa(va_arg(vl, unsigned long int));
	ft_add_space((char **)&tmp2, opt);
	*new_str = ft_strjoin(ft_strsub(*new_str, 0, i), tmp2);
	ft_strdel(&tmp);
}

int	ft_check_valide_conv(char *s, int *j, int *i)
{
	while (s[*j])
	{
		if (s[*j] == '#' || s[*j] == '-' || s[*j] == '+' || ft_isdigit(s[*j]) ||s[*j] == 'j'
			|| s[*j] == 'z' || s[*j] == ' ' || s[*j] == 'h' || s[*j] == 'l')
			*j += 1;
		else if (s[*j]== 's' || s[*j] == 'S' || s[*j] == 'p' || s[*j] == 'd' || s[*j] == 'D' ||  
	 			s[*j]== 'i' || s[*j] == 'o' || s[*j] == 'u' || s[*j] == 'x' ||
				s[*j]== 'X' || s[*j] == 'c' || s[*j] == 'C' || s[*j] == '%')
			return (1);
		else
		{
			if (*j == 0)
				*i -= 1;
			else
				*j -= 1;

			return (0);
		}
	}
	return (1);
}

char	*ft_find_conv(char *new_str, int i, int j, va_list vl)
{
	char	*opt;
	char	*tmp;

	tmp = ft_strnew(0);
	opt = ft_strsub(new_str, i + 1, i + j);
	if (new_str[i + j + 1] == '%')
		ft_printf_pct(&new_str, i, opt);
	else if (new_str[i + j + 1] == 's')
		ft_printf_s(&new_str, i, vl, opt);
	else if (new_str[i + j + 1] == 'p')
		ft_printf_p(&new_str, i, vl, opt);
	else if (new_str[i + j + 1] == 'c')
		ft_printf_c(&new_str, i, vl, opt);
	else if (new_str[i + j + 1] == 'd' || new_str[i + j + 1] == 'i')
		ft_printf_id(&new_str, i, vl, opt);
	else if (new_str[i + j + 1] == 'D')
		ft_printf_ld(&new_str, i, vl, opt);
	else
	{
		ft_add_space(&tmp, opt);
		new_str = ft_strjoin(ft_strsub(new_str,0 , i), tmp + 1);
		ft_strdel(&tmp);
	}
	return (new_str);
}

int ft_printf(const char *format, ...)
{
	va_list vl;
	int i;
	int j;
	char *new_str;
	char *tmp;

	new_str = ft_strdup(format);
	i = 0;
	va_start(vl, format);
	while (new_str[i])
	{
		j = 0;
		if (new_str[i] == '%')
		{
			ft_check_valide_conv(&new_str[i + j + 1], &j, &i);
			tmp = ft_strsub(new_str , i + j + 2, ft_strlen(new_str));
			new_str = ft_strjoin(ft_find_conv(new_str, i, j, vl), tmp);
		}
		i++;
	}
	va_end(vl);
	ft_putstr(new_str);
	return (ft_strlen(new_str));
}
