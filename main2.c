
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <kgricour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:35:58 by kgricour          #+#    #+#             */
/*   Updated: 2018/03/01 19:19:19 by kgricour         ###   ########.fr       */
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
	wchar_t *str = L"1 ☂ 2 € 3 ☯ 4 ∞ 5 ❤ 6 ♫ ";

	setlocale(LC_ALL, "");
	ft_printf("_____TEST %%s %%S _____\n");
	ft_printf("%s\n", NULL);
	ft_printf("%50S\n", L"ݗݜशব");
	ft_printf("%50s\n", "lol");
	ft_printf("%S\n", NULL);
	ft_printf("%s%s\n", "test", "test");//ok
	ft_printf("%s%s%s\n", "test", "test", "test");//ok
	ft_printf("%15S\n", L"我是一只猫。"); //behavior
	ft_printf("%S\n", L"我是一只猫。"); //behavior
	ft_printf("%10s is a string\n", "this");
	ft_printf("% T%s\n", "test"); //behavior
	ft_printf("%s\n", 0);
	ft_printf("ls = %ls\n", str);
	ft_printf("S = %S\n", str);
	ft_printf("ls0 = %ls\n", 0);
	ft_printf("S0 = %S\n", 0);
	ft_printf("lc = %lc\n", L'☂');
	ft_printf("C = %C\n", L'☂');
	ft_printf("lc0 = %lc\n", 0);
	ft_printf("lC0 = %C\n", 0);

	ft_printf("_____TEST %%d %%i _____\n");
	ft_printf("%d\n", 42);//ok
	ft_printf("%d%d\n", 42, 41);//ok
	ft_printf("%d%d%d\n", 41, 43, 44);//ok
	ft_printf("%ld\n", 2147483647); //ok
	ft_printf("%lld\n", 9223372036854775807); //ok
	ft_printf("%20.15d\n", -54321);//ok
	ft_printf("%-10d\n", 3);//ok
	ft_printf("% d\n", 3);//ok
	ft_printf("%+d\n", 3);//ok
	ft_printf("%010d\n", 1);//ok
	ft_printf("%hhd\n", 0);
	ft_printf("%jd\n", 9223372036854775807);//ok
	ft_printf("%zd\n", 4294967295);//ok
