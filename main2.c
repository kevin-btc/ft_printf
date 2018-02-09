
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <kgricour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:35:58 by kgricour          #+#    #+#             */
/*   Updated: 2018/02/08 18:18:14 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/libft.h"
#include <stdio.h>
#include  "srcs/ft_printf.h"

int main(void)
{
	int i = 3;
//	ft_printf("%#.x %#.0x", 0, 0);
//	ft_printf("ft hexa = %#X\n", 0);// ULLONG_MAX);
//	   printf("pr hexa = %#X\n", 0);// ULLONG_MAX);
//	ft_printf("ft hexa = %#llx\n", 0);
//	   printf("pr hexa = %#llx\n", 0);
	ft_printf("ft hexa = %x\n", -999999999);
	   printf("pr hexa = %x\n", -999999999);
	
//	printf("%ld\n", -100);
//	ft_printf("%ld\n", -100);
//	ft_printf("ft %+05d\n", 7);
//	   printf("pr %+05d\n", 7);
/*	ft_printf("\n");
	ft_printf("ft--->%% %5% %%%");
	ft_printf("\n");
	ft_printf("ft--->%-5%");
	ft_printf("\n");
	ft_printf("%s", "this is a string");
	ft_printf("\n");
	ft_printf("%s%s", "this is a string","k");
	ft_printf("\n");
	ft_printf("%s%s ", "this is a string","k");
	ft_printf("\n");
	ft_printf("%s ", "this is a string");
	ft_printf("\n");
	ft_printf("%s %d%s   %  %%coucou %c %p %hhd toi %i", "salut", 12,"femme", 'c', 16, 777, 12, 1258);
	   printf("%s %d%s   %  %%coucou %c %p %hhd toi %i", "salut", 12,"femme", 'c', 16, 777, 12, 1258);
	ft_printf("\n");*/
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
