
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <kgricour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:35:58 by kgricour          #+#    #+#             */
/*   Updated: 2018/05/09 17:47:51 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include  "ft_printf.h"
#include <locale.h>
#include <limits.h>
#include <sys/signal.h>

int main(int argc, char **argv)
{
	wchar_t *str = L"1 ☂ 2 € 3 ☯ 4 ∞ 5 ❤ 6 ♫ ";
	int	ret;
	int	ret2;

	int i = 5 ;
	ft_printf("%p\n", &i);
	printf("%p\n", &i);


	setlocale(LC_ALL, "");
	ret = ft_printf("_____TEST %%s %%S _____\n");
	ret2 = printf("_____TEST %%s %%S _____\n");
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%s\n", NULL);
	ret2 = printf("%s\n", NULL);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%50S\n", L"ݗݜशব");
	ret2 = printf("%50S\n", L"ݗݜशব");
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%50s\n", "lol");
	ret2 = printf("%50s\n", "lol");
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%S\n", NULL);
	ret2 = printf("%S\n", NULL);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%s%s\n", "test", "test");//ok
	ret2 = printf("%s%s\n", "test", "test");//ok
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%s%s%s\n", "test", "test", "test");//ok
	ret2 = printf("%s%s%s\n", "test", "test", "test");//ok
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%15S\n", L"我是一只猫。"); //behavior
	ret2 = printf("%15S\n", L"我是一只猫。"); //behavior
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%S\n", L"我是一只猫。"); //behavior
	ret2 = printf("%S\n", L"我是一只猫。"); //behavior
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%10s is a string\n", "this");
	ret2 = printf("%10s is a string\n", "this");
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("% T%s\n", "test"); //behavior
	ret2 = printf("% T%s\n", "test"); //behavior
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%s\n", 0);
	ret2 = printf("%s\n", 0);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("ls = %ls\n", str);
	ret2 = printf("ls = %ls\n", str);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("S = %S\n", str);
	ret2 = printf("S = %S\n", str);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("ls0 = %ls\n", 0);
	ret2 = printf("ls0 = %ls\n", 0);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("S0 = %S\n", 0);
	ret2 = printf("S0 = %S\n", 0);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("lc = %lc\n", L'☂');
	ret2 = printf("lc = %lc\n", L'☂');
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("C = %C\n", L'☂');
	ret2 = printf("C = %C\n", L'☂');
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("lc0 = %lc\n", 0);
	ret2 = printf("lc0 = %lc\n", 0);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("lC0 = %C\n", 0);
	ret2 = printf("lC0 = %C\n", 0);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("_____TEST %%d %%i _____\n");
	ret2 = printf("_____TEST %%d %%i _____\n");
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%d\n", 42);//ok
	ret2 = printf("%d\n", 42);//ok
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%d%d\n", 42, 41);//ok
	ret2 = printf("%d%d\n", 42, 41);//ok
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%d%d%d\n", 41, 43, 44);//ok
	ret2 = printf("%d%d%d\n", 41, 43, 44);//ok
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%ld\n", 2147483647); //ok
	ret2 = printf("%ld\n", 2147483647); //ok
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%lld\n", 9223372036854775807); //ok
	ret2 = printf("%lld\n", 9223372036854775807); //ok
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%20.15d\n", -54321);//ok
	ret2 = printf("%20.15d\n", -54321);//ok
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%-10d\n", 3);//ok
	ret2 = printf("%-10d\n", 3);//ok
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("% d\n", 3);//ok
	ret2 = printf("% d\n", 3);//ok
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%+d\n", 3);//ok
	ret2 = printf("%+d\n", 3);//ok
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%010d\n", 1);//ok
	ret2 = printf("%010d\n", 1);//ok
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%hhd\n", 0);
	ret2 = printf("%hhd\n", 0);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%jd\n", 9223372036854775807);//ok
	ret2 = printf("%jd\n", 9223372036854775807);//ok
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%zd\n", 4294967295);//ok
	ret2 = printf("%zd\n", 4294967295);//ok
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%hh50.20ld\n", 2); //behavior
	ret2 = printf("%hh50.20ld\n", 2); //behavior
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%05.1d\n", -6);
	ret2 = printf("%05.1d\n", -6);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("{% 03d}\n", 0); //behavior
	ret2 = printf("{% 03d}\n", 0); //behavior
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%15.4d\n", -42);
	ret2 = printf("%15.4d\n", -42);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("{% 03d}\n", 0);
	ret2 = printf("{% 03d}\n", 0);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%4.15d\n", 42);
	ret2 = printf("%4.15d\n", 42);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%.4d\n", -424242);
	ret2 = printf("%.4d\n", -424242);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%.4d\n", 424242);
	ret2 = printf("%.4d\n", 424242);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("% 10.5d\n", 4242);
	ret2 = printf("% 10.5d\n", 4242);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("->%+01d\n", 0);
	ret2 = printf("->%+01d\n", 0);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%0+5d\n", 42);
	ret2 = printf("%0+5d\n", 42);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%D\n", LONG_MIN);
	ret2 = printf("%D\n", LONG_MIN);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%.0d\n", 0);
	ret2 = printf("%.0d\n", 0);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%07d\n", 1234);
	ret2 = printf("%07d\n", 1234);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%07d\n", 1234);
	ret2 = printf("%07d\n", 1234);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%03.2d\n", -1);
	ret2 = printf("%03.2d\n", -1);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%5d\n", -42);
	ret2 = printf("%5d\n", -42);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("-0+5 %-0+5d\n", 42);
	ret2 = printf("-0+5 %-0+5d\n", 42);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("zhd %zhd\n", 4294967296);	
	ret2 = printf("zhd %zhd\n", 4294967296);	
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("jhd %jhd\n", 9223372036854775807);
	ret2 = printf("jhd %jhd\n", 9223372036854775807);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%D\n", 1234567891011112);
	ret2 = printf("%D\n", 1234567891011112);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%hd\n", 444444442);
	ret2 = printf("%hd\n", 444444442);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%+10.5d\n", 4242);
	ret2 = printf("%+10.5d\n", 4242);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%03.2d\n", 1); 
	ret2 = printf("%03.2d\n", 1); 
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%0+5d\n", 42);
	ret2 = printf("%0+5d\n", 42);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%0+7d\n", -42);
	ret2 = printf("%0+7d\n", -42);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%+0.0d\n", 4242);
	ret2 = printf("%+0.0d\n", 4242);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%03.2d\n", -1);
	ret2 = printf("%03.2d\n", -1);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%03.2d\n", 0);
	ret2 = printf("%03.2d\n", 0);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%.10d\n", -42);
	ret2 = printf("%.10d\n", -42);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%ld\n", -100);
	ret2 = printf("%ld\n", -100);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("ft %+05d\n", 7);
	ret2 = printf("ft %+05d\n", 7);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("\n"); //ok	
	ret2 = printf("\n"); //ok	
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%%\n");//ok
	ret2 = printf("%%\n");//ok
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%x\n", 505); //ok
	ret2 = printf("%x\n", 505); //ok
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%X\n", 505);//ok
	ret2 = printf("%X\n", 505);//ok
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%p\n", &ft_printf);//ok
	ret2 = printf("%p\n", &ft_printf);//ok
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%\n");//ok
	ret2 = printf("%\n");//ok
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%U\n", 4294967295);//ok
	ret2 = printf("%U\n", 4294967295);//ok
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%u\n", 4294967295);//ok
	ret2 = printf("%u\n", 4294967295);//ok
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%o\n", 40);//ok
	ret2 = printf("%o\n", 40);//ok
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%%#08x\n", 42);//ok
	ret2 = printf("%%#08x\n", 42);//ok
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%x\n", 1000);//ok
	ret2 = printf("%x\n", 1000);//ok
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%#X\n", 1000);//ok
	ret2 = printf("%#X\n", 1000);//ok
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%C\n", 15000);//ok
	ret2 = printf("%C\n", 15000);//ok
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("% ");
	ret2 = printf("% ");
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("dfssgdsfgd%cgtrwtrt\n", '-');
	ret2 = printf("dfssgdsfgd%cgtrwtrt\n", '-');
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("{%05p}\n", 0);
	ret2 = printf("{%05p}\n", 0);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%#08x\n", 42);
	ret2 = printf("%#08x\n", 42);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%.5p\n", 0);
	ret2 = printf("%.5p\n", 0);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("{%#.5x}\n", 1); 
	ret2 = printf("{%#.5x}\n", 1); 
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%#.3o\n", 1);		
	ret2 = printf("%#.3o\n", 1);		
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%-15p\n", 0);
	ret2 = printf("%-15p\n", 0);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%-5%\n", -4200000);
	ret2 = printf("%-5%\n", -4200000);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("{%-15p}\n", 0);
	ret2 = printf("{%-15p}\n", 0);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%.5p\n", 0);
	ret2 = printf("%.5p\n", 0);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%p\n", 0);
	ret2 = printf("%p\n", 0);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%   Zoooo\n");
	ret2 = printf("%   Zoooo\n");
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("{%}\n");
	ret2 = printf("{%}\n");
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%12.10X\n", 424242424);
	ret2 = printf("%12.10X\n", 424242424);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%12.10x\n", 424242424);
	ret2 = printf("%12.10x\n", 424242424);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%O\n", 0); 
	ret2 = printf("%O\n", 0); 
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%#x\n", 0); 
	ret2 = printf("%#x\n", 0); 
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%#.x %#.0x\n", 0, 0);
	ret2 = printf("%#.x %#.0x\n", 0, 0);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%4.2s\n", "424242");
	ret2 = printf("%4.2s\n", "424242");
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%9.20s is a string\n", "this");
	ret2 = printf("%9.20s is a string\n", "this");
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%hx", 4294967296);
	ret2 = printf("%hx", 4294967296);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%.5x\n", 5427);
	ret2 = printf("%.5x\n", 5427);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%5.c %5.0c\n", 0, 0);
	ret2 = printf("%5.c %5.0c\n", 0, 0);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%5.2s\n", "coucou");
	ret2 = printf("%5.2s\n", "coucou");
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%#08x\n", 42);
	ret2 = printf("%#08x\n", 42);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("->%U\n", 30000000000);
	ret2 = printf("->%U\n", 30000000000);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%u\n", -1);
	ret2 = printf("%u\n", -1);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%.50lx\n", 4294967296);
	ret2 = printf("%.50lx\n", 4294967296);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%X\n", 10);
	ret2 = printf("%X\n", 10);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%x\n", 10);
	ret2 = printf("%x\n", 10);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%b\n", "coucou");
	ret2 = printf("%b\n", "coucou");
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%o\n", 10);
	ret2 = printf("%o\n", 10);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%50S\n", str);
	ret2 = printf("%50S\n", str);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%#08x\n", 42);
	ret2 = printf("%#08x\n", 42);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%#.x%#.0x\n", 0, 0);
	ret2 = printf("%#.x%#.0x\n", 0, 0);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%C\n", L'☂');
	ret2 = printf("%C\n", L'☂');
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("% Z \n", "test");
	ret2 = printf("% Z \n", "test");
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%#.x %#.5x\n", 42, 42);
	ret2 = printf("%#.x %#.5x\n", 42, 42);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%.0p, %.p\n", 0, 0);
	ret2 = printf("%.0p, %.p\n", 0, 0);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%9.2p\n", 1234);
	ret2 = printf("%9.2p\n", 1234);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("ft hexa = %#X\n", 0);// ULLONG_MAX);
	ret2 = printf("ft hexa = %#X\n", 0);// ULLONG_MAX);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("ft hexa = %#llx\n", 0);
	ret2 = printf("ft hexa = %#llx\n", 0);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("ft hexa = %x\n", -999999999);
	ret2 = printf("ft hexa = %x\n", -999999999);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("ft--->%% %5% %%%\n");
	ret2 = printf("ft--->%% %5% %%%\n");
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("ft--->%-5%\n");
	ret2 = printf("ft--->%-5%\n");
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%s\n", "this is a string");
	ret2 = printf("%s\n", "this is a string");
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%s%s\n", "this is a string","k");
	ret2 = printf("%s%s\n", "this is a string","k");
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%s%s \n", "this is a string","k");
	ret2 = printf("%s%s \n", "this is a string","k");
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%s \n", "this is a string");
	ret2 = printf("%s \n", "this is a string");
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%s %d%s   %  %%coucou %c %p %hhd toi %i\n", "salut", 12,"femme", 'c', 16, 777, 12, 1258);
	ret2 = printf("%s %d%s   %  %%coucou %c %p %hhd toi %i\n", "salut", 12,"femme", 'c', 16, 777, 12, 1258);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%x\n", 42);
	ret2 = printf("%x\n", 42);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%%-5%%=> %-5% <\n");
	ret2 = printf("%%-5%%=> %-5% <\n");
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%%05%%=> %05% <\n");
	ret2 = printf("%%05%%=> %05% <\n");
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%%-05%%=> %05%  <\n");
	ret2 = printf("%%-05%%=> %05%  <\n");
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("s: %s, p: %p, d:%d\n", "a string", &str, 42);
	ret2 = printf("s: %s, p: %p, d:%d\n", "a string", &str, 42);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
 	ret = ft_printf("%03.2d\n", -1);
 	ret2 = printf("%03.2d\n", -1);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
 	ret = ft_printf("%15.10d\n", -42);
 	ret2 = printf("%15.10d\n", -42);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
 	ret = ft_printf("%4.15s\n", "42");
 	ret2 = printf("%4.15s\n", "42");
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%.4S\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	ret2 = printf("%.4S\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("%.4s\n", "coucou toi ca va");
	ret2 = printf("%.4s\n", "coucou toi ca va");
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	ret = ft_printf("[%10zu] [%zu]\n", -78, -99);
	ret2 = printf("[%10zu] [%zu]\n", -78, -99);
	ft_printf("ret = %d && ret2 = %d\n", ret, ret2);
	if (argc == 2)
	{
		getchar();
		argv[argc-1] = NULL;
	}

}
