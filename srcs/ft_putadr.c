/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:33:46 by kgricour          #+#    #+#             */
/*   Updated: 2018/02/14 19:22:42 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct	s_hex
{
	char *base;
	char *res;
	char *tmp;
}				t_hex;

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
	int					i;
	int					done;
	char				*tmp;

	tmp = ft_strnew(2);
	i = ft_count_nbr(adr, base);
	if (!(hex = (t_hex *)malloc(sizeof(t_hex))))
		return (NULL);
	hex->res = (char *)malloc(sizeof(char) * (i + 1));
	hex->res[i] = '\0';
	if (ft_strchr(opt, 'X'))
		hex->base = "0123456789ABCDEF";
	else
		hex->base = "0123456789abcdef";
	done = 0;
	while (adr != 0)
	{
		i--;
		hex->res[i] = hex->base[adr % base];
		adr /= (unsigned long long)base;
	}
	if (ft_strchr(opt, '.') || (ft_strchr(opt, '#') && ft_strchr(opt,'x') && !ft_strchr(opt, '-')))
		ft_precision((char **)&hex->res, opt);
	if (hex->res[0] != '\0')
	{
		if (ft_strchr(opt, '#') && ft_strchr(opt, 'x') && !ft_strchr(opt, '.'))
			tmp = "0x";
		else if (ft_strchr(opt, '#') && ft_strchr(opt, 'X') && !ft_strchr(opt, '.'))
			tmp = "0X";
		else if (ft_strchr(opt, 'p'))
			tmp = "0x";
		else if (ft_strchr(opt, 'o') && ft_strchr(opt, '#'))
			tmp = "0";
	}
	hex->res = ft_strjoin(tmp, hex->res);
	if (hex->res[0] == '\0' && !ft_strchr(opt, '.'))
		hex->res = "0";
	if (opt[i] ==  '0' && !ft_isdigit(opt[i - 1]))
	{
		done = 1;
		ft_add_space((char **)&hex->res, opt);
	}
	if (done == 0)
		ft_add_space((char **)&hex->res, opt);
	return (hex->res);
}
