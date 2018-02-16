/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 23:41:34 by kgricour          #+#    #+#             */
/*   Updated: 2018/02/16 16:26:19 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_edit_nbr_sd(char **str, char *opt, int i, int mode)
{
	int		nbr;

	nbr = 0;
	nbr = ft_atoi(opt + i + 1);
	*str = ft_strsub(*str, 0, nbr, 0);
	if (mode == 1)
		nbr = nbr - ft_strlen(*str);
	else if (mode == 2)
		nbr = nbr - ft_strlen(*str) + 1;
	else if (mode == 3)
		nbr = nbr - ft_strlen(*str) - 1;
	return (nbr);
}

static int	ft_edit_nbr_x(char **str, char *opt)
{
	int		i;
	int		nbr;
	char	*adr;

	i = 0;
	nbr = 0;
	if (opt[0] == '0' || opt[1] == '0')
		i++;
	if ((adr = ft_strchr(opt, '.')))
		nbr = ft_atoi(adr + 1) - ft_strlen(*str);
	else if (ft_strchrstr("0", &opt[i], '&'))
		nbr = ft_atoi(opt + i + 1) - ft_strlen(*str);
	if (ft_strchr(opt, '#') && ft_strchrstr("xX", opt, '|'))
		nbr -= 2;
	if (nbr < 0)
		nbr = 0;
	return (nbr);
}

void		ft_precision(char **str, char *opt)
{
	int		nbr;
	char	*zero;
	int		i;

	i = 0;
	nbr = ft_edit_nbr_x(str, opt);
	while (opt[i] != '.' && opt[i] != '+' && opt[i] != '\0')
		i++;
	if (!ft_strchr(*str, '-'))
	{
		if (ft_strchrstr("sS", opt, '|'))
			nbr = ft_edit_nbr_sd(str, opt, i, 1);
		else if (opt[0] == '0' && ft_strchrstr("d+", opt, '&'))
			nbr = ft_edit_nbr_sd(str, opt, i, 3);
	}
	if (ft_strchr(*str, '-'))
		if (ft_strchrstr("dD", opt, '|') && ft_strchr(opt, '.'))
			nbr = ft_edit_nbr_sd(str, opt, i, 2);
	zero = ft_strnew(nbr);
	ft_memset(zero, '0', nbr);
	(**str == '\0') ? zero[0] = '\0' : zero[0];
	*str = ft_freejoin(zero, *str, 2);
	if (opt[0] == ' ' && !ft_strchr(opt, '+') && *str[0] != '-')
		*str = ft_freejoin(" ", *str, 1);
}
