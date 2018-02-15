/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:22:02 by kgricour          #+#    #+#             */
/*   Updated: 2018/02/15 18:36:15 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_find_base(char *opt)
{
	int b;

	b = 0;
	if (ft_strchr(opt, 'o'))
		b = 8;
	else if (ft_strchr(opt, 'x') || ft_strchr(opt, 'X') ||ft_strchr(opt, 'p'))
		b = 16;
	else if (ft_strchr(opt, 'b'))
		b = 2;
	else if (ft_strchr(opt, 'u') || ft_strchr(opt, 'U'))
		b = 10;
	return (b);
}

int	ft_printf_xobup(char **new_str, int i, va_list vl, char *opt)
{	
	char    *tmp;
	char    *tmp2;
	char	*adr;
	int		b;

	tmp = *new_str;
	tmp2 = NULL;
	b = ft_find_base(opt);
	if (ft_strchr(opt, 'U') || ft_strchr(opt, 'l'))
		tmp2 = ft_putadr(va_arg(vl, unsigned long int), opt, b);
	else if (ft_strchr(opt, 'p'))
		tmp2 = ft_putadr((unsigned long long)va_arg(vl, char *), opt, b);
	else if ((adr = ft_strchr(opt, 'h')) && ft_strchr(adr + 1, 'h'))
		tmp2 = ft_putadr((unsigned char)va_arg(vl, unsigned int), opt, b);
	else if ((adr = ft_strchr(opt, 'l')) && ft_strchr(adr + 1, 'l'))
		tmp2 = ft_putadr(va_arg(vl, unsigned long long int), opt, b);
	else if (ft_strchr(opt, 'h'))
		tmp2 = ft_putadr((unsigned short int)va_arg(vl,unsigned int), opt, b);
	else if (ft_strchr(opt, 'j'))
		tmp2 = ft_putadr((unsigned long long)va_arg(vl, intmax_t), opt, b);
	else if (ft_strchr(opt, 'z'))
		tmp2 = ft_putadr(va_arg(vl, size_t), opt, b);
	else
		tmp2 = ft_putadr(va_arg(vl, unsigned int), opt, b);
	if ((adr = ft_strchr(opt, '.')) && (*(adr + 1) == '0' || ft_isalpha(*(adr + 1))) && *tmp2 == '0' && ft_strchr(opt, 'x'))
		tmp2 = ft_strdup("");
	*new_str = ft_strjoin(ft_strsub(*new_str, 0, i), tmp2);
	ft_strdel(&tmp);
	return (ft_strlen(tmp2));
}
