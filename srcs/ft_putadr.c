/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:33:46 by kgricour          #+#    #+#             */
/*   Updated: 2018/01/14 22:10:35 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_cut_hex(char *res)
{
	int i;

	i = 0;
	while (res[i] == '0' && res[i])
		i++;
	return (res + i);
}

char	*ft_putadr(void const *p)
{
	char	*base;
	char	*res;
	char	*tmp;
	size_t	adr;
	int		i;

	res = ft_strnew(9);
	base = "0123456789abcdef";
	i = 11;
	adr = (size_t)p;
	while (i != -1)
	{
		res[i--] = base[adr % 16];
		adr /= 16;
	}
	tmp = res;
	if (ft_strcmp(res, "000000000000") == 0)
		res = ft_strjoin("0x", "0");
	else
		res = ft_strjoin("0x", ft_cut_hex(res));
	ft_strdel(&tmp);
	return (res);
}
