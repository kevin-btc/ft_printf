/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 23:41:34 by kgricour          #+#    #+#             */
/*   Updated: 2018/03/01 15:58:26 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_edit_nbr_sd(char **str, char *opt, int i, int mode)
{
	int		nbr;
	int		dot;
	int		len_str;
	
	nbr = ft_atoi(opt + i + 1);
	while (opt[i] && opt[i] != '.')
		i++;
	dot = ft_atoi(opt + i + 1);
	if (ft_strlen(*str) > (size_t)nbr && ft_strchrstr("dD", opt, '|'))
		return (0);
	if (ft_strlen(*str) > (size_t)dot && ft_strchr(*str, '-'))
		return (0);
	*str = ft_strsub(*str, 0, nbr, 0);
	len_str = ft_strlen(*str);
	if (mode == 1)
		nbr = nbr - len_str;
	else if (mode == 2 && dot >= len_str)
		nbr = nbr - len_str + 1;
	else if (mode == 3)
		nbr = nbr - len_str - 1;
	if (ft_strchrstr("sS", opt, '|'))
		nbr = 0;
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
	if (ft_strchr(opt, '#') && ft_strchrstr("xX", opt, '|') && !ft_strchr(opt, '.'))
		nbr -= 2;
	if (nbr < 0)
		nbr = 0;
	return (nbr);
}

int		ft_precision(char **str, char *opt)
{
	int	nbr;
	char	*zero;
	int	i;

	i = 0;
	zero = NULL;
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
	if (ft_strchrstr("#.o", opt, '&') && nbr != 0)
		nbr--;
	if (nbr >= 0)
	{
		zero = ft_strnew(nbr);
		ft_memset(zero, '0', nbr);
		*str = ft_freejoin(zero, *str, 2);
		return (1);
	}
	return (0);
}
