/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tool.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 20:35:13 by kgricour          #+#    #+#             */
/*   Updated: 2018/02/15 18:46:12 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *ft_count_caract(char *opt, int nbr_letters_add)
{
	int		i;
	char	*space;
	int		nbr;
	char    c;
	char	*bef_adr;

	i = 0;
	c = ' ';
	nbr = 0;
	while (opt[i] == '#' && opt[i] == '-' && opt[i] == '+' )
	{
		if (opt[i + 1] == '\0')
		{
			i = 0;
			break;
		}
		i++;
	}
	while (opt[i] && opt[i] != '.')
	{
		if (!ft_strchr(opt, '-') && opt[i] == '0' && !ft_strchr(opt , '.'))
			c = '0';	
		if (ft_isdigit(opt[i]) && opt[i] != '0')
		{
			if ((nbr = ft_atoi(&opt[i]) - nbr_letters_add) < 1)
				return (NULL);
			if (ft_strchr(opt, 'p') && nbr > 2)
				nbr -= 2;
			else if (ft_check_valide_conv(opt, &i) == 0)
				nbr++;
			else if (ft_strchr(opt, 'x') && nbr > 2 && ft_strchr(opt, '#') && (bef_adr = ft_strchr(opt, '0')) && !ft_isdigit(*bef_adr - 1) && !ft_strchr(opt ,'-'))
				nbr -= 2;
			else if (ft_strchr(opt, 'X') && nbr > 2 && ft_strchr(opt, '#') && (bef_adr = ft_strchr(opt, '0')) && !ft_isdigit(*bef_adr - 1) && !ft_strchr(opt ,'-'))
				nbr -= 2;
			space = ft_strnew(nbr);
			ft_memset(space, c, nbr);
			return (space);
		}
		i++;
	}
	return (NULL);
}

void    ft_add_space(char **tmp2, char *opt)
{
	char *str_added;
	str_added = ft_count_caract(opt, ft_strlen(*tmp2));
	if (str_added != NULL)
	{
		if (ft_strchr(opt, '-'))
			*tmp2 = ft_freejoin(*tmp2, str_added, 1);
		else
			*tmp2 = ft_freejoin(str_added, *tmp2, 0);
	}
}

void	ft_precision(char **str, char *opt)
{
	char	*adr;
	int		nbr;
	char	*zero;
	int		i;

	nbr = 0;
	i = 0;
	if (opt[0] == '0' || opt[1] == '0')
		i++;
	if ((adr = ft_strchr(opt, '.')))
		nbr = ft_atoi(adr + 1) - ft_strlen(*str);
	else if (opt[i] == '0' && !ft_isdigit(opt[i - 1]))
		nbr = ft_atoi(opt + i + 1) - ft_strlen(*str);
	if (ft_strchr(opt, '#') && (ft_strchr(opt, 'x') || ft_strchr(opt, 'X')))
		nbr -= 2;
	if (nbr < 0)
		nbr = 0;
	i = 0;
	while (opt[i] != '.' && opt[i] != '+' && opt[i] != '\0')
		i++;
	if (ft_strchr(opt , 's') || ft_strchr(opt, 'S'))
	{
		nbr = ft_atoi(opt + i + 1);
		*str = ft_strsub(*str, 0, nbr);
		nbr = nbr - ft_strlen(*str);
	}
	if (ft_strchrstr("dD", opt, '|') && ft_strchr(opt, '.') && ft_strchr(*str, '-'))
	{
		nbr = ft_atoi(opt + i + 1);
		*str = ft_strsub(*str, 0, nbr);
		nbr = nbr - ft_strlen(*str) + 1;
	}
	if (opt[0] == '0' && ft_strchrstr("d+", opt, '&') && !ft_strchr(*str, '-'))
	{
		nbr = ft_atoi(opt + i + 1);
		*str = ft_strsub(*str, 0, nbr);
		nbr = nbr - ft_strlen(*str) - 1;
	}
	zero = ft_strnew(nbr);
	ft_memset(zero, '0', nbr);
	if (**str == '\0')
		zero[0] = '\0';
	*str = ft_freejoin(zero, *str, 2);
	if (opt[0] == ' ' && !ft_strchr(opt, '+') && *str[0] != '-')
		*str = ft_freejoin(" " , *str, 1);
}

void	ft_add_plus(char *opt, char **tmp2)
{
	if (!ft_strchr(opt, '-'))
		ft_precision((char **)tmp2, opt);
	if (opt[0] == '0' && ft_strchr(opt, '+') && !ft_strchr(*tmp2, '-'))
	{
		ft_precision((char **)tmp2, opt);
		*tmp2 = ft_freejoin("+", *tmp2, 1);
	}
	else if (*tmp2[0] != '-' && ft_strchr(opt, '+'))
	{
		ft_precision((char **)tmp2, opt);
		*tmp2 = ft_freejoin("+", *tmp2, 1);
	}
	else if (ft_strchr(opt, '-') && ft_strchr(opt, '.'))
	{
		ft_precision((char **)tmp2, opt);
	}
}
