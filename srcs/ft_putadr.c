/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:33:46 by kgricour          #+#    #+#             */
/*   Updated: 2018/02/28 13:39:09 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_type_x(char **base, char *opt)
{
	if (ft_strchr(opt, 'X'))
		*base = "0123456789ABCDEF";
	else
		*base = "0123456789abcdef";	
}

void	ft_apply_opt(char *opt, t_hex *hex)
{
	char	*tmp;
	
	tmp = "";
	if (ft_strchr(opt, '.') || (ft_strchrstr("#x", opt, '|') && !ft_strchr(opt, '-')))
		ft_precision(&hex->res, opt);
	if (hex->res[0] != '\0' || ft_strchr(opt, 'p'))
	{
//	ft_putendl(hex->res); // --------------------------------
		if (ft_strchr(opt, '#') && ft_strchr(opt, 'x') /*&& !ft_strchr(opt, '.')*/)
			tmp = "0x";
		else if (ft_strchr(opt, '#') && ft_strchr(opt, 'X') /*&& !ft_strchr(opt, '.')*/)
			tmp = "0X";
		else if (ft_strchr(opt, 'p'))
			tmp = "0x";
		else if (ft_strchrstr("oO", opt, '|') && ft_strchr(opt, '#'))
			tmp = "0";
	}
	if (ft_strchr(opt, 'p') && hex->res[0] == '\0')
			tmp = "0x0";
		hex->res = ft_freejoin(tmp, hex->res, 1);
	if (hex->res[0] == '\0' && !ft_strchr(opt, '.'))
		hex->res = "0";
	if (hex->res[0] == '\0' && ft_strchr(opt, '#'))
		hex->res = "0";
}

int		ft_count_nbr(unsigned long long value, int base)
{
	int nbr_nbr;

	nbr_nbr = 0;
	while (value != 0)
	{
		value = value / base;
		nbr_nbr++;
	}
	return (nbr_nbr);
}

char			*ft_putadr(unsigned long long adr, char *opt, int base)
{
	t_hex				*hex;
	char				*ret;
	int					i;

	i = ft_count_nbr(adr, base);
	if (!(hex = (t_hex *)malloc(sizeof(t_hex))))
		return (NULL);
	hex->res = (char *)malloc(sizeof(char) * (i + 1));
	hex->res[i] = '\0';
	ft_check_type_x(&hex->base, opt);
	while (adr != 0)
	{
		i--;
		hex->res[i] = hex->base[adr % base];
		adr /= (unsigned long long)base;
	}
	ft_apply_opt(opt, hex);
	ft_add_space(&hex->res, opt);

	ret = ft_strdup(hex->res);
	if (ft_strcmp(hex->res, "0") != 0)
		ft_strdel(&hex->res);
	free(hex);
	return (ret);
}
