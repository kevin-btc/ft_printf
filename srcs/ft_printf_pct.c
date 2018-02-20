/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 15:50:59 by kgricour          #+#    #+#             */
/*   Updated: 2018/02/19 20:32:40 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_find_next_pct(char *str, int i, int *j)
{
	int	noopt;

	noopt = 1;
	while (str[i + *j] != '%')
	{
		if (str[i + *j] != ' ')
			noopt = 0;
		*j = *j + 1;
	}
	return (noopt);
}

static char	*ft_add_pct_left(char *opt, char *str, int *len, int i)
{
	char *tmp2;
	char *del;

	tmp2 = ft_strnew(0);
	ft_add_space(&tmp2, opt);
	tmp2 = ft_strjoin("%", tmp2 + 1);
	*len = ft_strlen(tmp2);
	del = ft_strsub(str,0 ,i , 0);
	tmp2 = ft_freejoin(del, tmp2, 2);
	return (tmp2);
}

static char	*ft_add_pct(char *opt, char *str, int *len, int i)
{
	char *tmp2;

	tmp2 = ft_strdup("%");
	ft_add_space(&tmp2, opt);
	*len = ft_strlen(tmp2);
	tmp2 = ft_freejoin(ft_strsub(str,0 ,i , 0), tmp2, 2);
	return (tmp2);
}

int        	ft_printf_pct(char **new_str, char *opt, int i)
{
	char    *tmp2;
	int	j;
	int	len;
	int noopt;

	j = 0;
	len = 0;
	noopt = ft_find_next_pct(*new_str, i, &j);
	if (ft_strchr(opt, '-') != NULL && new_str[0][i + j] == '%')
		tmp2 = ft_add_pct_left(opt, *new_str, &len, i);
	else
		tmp2 = ft_add_pct(opt, *new_str, &len, i);
	*new_str = ft_strdup(tmp2);
	return (len);
}
