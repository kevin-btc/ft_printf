/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:45:20 by kgricour          #+#    #+#             */
/*   Updated: 2018/01/14 17:09:42 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_formitoc(char *dest, long long *n, long long *len)
{
	dest[*len] = (*n % 10) + 48;
	*n /= 10;
}

static long long	ft_nbrlenj(long long *n, long long *neg, long long *j)
{
	long long	i;
	long long	tmp;

	i = 0;
	*j = 0;
	tmp = *n;
	if (*n < (long long)0)
	{
		*n = *n * -1;
		*neg = *neg * -1;
	}
	while (tmp != 0)
	{
		tmp /= 10;
		i++;
	}
	if (*neg == (long long)-1)
	{
		*j = *j + 1;
		return (i + 1);
	}
	return (i);
}

char		*ft_itoa(long long n)
{
	long long	i;
	long long	j;
	long long	neg;
	long long	nbr;
	char			*str;

	neg = 1;
	j = 0;
	nbr = n;
	i = ft_nbrlenj(&nbr, &neg, &j);
	if (!(str = ft_memalloc(i)))
		return (NULL);
	if (neg == (long long)-1)
		str[0] = '-';
	if (nbr == 0)
	{
		str[0] = '0';
		return (str);
	}
	str[i] = '\0';
	while (nbr && i-- > j)
		ft_formitoc(str, &nbr, &i);
	return (str);
}
