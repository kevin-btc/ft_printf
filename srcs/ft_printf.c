/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:36:40 by kgricour          #+#    #+#             */
/*   Updated: 2018/02/17 00:23:54 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	vl;
	int		i;
	int		j;
	char	*new_str;
	char	*tmp;

	tmp = ft_strnew(0);
	new_str = ft_strdup(format);
	i = 0;
	va_start(vl, format);
	while (new_str[i])
	{
		j = 0;
		if (new_str[i] == '%')
		{		
			if (ft_check_valide_conv(&new_str[i + j + 1], &j) == 1)
			{
				tmp = ft_strsub(new_str, i + j + 2, ft_strlen(new_str), 0);
				new_str = ft_freejoin(ft_find_conv(new_str, &i, vl), tmp, 1);
				i--;
			}
			else if (ft_check_valide_conv(&new_str[i + j + 1], &j) == 0)
			{
				tmp = ft_strsub(new_str, i + j + 1, ft_strlen(new_str), 1);
				ft_add_space(&tmp, ft_strsub(new_str, i + 1, i + j, 1));
				new_str = ft_freejoin(ft_strsub(new_str, 0, i, 1), tmp, 1);
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
	i = ft_strlen(new_str);
	ft_strdel(&new_str);
	return (i);
}
