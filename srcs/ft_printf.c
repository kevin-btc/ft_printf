/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:36:40 by kgricour          #+#    #+#             */
/*   Updated: 2018/02/19 17:32:56 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_skip_space(char *str, int i, int *j)
{
	if (str[i + *j] == ' ')
	{
		while (str[i + *j] == ' ' && str[i + *j])
			*j = *j + 1;
		*j = *j - 1;
	}
}

static void	ft_add_word_str(char **str, int *i, int j, va_list vl)
{
	char	*tmp;

	tmp = ft_strsub(*str, *i + j + 2, ft_strlen(*str), 0);
	*str = ft_freejoin(ft_find_conv(*str, i, vl), tmp, 2);
	*i = *i - 1;
}

int		ft_printf(const char *format, ...)
{
	va_list	vl;
	int		i;
	int		j;
	char	*new_str;
	char	*tmp;

	new_str = ft_strdup(format);
	i = 0;
	va_start(vl, format);
	while (new_str[i])
	{
		j = 0;
		if (new_str[i] == '%')
		{
			if (ft_check_valide_conv(&new_str[i + j + 1], &j) == 1)
				ft_add_word_str(&new_str, &i, j, vl);
			else
			{
				ft_skip_space(new_str, i, &j);
				tmp = ft_strsub(new_str, i  + j + 1, ft_strlen(new_str ), 0);
				while (ft_strchrstr("+-#", &new_str[j], '|'))
					j++;
				ft_add_space(&new_str, ft_strsub(new_str, i , i + j, 0));
				new_str = ft_freejoin(ft_strsub(new_str, 0, i-- , 0), tmp, 0);
			}
		}
		i++;
	}
	va_end(vl);
	i = ft_print(new_str);
	ft_strdel(&new_str);
	return (i);
}
