/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 11:46:24 by kgricour          #+#    #+#             */
/*   Updated: 2018/02/02 17:19:32 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct    s_str
{
	char    *str;
	char    *begin_new_str;
	char    *end_new_str;
	char    *add_param_str;

}                t_str;

char    *ft_count_caract(char *opt, int nbr_letters_add)
{
	int        i;
	char    *space;
	int        nbr;
	char    c;

	i = 0;
	c = '0';
	while (opt[i])
	{
		if (ft_isdigit(opt[i]))
		{
			if ((nbr = ft_atoi(&opt[i]) - nbr_letters_add) < 1)
				return (NULL);
			space = ft_strnew(nbr);
			if (ft_strchr(opt, '-') != NULL || (nbr > 0 && opt[i] != '0'))
				c = ' ';
			ft_memset(space, c, nbr);
			return (space);
		}
		i++;
	}
	return (NULL);
}

void    ft_add_space(char **tmp2, char *opt)
{
	char *str_added;
//	printf("opt = %s\n",opt);
	str_added = ft_count_caract(opt, ft_strlen(*tmp2));
//	printf("str_added = %s\n", str_added);
	if (str_added != NULL)
	{
		if (ft_strchr(opt, '-'))
		{
			*tmp2 = ft_strjoin(*tmp2, str_added);
	//	printf("1 - *tmp2 = %s\n", *tmp2);
		}
		else
			*tmp2 = ft_strjoin(str_added, *tmp2);
	}
}

void    ft_printf_ss(char **new_str, int i, va_list vl, char *opt)
{
	char *tmp;

	opt = NULL; //a suppr
	tmp = *new_str;
	*new_str = ft_strjoin(ft_strsub(*new_str, 0, i), va_arg(vl, char *));
	ft_strdel(&tmp);
}

int        ft_printf_p(char **new_str, int i, va_list vl, char *opt)
{
	char *tmp;
	char *res;

	opt = NULL;//a suppr
	tmp = *new_str;
	res = va_arg(vl, char *);
	*new_str = ft_strjoin(ft_strsub(*new_str, 0, i), ft_putadr(res));
	ft_strdel(&tmp);
	return (ft_strlen(ft_putadr(res)));
}

int        ft_printf_c(char **new_str, int i, va_list vl, char *opt)
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
	return (ft_strlen(c_to_s));
}

int        ft_printf_pct(char **new_str, char *opt, int i)
{
	char    *tmp2;
	tmp2 = ft_strnew(0);
	if (ft_strchr(opt, '-') == NULL && new_str[0][i + 1] != '%')
	{
		ft_add_space(&tmp2, opt);
		tmp2 = ft_strjoin(tmp2, "%");
		tmp2 = ft_strjoin(ft_strsub(*new_str, 0 , i),ft_strdup(tmp2 + 1));
	}
	else if (ft_strchr(opt, '-') != NULL)
	{
		ft_add_space(&tmp2, opt);
		tmp2 = ft_strjoin("%", tmp2 + 1);
		tmp2 = ft_strjoin(ft_strsub(*new_str, 0 , i),ft_strdup(tmp2));
	}
	else
	{
		tmp2 = ft_strdup("%");
		tmp2 = ft_strjoin(ft_strsub(*new_str, 0 , i),ft_strdup(tmp2));
	}
	*new_str = ft_strdup(tmp2);
	return (ft_strlen(tmp2));
}

int        ft_printf_id(char **new_str, int i, va_list vl, char *opt)
{
	char    *tmp;
	void    *tmp2;

	tmp = *new_str;
	if (ft_strchr(opt, 'h') && ft_strchr(opt + 1, 'h'))
		tmp2 = ft_itoa((char)va_arg(vl, int));
	else if (ft_strchr(opt, 'l') && ft_strchr(opt + 1, 'l'))
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
	ft_add_space((char **)&tmp2, opt);
	*new_str = ft_strjoin(ft_strsub(*new_str, 0, i), tmp2);
	ft_strdel(&tmp);
	return (ft_strlen(tmp2));
}

int        ft_printf_ld(char **new_str, int i, va_list vl, char *opt)
{
	char    *tmp;
	void    *tmp2;

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
	return (ft_strlen(tmp2));
}

char    *ft_find_conv(char *new_str, int *i, int j, va_list vl)
{
	char    *opt;
	char    *tmp;

	tmp = ft_strnew(0);
	opt = ft_get_opt(new_str + *i + 1);
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
	ft_strdel(&tmp);
	return (new_str);
}

int        ft_printf(const char *format, ...)
{
	va_list    vl;
	int        i;
	int        j;
	char    *new_str;
	char    *tmp;

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
				tmp = ft_strsub(new_str, i + j + 2, ft_strlen(new_str));
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

