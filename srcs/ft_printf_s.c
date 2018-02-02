/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 11:58:26 by kgricour          #+#    #+#             */
/*   Updated: 2018/02/02 16:49:20 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_s(char **new_str, int i, va_list vl, char *opt)
{
	char *tmp;
	char *str;

	if (!(str = va_arg(vl, char *)))
		str = "(null)";
	tmp = *new_str;
	ft_add_space((char **)&str, opt);
	*new_str = ft_strjoin(ft_strsub(*new_str, 0, i), str);
	ft_strdel(&tmp);
	return (ft_strlen(str));
}
