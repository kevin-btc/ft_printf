/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 11:19:34 by kgricour          #+#    #+#             */
/*   Updated: 2018/02/02 16:53:59 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_get_opt(char *s)
{
	char    opt[100];
 	int		i;
	int		k;

	i = 0;
	k = 0;
	while (s[i] != 's' && s[i] != 'c' &&/* s[i] != 'S' &&*/ s[i] != 'p' && s[i] != 'd' &&
	/*s[i] != 'D' &&*/ s[i] != 'i' &&/* s[i] != 'o' && s[i] != 'u' &&s[i] != 'x' &&
	s[i] != 'X' && s[i] != 'C' &&*/ s[i] != '%' && s[i] != '\0')
	{
		opt[k] = s[i];
		i++;
		k++;
	}
	opt[k] = '\0';
	return (ft_strdup(opt));
}

int        ft_check_valide_conv(char *s, int *j)
{
	while (s[*j])
	{
		if (s[*j] == 's' || s[*j] == 'c' || /*s[*j] == 'S' ||*/ s[*j] == 'p' || s[*j] == 'd' ||
		/*s[*j] == 'D' ||*/ s[*j] == 'i' ||/* s[*j] == 'o' || s[*j] == 'u' ||
		s[*j] == 'x' || s[*j] == 'X' || s[*j] == 'C' ||*/s[*j] == '%')
		{ 
			return (1);
		}
		else if (s[*j] == '#' || s[*j] == '-' || s[*j] == '+' || ft_isdigit(s[*j]) ||
				s[*j] == 'j' || s[*j] == 'z' || s[*j] == ' ' || s[*j] == 'h' ||
				s[*j] == 'l' || s[*j] == '.')
		{
			*j += 1;
		}
		else
		{
			*j -= 1;
			return (0);
		}
	}
	return (0);
}
/*
int main()
{
	char *s;

	s = "coucou %-0/=/-+5s toi";
	printf("%s\n", ft_get_opt(ft_strchr(s , '%') + 1));
	return (0);
}*/
