/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <kgricour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:35:58 by kgricour          #+#    #+#             */
/*   Updated: 2018/02/02 17:19:53 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/ft_printf.h"
#include "srcs/libft.h"
#include <stdio.h>
#include  "srcs/ft_printf.h"

int main(void)
{
//	ft_printf("%#.x %#.0x", 0, 0);
/*	ft_printf("ft coucou %5p toi", "kevin c'est bien ");
	ft_printf("\n");
	ft_printf("%s", "this is a string");
	ft_printf("\n");
	ft_printf("%s%s", "this is a string","k");
	ft_printf("\n");
	ft_printf("%s%s ", "this is a string","k");
	ft_printf("\n");
	ft_printf("%s ", "this is a string");
	ft_printf("\n");*/
	ft_printf("%s %d%s   %  %%coucou %c %p %hhd toi %i", "salut", 12,"femme", 'k', 16, 777, 1234567);
	   printf("%s %d%s   %  %%coucou %c %p %hhd toi %i", "salut", 12,"femme", 'k', 16, 777, 1234567);
	ft_printf("\n");
//	ft_printf("%x", 42);
//	printf("%s%s", "this is a string","k");
//	printf("%s \n", "this is a string");
//	printf("%#.x %#.0x", 0, 0);
//	long long int nbr = 245884445778;
//	ft_printf("ft_printf %%-5%% => %-5%  <\n");
//	   printf("   printf %%-5%% => %-5% <\n");
//	ft_printf("ft_printf %%05%%=> %05%  <\n");
//	   printf("   printf %%05%%=> %05% <\n");
//	ft_printf("ft_printf %%-05%%=> %05%  <\n");
//	   printf("   printf %%-05%%=> %05% <\n");
//	ft_printf("s: %s, p: %p, d:%d\n", "a string", &nbr, 42);
//	printf("s: %s, p: %p, d:%d\n", "a string", &nbr, 42);
}
