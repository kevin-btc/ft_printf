/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_id.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 15:33:36 by kgricour          #+#    #+#             */
/*   Updated: 2018/02/26 15:25:28 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_swap_sign(char *tmp2)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	c = '+';

	while (tmp2[j] != '0' && tmp2[j])
		j++;
	(ft_strchr(tmp2, '-')) ? c = '-' : c;
	while (tmp2[i])
	{
		if (tmp2[i] == c && i != 0)
		{
			tmp2[j] = c;
			tmp2[i] = '0';
			break ;
		}
		i++;
	}
}

static char	*ft_cast_param_ild(va_list vl, char *opt)
{
	char	*adr;
	char	*tmp2;

	tmp2 = NULL;
	if (ft_strchrstr("Dl", opt, '|'))
		tmp2 = ft_itoa(va_arg(vl, long int));
	else if ((adr = ft_strchr(opt, 'h')) && ft_strchr(adr + 1, 'h'))
		tmp2 = ft_itoa((char)va_arg(vl, int));
	else if ((adr = ft_strchr(opt, 'l')) && ft_strchr(adr + 1, 'l'))
		tmp2 = ft_itoa(va_arg(vl, long long int));
	else if (ft_strchr(opt, 'z'))
		tmp2 = ft_itoa(va_arg(vl, size_t));
	else if (ft_strchr(opt, 'j'))
		tmp2 = ft_itoa(va_arg(vl, intmax_t));
	else if (ft_strchr(opt, 'h'))
		tmp2 = ft_itoa((short int)va_arg(vl, int));
	else
		tmp2 = ft_itoa(va_arg(vl, int));
	return (tmp2);
}

int			ft_printf_id(char **new_str, int i, va_list vl, char *opt)
{
	char	*tmp;
	char	*tmp2;
	char	*adr;
	int		len;

	tmp = *new_str;
	tmp2 = ft_cast_param_ild(vl, opt);
	if ((adr = ft_strchr(opt, '.')) && (*(adr + 1) == '0' ||
		ft_isalpha(*(adr + 1))) && tmp2[0] == '0')
		tmp2[0] = '\0';
	if (ft_strchr(opt, '+'))
		ft_add_plus(opt, &tmp2);
	if (ft_strchr(opt, '.'))
		ft_precision(&tmp2, opt);
	ft_add_space((char **)&tmp2, opt);
	if (ft_strchr(tmp2, '0') && ft_strchr(tmp2, '-'))
	{
		if (!ft_strchrstr("jllD", opt, '|'))
			ft_swap_sign(tmp2);
	}
	if (ft_strchr(tmp2, '+') && tmp2[0] == '0')
			ft_swap_sign(tmp2);

	if (ft_strchr(opt, ' ') && !ft_strchr(opt, '+') && tmp2[0] != '-')
		if (!ft_strchr(opt, '.'))
			tmp2 = ft_freejoin(" ", tmp2, 3);

	len = ft_strlen(tmp2);
	*new_str = ft_freejoin(ft_strsub(*new_str, 0, i, 0), tmp2, 2);
	ft_strdel(&tmp);
	return (len);
}
