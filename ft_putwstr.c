/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 16:22:13 by kgricour          #+#    #+#             */
/*   Updated: 2018/02/12 19:00:08 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_putwstr(wchar_t *s)
{
		printf("la\n");
	char *new_str;
	char *tmp;
	char *tmp2;

	new_str = NULL;
	if (s != NULL)
	{
		while (*s)
		{
			tmp = new_str;
			tmp2 = ft_putwchar(*s);
			new_str = ft_strjoin(new_str, (const char *)tmp2);
			ft_strdel(&tmp);
			s++;
		}
	}
	return (new_str);
}
