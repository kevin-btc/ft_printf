/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:55:51 by kgricour          #+#    #+#             */
/*   Updated: 2018/02/15 18:24:52 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_strchrstr(const char *search, const char *target, char cmp)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	nbr_char;

	if (!search || !target)
		return (0);
	i = 0;
	nbr_char = 0;
	while (search[i])
	{
		j = 0;
		while (target[j])
			if (search[i] == target[j++])
			{
				nbr_char++;
				break ;
			}
		i++;
	}
	if (nbr_char == i && cmp == '&')
		return (1);
	else if (nbr_char > 0 && cmp == '|')
		return (1);
	return (0);
}
