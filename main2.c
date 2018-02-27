
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <kgricour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:35:58 by kgricour          #+#    #+#             */
/*   Updated: 2018/02/27 22:59:10 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/libft.h"
#include <stdio.h>
#include  "srcs/ft_printf.h"
#include <locale.h>
#include <limits.h>
#include <sys/signal.h>

int main(void)
{
	ft_printf("\n"); //ok
	ft_printf("%%\n");//ok
	ft_printf("%d\n", 42);//ok
	ft_printf("%d%d\n", 42, 41);//ok
	ft_printf("%d%d%d\n", 42, 43, 44);//ok
	ft_printf("%ld\n", 2147483647); //ok
	ft_printf("%lld\n", 9223372036854775807); //ok
	ft_printf("%x\n", 505);
//	ft_printf("%X\n", 505);
//	ft_printf("%p\n", &ft_printf);
//	ft_printf("%20.15d\n", 54321);
//	ft_printf("%-10d\n", 3);
//	ft_printf("% d\n", 3);
//	ft_printf("%+d\n", 3);
//	ft_printf("%010d\n", 1);
//	ft_printf("%hhd\n", 0);
//	ft_printf("%jd\n", 9223372036854775807);
//	ft_printf("%zd\n", 4294967295);
//	ft_printf("%\n");
//	ft_printf("%U\n", 4294967295);
//	ft_printf("%u\n", 4294967295);
//	ft_printf("%o\n", 40);
//	ft_printf("%%#08x\n", 42);
//	ft_printf("%x\n", 1000);
//	ft_printf("%#X\n", 1000);
//	ft_printf("%s\n", NULL);
//	ft_printf("%S\n", L"ݗݜशব");
//	ft_printf("%s%s\n", "test", "test");
//	ft_printf("%s%s%s\n", "test", "test", "test");
//	ft_printf("%C\n", 15000);
getchar();
	//	int i;
	//	i = 0;
	//		setlocale(LC_ALL, "");
	//		wchar_t *str = L"1 ☂ 2 € 3 ☯ 4 ∞ 5 ❤ 6 ♫ ";
	//		char	*ft_putwstr(wchar_t *s);
	//		ft_printf("% ");
	//	ft_printf("{%10R}");
	//	printf("{%10R}");
	//	ft_printf("{%05p}\n", 0);
	//	printf("{%05p}\n", 0);
	//	ft_printf("{% 03d}", 0);
	//	ft_printf("{%05.S}", L"42 c est cool");
	//	printf("{%05.S}", L"42 c est cool");
	//	ft_printf("%9.2p\n", 1234);
	//	printf("%9.2p\n", 1234);
	//	ft_printf("%.5p\n", 0);
	//	printf("%.5p\n", 0);
	//	ft_printf("%.0p, %.p\n", 0, 0);
	//	printf("%.0p, %.p\n", 0, 0);
	//	ft_printf("%15.4S", L"我是一只猫。");
	//	printf("%15.4S", L"我是一只猫。");
	//	ft_printf("%.4S\n", L"我是一只猫。");
	//	printf("%.4S\n", L"我是一只猫。");
	//	ft_printf("%15.4d\n", -42);
	//	printf("%15.4d\n", -42);
	//	ft_printf("{%#.5x}\n", 1); // a regler
	//	printf("{%#.5x}\n", 1);
	//	ft_printf("%#.3o\n", 1);
	//	printf("%#.3o\n", 1);
	//		ft_printf("{% 03d}\n", 0);
	//	   printf("{% 03d}\n", 0);

	//ft_printf("%4.15d\n", 42);
	//   printf("%4.15d\n", 42);
	//	ft_printf("%.4d\n", -424242);
	//	ft_printf("%.4d\n", 424242);
	//ft_printf("{%-15Z}\n", 123);//----------
	//   printf("{%-15Z}\n", 123);//---------
	//	ft_printf("% 10.5d", 4242);
	//ft_printf("%10s is a string", "this");
	//		printf("% 10.5d", 4242);
	//  ft_printf("->%+01d\n", 0);
	//     printf("->%+01d\n", 0);
	//	  ft_printf("%.0p, %.p", 0, 0);
	//	  printf("%.0p, %.p", 0, 0);
	//	  ft_printf("%0+5d\n", 42);
	//	  printf("%0+5d\n", 42);
	//	ft_putnbr(ft_printf("%s\n", ));
	//	ft_putnbr(printf("%s\n", NULL));

	//	ft_printf("% T%s\n", "test");
	//	printf("% T%s\n", "test");
	//	ft_printf("%-15p\n", 0);
	//	printf("%-15p\n", 0);

	//	ft_printf("%D\n", LONG_MIN);
	//	printf("%D\n", LONG_MIN);
	//		while ( i != 1)
	//		{
	//			ft_printf("%-5%\n", -4200000);
	//			printf("%05lld\n", -4200000);
	//		 ft_printf("@moulitest: %.10d\n", -42);
	//		 sleep(1);
	//		 i++;
	//		}

	//		ft_printf("{%-15p}\n", 0);
	//		printf("{%-15p}\n", 0);
	//	ft_printf("{%-15Z}", 123);
	//	printf("{%-15Z}", 123);
	//	ft_printf("%.0p, %.p\n", 0, 0);
	//	printf("%.0p, %.p\n", 0, 0);
	//	NG_MIN)
	//	NG_MIN)
	//	ft_printf("%.5p\n", 0); //<------------------------------
	//	printf("%.5p\n", 0); 
	//	ft_printf("%.0d\n", 0); //<------------------------------
	//		printf("%.0d\n", 0);
	//printf("%p\n", 0);
	//ft_printf("%p\n", 0);
	//ft_printf("%   Zoooo\n");
	//ft_printf("{%}\n");
	//   printf("{%}\n");
	//	ft_printf("_____________Behavior_____________\n");
	//	ft_printf("-0+5 %-0+5d\n", 42);
	//	printf("-0+5 %-0+5d\n", 42);
	//	ft_printf("zhd %zhd\n", 4294967296);	
	//	printf("zhd %zhd\n", 4294967296);
	//	ft_printf("jhd %jhd\n", 9223372036854775807);
	//	printf("jhd %jhd\n", 9223372036854775807);	
	//	ft_printf("_____________TEST UNICODE_____________\n");
	//	ft_putnbr(ft_printf("ls = %ls\n", str));
	//		ft_putnbr(printf("ls = %ls\n", str));
	/*	ft_printf("S = %S\n", str);// L'☂');
		printf("S = %S\n", str);
		ft_printf("ls0 = %ls\n", 0);
		printf("ls0 = %ls\n", 0);
		ft_printf("S0 = %S\n", 0);// L'☂');
		printf("S0 = %S\n", 0);
		ft_printf("lc = %lc\n", L'☂');
		printf("lc = %lc\n", L'☂');
		ft_printf("C = %C\n", L'☂');// L'☂');
		printf("C = %C\n", L'☂');
		ft_printf("lc0 = %lc\n", 0);
		printf("lc0 = %lc\n", 0);
		ft_printf("lC0 = %C\n", 0);// L'☂');
		printf("lC0 = %C\n", 0);*/
	//   printf("%   Zoooo\n");
	//printf("%O", 0);
	//ft_printf("%O\n", 0);
	//	ft_printf("%.2s\n", "424242");
	//printf("%.2s\n", "424242");
	//	ft_printf("%5.2s is a string\n", "this");
	//	printf("%5.2s is a string\n", "this");
	//ft_printf("%hx", 4294967296);
	//  printf("%hx", 4294967296);
	//	ft_printf("%D\n", 1234567891011112);
	//	   printf("%D\n", 1234567891011112);
	//  ft_printf("%#x\n", 0);
	//    printf("%#x\n", 0);
	//	ft_printf("%.5x\n", 5427);
	//	   printf("%.5x\n", 5427);
	//   printf("%s");
	//	ft_printf("%s");
	//	printf("%hd\n", 444444442);
	//	ft_printf("%hd\n", 444444442);
	//	ft_printf("%+10.5d\n", 4242);
	//	printf("%+10.5d\n", 4242)0;
	//	ft_printf("%03.2d\n", 1); 
	//	ft_printf("@moulitest: %#.x %#.0x\n", 0, 0);
	//	   printf("@moulitest: %#.x %#.0x\n", 0, 0);
	//	   ft_printf("%0+5d\n", 42);
	//	      printf("%0+5d\n", 42);
	//		ft_printf("%0+7d\n", -42);
	//		   printf("%0+7d\n", -42);
	//ft_printf("%+0.0d\n", 4242);
	// printf("%+0.0d\n", 4242);
	// ft_printf("%03.2d", -1);
	//ft_printf("%5.2s\n", "coucou");
	//  printf("%+ d", -42);
	// ft_printf("dfsfdsfsgdsfgd%c  gtrwtrtwrwrt\n", 0);
	//printf("%d\n", 'c');
	//	ft_printf("%03.2d\n", 0);
	//	   printf("%03.2d\n", 1); 
	//	   printf("%03.2d\n", 0);
	//	ft_printf("@moulitest: %.10d", -42);
	//	   printf("@moulitest: %.10d", -42);
	//		ft_printf("@mouli11test: %5.c %5.0c\n", 0, 0);
	//		printf("@moulitest: %5.c %5.0c\n", 0, 0);
	//	ft_printf("%07d\n", 1234);
	//		ft_printf("%07d\n", 1234);
	//		ft_printf("%03.2d\n", -1);
	//		   printf("%03.2d\n", -1);
	//		   ft_printf("%5d\n", -42);
	//		      printf("%5d\n", -42);
	//	ft_printf("%#08x\n", 42);
	//		printf("%#08x\n", 42);
	//	char *str = "coucou";
	//	ft_printf("->%U\n", 30000000000);
	//	ft_printf("%u\n", -1);
	//	   printf("%u\n", -1);
	//	   ft_printf("%.50lx\n", 4294967296);
	//	   printf("%.50lx\n", 4294967296);
	//	ft_printf("%X\n", 10);
	//	ft_printf("%x\n", 10);
	//	ft_printf("%b\n", "coucou");
	//	ft_printf("%o\n", 10);
	//	ft_printf("%50S\n", str);
	//	   printf("%50S\n", str);
	//	ft_printf("%#08x\n", 42);
	//	printf("%#08x\n", 42);
	//	ft_printf("%#.x%#.0x\n", 0, 0);
	//	   printf("%#.x%#.0x\n", 0, 0);
	/*
	   double i = 3.123456789;
	//	ft_printf("coucou %s toi\n");
	//	   printf("coucou %s toi\n");
	ft_printf("%C\n", L'☂');
	ft_printf("% Z \n", "test");
	printf("% Z \n", "test");
	ft_printf("%10.  Z\n");
	printf("%10.   Z\n");
	ft_printf("%#.x %#.5x\n", 42, 42);
	ft_printf("ft hexa = %#X\n", 0);// ULLONG_MAX);
	printf("pr hexa = %#X\n", 0);// ULLONG_MAX);*/
	//	ft_printf("ft hexa = %#llx\n", 0);
	//	printf("pr hexa = %#llx\n", 0);
	//		ft_printf("ft hexa = %x\n", -999999999);
	//		printf("pr hexa = %x\n", -999999999);

	//		printf("%ld\n", -100);
	/*		ft_printf("%ld\n", -100);
			ft_printf("ft %+05d\n", 7);
			printf("pr %+05d\n", 7);
			ft_printf("\n");
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
			ft_printf("%s %d%s   %  %%coucou %c %p %hhd toi %i", "salut", 12,"femme", 'c', 16, 777, 12, 1258);
			ft_printf("\n");
			printf("%s %d%s   %  %%coucou %c %p %hhd toi %i", "salut", 12,"femme", 'c', 16, 777, 12, 1258);
			ft_printf("\n");
			ft_printf("%x", 42);
			printf("%s%s", "this is a string","k");
			printf("%s \n", "this is a string");
			printf("%#.x %#.0x", 0, 0);
			long long int nbr = 245884445778;
			ft_printf("ft_printf %%-5%%=> %-5% <\n");
			printf("   printf %%-5%%=> %-5% <\n");
			ft_printf("ft_printf %%05%%=> %05% <\n");
			printf("   printf %%05%%=> %05% <\n");
			ft_printf("ft_printf %%-05%%=> %05%  <\n");
			printf("   printf %%-05%%=> %05% <\n");
			ft_printf("s: %s, p: %p, d:%d\n", "a string", &nbr, 42);
			printf("s: %s, p: %p, d:%d\n", "a string", &nbr, 42);
	//		getchar();*/
	//
	//
}
