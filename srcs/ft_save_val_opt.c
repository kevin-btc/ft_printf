/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_val_opt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 19:06:00 by kgricour          #+#    #+#             */
/*   Updated: 2018/03/01 18:50:57 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_uncheck_if(int *check, int nbr_dot, int nbr_space, char *str)
{
	if (nbr_dot > nbr_space)
		*check = 0;
	else if (nbr_space <= (int)ft_strlen(str))
		*check = 0;
	else if (nbr_dot + 1 == nbr_space && ft_strchr(str, '-'))
		*check = 0;
	else if ((int)ft_strlen(str) > nbr_space)
		*check = 0;
	else if ((int)ft_strlen(str) == nbr_space && ft_strchr(str, '+'))
		*check = 0;
}

int			ft_check_point(char *opt, char *str)
{
	int i;
	int check;
	int nbr_space;

	i = 0;
	check = 0;
	nbr_space = 0;
	while (opt[i])
	{
		if (opt[i] == '.' || (ft_strchrstr("#0x", opt, '&') &&
			!ft_strchr(opt, '-')))
			break ;
		if (ft_isdigit(opt[i]) && opt[i] != '0')
		{
			check = 1;
			nbr_space = ft_atoi(opt + i);
			break ;
		}
		i++;
	}
	while (opt[i] && opt[i] != '.')
		i++;
	ft_uncheck_if(&check, ft_atoi(opt + i + 1), nbr_space, str);
	return (check);
}
