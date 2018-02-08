/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:33:46 by kgricour          #+#    #+#             */
/*   Updated: 2018/02/08 12:38:38 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_cut_hex(char *res)
{
	int i;

	i = 0;
	while (res[i] == '0' && res[i])
		i++;
	if (i == 17)
		i = 16;
	return (res + i);
}

char	*ft_putadr(uintmax_t p, char *opt)
{
	char				*base;
	char				*res;
	char				*tmp;
	uintmax_t	adr;
	int					i;

	res = ft_strnew(16);
	if (ft_strchr(opt, 'X'))
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	i = 16;
	adr = p;
	while (i != -1)
	{
		res[i--] = base[adr % (uintmax_t)16];
		adr /= (uintmax_t)16;
	}
	tmp = res;
	res = ft_strdup(ft_cut_hex(res));
	if (ft_strchr(opt, '#') != NULL && ft_strchr(opt, 'x'))
		res = ft_strjoin("0x", res);	
	else if (ft_strchr(opt, '#') != NULL && ft_strchr(opt, 'X'))
		res = ft_strjoin("0X", res);	
	ft_strdel(&tmp);
	return (res);
}
