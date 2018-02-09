/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:33:46 by kgricour          #+#    #+#             */
/*   Updated: 2018/02/08 18:24:52 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct	s_hex
{
	char *base;
	char *res;
	char *tmp;
}				t_hex;

static char		*ft_cut_hex(char *res, int nbr)
{
	int i;

	i = 0;
	while (res[i] == '0' && res[i])
		i++;
	if (i == nbr + 1)
		i = i - 1;
	return (res + i);
}

char			*ft_putadr(unsigned long long p, char *opt, int nbr)
{
	t_hex				*hex;
	unsigned long long	adr;
	int					i;

	hex = (t_hex *)malloc(sizeof(t_hex));
	hex->res = ft_strnew(nbr);
	if (ft_strchr(opt, 'X'))
		hex->base = "0123456789ABCDEF";
	else
		hex->base = "0123456789abcdef";
	i = nbr;
	adr = p;
	while (i != -1)
	{
		hex->res[i--] = hex->base[adr % (unsigned long long)16];
		adr /= (unsigned long long)16;
	}
	hex->tmp = hex->res;
	hex->res = ft_strdup(ft_cut_hex(hex->res, nbr));	
	ft_add_space((char **)&hex->res, opt);
	if (ft_strchr(opt, '#') && ft_strchr(opt, 'x') && ft_strcmp(hex->res, "0"))
		hex->res = ft_strjoin("0x", hex->res);	
	else if (ft_strchr(opt, '#') && ft_strchr(opt, 'X') && ft_strcmp(hex->res, "0"))
		hex->res = ft_strjoin("0X", hex->res);
	else if (ft_strchr(opt, 'p'))
		hex->res = ft_strjoin("0x", hex->res);	
	ft_strdel(&hex->tmp);
	return (hex->res);
}
