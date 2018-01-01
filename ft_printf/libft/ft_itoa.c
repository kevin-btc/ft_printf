/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:45:20 by kgricour          #+#    #+#             */
/*   Updated: 2017/11/17 17:46:34 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_formitoc(char *dest, int *n, int *len)
{
	dest[*len] = (*n % 10) + 48;
	*n /= 10;
}

static int	ft_nbrlenj(int *n, int *neg, int *j)
{
	int i;
	int tmp;

	i = 0;
	*j = 0;
	tmp = *n;
	if (*n < 0)
	{
		if (*n == -2147483648)
			*n = *n - 1;
		else
			*n = *n * -1;
		*neg = *neg * -1;
	}
	while (tmp != 0)
	{
		tmp /= 10;
		i++;
	}
	if (*neg == -1)
	{
		*j = *j + 1;
		return (i + 1);
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int		i;
	int		j;
	int		neg;
	char	*str;
	int		nbr;

	neg = 1;
	j = 0;
	nbr = n;
	i = ft_nbrlenj(&nbr, &neg, &j);
	if (!(str = ft_memalloc(i)))
		return (NULL);
	if (neg == -1)
		str[0] = '-';
	if (nbr == 0)
	{
		str[0] = '0';
		return (str);
	}
	str[i] = '\0';
	while (nbr && i-- > j)
		ft_formitoc(str, &nbr, &i);
	if (n == -2147483648)
		str[10] = '8';
	return (str);
}
