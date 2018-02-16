/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tool.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 20:35:13 by kgricour          #+#    #+#             */
/*   Updated: 2018/02/16 17:27:27 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_edit_nbr_carac(char *opt, int *nbr)
{
	int i;

	i = 0;
	if (ft_strchr(opt, 'p') && *nbr > 2)
		*nbr -= 2;
	else if (ft_check_valide_conv(opt, &i) == 0)
		*nbr += 1;
	else if (ft_strchrstr("x#0", opt, '&') && !ft_strchr(opt, '-') && *nbr > 2)
		nbr -= 2;
	else if (ft_strchrstr("X#0", opt, '&') && !ft_strchr(opt, '-') && *nbr > 2)
		*nbr -= 2;
}

static	char	*ft_count_caract(char *opt, int nbr_letters_add)
{
	int		i;
	char	*space;
	int		nbr;
	char	c;

	i = 0;
	c = ' ';
	nbr = 0;
	while (opt[i] && opt[i] != '.')
	{
		if (!ft_strchrstr("-.", opt, '|') && opt[i] == '0')
			c = '0';
		if (ft_isdigit(opt[i]) && opt[i] != '0')
		{
			if ((nbr = ft_atoi(&opt[i]) - nbr_letters_add) < 1)
				return (NULL);
			ft_edit_nbr_carac(opt, &nbr);
			space = ft_strnew(nbr);
			ft_memset(space, c, nbr);
			return (space);
		}
		i++;
	}
	return (NULL);
}

void			ft_add_space(char **tmp2, char *opt)
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

void			ft_add_plus(char *opt, char **tmp2)
{
	if (!ft_strchr(opt, '-'))
		ft_precision((char **)tmp2, opt);
	if (ft_strchrstr("0+", opt, '&') && !ft_strchr(*tmp2, '-'))
	{
		ft_precision((char **)tmp2, opt);
		*tmp2 = ft_freejoin("+", *tmp2, 1);
	}
	else if (*tmp2[0] != '-' && ft_strchr(opt, '+'))
	{
		ft_precision((char **)tmp2, opt);
		*tmp2 = ft_freejoin("+", *tmp2, 1);
	}
	else if (ft_strchrstr("-.", opt, '&'))
		ft_precision((char **)tmp2, opt);
}
