/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 19:44:46 by kgricour          #+#    #+#             */
/*   Updated: 2018/01/20 21:38:09 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "srcs/ft_printf.h"
#include <locale.h>


int main(int argc, char **argv)
{
	char *locale;

	locale = setlocale(LC_ALL, "");
	//system("clear");
	if (argc == 1)
	{
		ft_printf("Gestion de la conversion %%c, et le cas avec des espaces entre %% et c: \n\n");
		ft_printf("ft_printf(\"affiche un seul caractere : %%    c\", 'k');\n-------------------------\n\n");
		ft_putendl("ft_printf :");
		ft_printf("affiche un seul caractere : %      C", 0x1f0);
		ft_putchar('\n');
		ft_putchar('\n');
		ft_putendl("printf :");
		printf("affiche un seul caractere : %       C\n", 0x1f0);
	}
	
	if (argc == 2)
	{
		ft_putendl("ft_printf :");
		ft_printf(argv[1]);
		ft_putchar('\n');
		ft_putchar('\n');
		ft_putendl("printf :");
		printf(argv[1]);
	}
	if (argc == 3)
	{
		ft_putendl("ft_printf :");
		ft_printf(argv[1], argv[2]);
		ft_putchar('\n');
		ft_putchar('\n');
		ft_putendl("printf :");
		printf(argv[1], argv[2]);
	}
	if (argc == 4)
	{
		ft_putendl("ft_printf :");
		ft_printf(argv[1], argv[2], argv[3]);
		ft_putchar('\n');
		ft_putchar('\n');
		ft_putendl("printf :");
		printf(argv[1], argv[2], argv[3]);
	}
	if (argc == 5)
	{
		ft_putendl("ft_printf :");
		ft_printf(argv[1], argv[2], argv[3], argv[4]);
		ft_putchar('\n');
		ft_putchar('\n');
		ft_putendl("printf :");
		printf(argv[1], argv[2], argv[3], argv[4]);
	}
	if (argc == 6)
	{
		ft_putendl("ft_printf :");
		ft_printf(argv[1], argv[2], argv[3], argv[4], argv[5]);
		ft_putchar('\n');
		ft_putchar('\n');
		ft_putendl("printf :");
		printf(argv[1], argv[2], argv[3], argv[4], argv[5]);
	}
	if (argc == 7)
	{
		ft_putendl("ft_printf :");
		ft_printf(argv[1], argv[2], argv[3], argv[4], argv[5], argv[5]);
		ft_putchar('\n');
		ft_putchar('\n');
		ft_putendl("printf :");
		printf(argv[1], argv[2], argv[3], argv[4], argv[5], argv[5]);
	}
	if (argc > 7 )
	{
		ft_printf("Gestion de la conversion %%i, %%d et le cas %% : \n\n");
		ft_printf("ft_printf(\"Mettre un nombre d'argument inferieure a %%i (actuel = %%d).\\n\",7, argc - 1);\n");
		ft_printf("Mettre un nombre d'argument inferieure a %i (actuel = %d).\n",7, argc - 1);
	}
	return (0);
}
