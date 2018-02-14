/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 15:50:59 by kgricour          #+#    #+#             */
/*   Updated: 2018/02/05 21:06:09 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int        ft_printf_pct(char **new_str, char *opt, int i)
{
	char    *tmp2;
	int	j;
	int	len;
	int noopt;

	j = 0;
	len = 0;
	noopt = 1;
	tmp2 = ft_strnew(0);
	while (new_str[0][i + j] != '%')
	{
		if (new_str[0][i+j] != ' ')
			noopt = 0;
		j++;
	}
	if (ft_strchr(opt, '-') != NULL && new_str[0][i + j] == '%')
	{
		ft_add_space(&tmp2, opt);
		tmp2 = ft_strjoin("%", tmp2 + 1);
		len = ft_strlen(tmp2);
		tmp2 = ft_strjoin(ft_strsub(*new_str, 0 , i),ft_strdup(tmp2));
	}
	else if (ft_strchr(opt, '-') == NULL && new_str[0][i + j] == '%' && noopt == 0)
	{
		ft_add_space(&tmp2, opt);
		tmp2 = ft_strjoin(tmp2, "%");
		len = ft_strlen(tmp2);
		tmp2 = ft_strjoin(ft_strsub(*new_str, 0 , i),ft_strdup(tmp2 + 1));
	}
	else
	{
		tmp2 = ft_strdup("%");
		ft_add_space(&tmp2, opt);
		len = ft_strlen(tmp2);
		tmp2 = ft_strjoin(ft_strsub(*new_str, 0 , i), tmp2);
	}
	*new_str = ft_strdup(tmp2);
	return (len);
}