//	ft_printf("%hh50.20ld\n", 2); //behavior
	ft_printf("%05.1d\n", -1);
	ft_printf("{% 03d}\n", 0); //behavior
	ft_printf("%15.4d\n", -42);
	ft_printf("{% 03d}\n", 0);
	ft_printf("%4.15d\n", 42);
	ft_printf("%.4d\n", -424242);
	ft_printf("%.4d\n", 424242);
	ft_printf("% 10.5d\n", 4242);
	ft_printf("->%+01d\n", 0);
	ft_printf("%0+5d\n", 42);
	ft_printf("%D\n", LONG_MIN);
	ft_printf("%.0d\n", 0);
	ft_printf("%07d\n", 1234);
	ft_printf("%07d\n", 1234);
	ft_printf("%03.2d\n", -1);
	ft_printf("%5d\n", -42);
	ft_printf("-0+5 %-0+5d\n", 42);
	ft_printf("zhd %zhd\n", 4294967296);	
	ft_printf("jhd %jhd\n", 9223372036854775807);
	ft_printf("%D\n", 1234567891011112);
	ft_printf("%hd\n", 444444442);
	ft_printf("%+10.5d\n", 4242);
	ft_printf("%03.2d\n", 1); 
	ft_printf("%0+5d\n", 42);
	ft_printf("%0+7d\n", -42);
	ft_printf("%+0.0d\n", 4242);
	ft_printf("%03.2d\n", -1);
	ft_printf("%03.2d\n", 0);
	ft_printf("%.10d\n", -42);
	ft_printf("%ld\n", -100);
	ft_printf("ft %+05d\n", 7);
	ft_printf("\n"); //ok	
	ft_printf("%%\n");//ok
	ft_printf("%x\n", 505); //ok
	ft_printf("%X\n", 505);//ok
	ft_printf("%p\n", &ft_printf);//ok
	ft_printf("%\n");//ok
	ft_printf("%U\n", 4294967295);//ok
	ft_printf("%u\n", 4294967295);//ok
	ft_printf("%o\n", 40);//ok
	ft_printf("%%#08x\n", 42);//ok
	ft_printf("%x\n", 1000);//ok
	ft_printf("%#X\n", 1000);//ok
	ft_printf("%C\n", 15000);//ok
	ft_printf("% ");
	ft_printf("{%10R}\n");
	ft_printf("dfsfdsfsgdsfgd%c  gtrwtrtwrwrt\n", 0);
	ft_printf("{%05p}\n", 0);
	ft_printf("%#08x\n", 42);
	ft_printf("%9.2p\n", 1234);
	ft_printf("%.5p\n", 0);
	ft_printf("%.0p, %.p\n", 0, 0);
	ft_printf("{%#.5x}\n", 1); // a regler
	ft_printf("%#.3o\n", 1);		
	ft_printf("{%-15Z}\n", 123);//----------
	printf("{%-15Z}\n", 123);
	ft_printf("%.0p, %.p\n", 0, 0);
	ft_printf("%-15p\n", 0);
	ft_printf("%-5%\n", -4200000);
	ft_printf("{%-15p}\n", 0);
	ft_printf("%.5p\n", 0);
	ft_printf("%p\n", 0);
	ft_printf("%   Zoooo\n");
	ft_printf("{%}\n");
	ft_printf("%12.10X\n", 424242424);
	ft_printf("%12.10x\n", 424242424);
	ft_printf("pb 42fs = {%10R}\n");
	   printf("pb 42fs = {%10R}\n");
	ft_printf("%O\n", 0); 
	ft_printf("%#x\n", 0); 
	ft_printf("%#.x %#.0x\n", 0, 0);
	ft_printf("{%-15Z}\n", 123); //<----- pas gere
	ft_printf("%4.2s\n", "424242");
	ft_printf("%9.10s is a string\n", "this");
	ft_printf("%hx", 4294967296);
	ft_printf("%.5x\n", 5427);
	ft_printf("%s");
	ft_printf("%5.c %5.0c\n", 0, 0);
	ft_printf("%5.2s\n", "coucou");
	ft_printf("%#08x\n", 42);
	ft_printf("->%U\n", 30000000000);
	ft_printf("%u\n", -1);
	ft_printf("%.50lx\n", 4294967296);
	ft_printf("%X\n", 10);
	ft_printf("%x\n", 10);
	ft_printf("%b\n", "coucou");
	ft_printf("%o\n", 10);
	ft_printf("%50S\n", str);
	ft_printf("%#08x\n", 42);
	ft_printf("%#.x%#.0x\n", 0, 0);
	ft_printf("coucou %s toi\n");
	ft_printf("%C\n", L'☂');
	ft_printf("% Z \n", "test");
	ft_printf("%10.  Z\n");
	ft_printf("%#.x %#.5x\n", 42, 42);
	ft_printf("ft hexa = %#X\n", 0);// ULLONG_MAX);
	ft_printf("ft hexa = %#llx\n", 0);
	ft_printf("ft hexa = %x\n", -999999999);
	ft_printf("ft--->%% %5% %%%\n");
	ft_printf("ft--->%-5%\n");
	ft_printf("%s", "this is a string\n");
	ft_printf("%s%s", "this is a string\n","k");
	ft_printf("%s%s ", "this is a string\n","k");
	ft_printf("%s ", "this is a string\n");
	ft_printf("%s %d%s   %  %%coucou %c %p %hhd toi %i\n", "salut", 12,"femme", 'c', 16, 777, 12, 1258);
	ft_printf("%x\n", 42);
	ft_printf("ft_printf %%-5%%=> %-5% <\n");
	ft_printf("ft_printf %%05%%=> %05% <\n");
	ft_printf("ft_printf %%-05%%=> %05%  <\n");
	ft_printf("s: %s, p: %p, d:%d\n", "a string", &str, 42);
	getchar();
}
