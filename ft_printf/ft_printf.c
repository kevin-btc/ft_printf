#include "stdarg.h"
#include "stdio.h"
#include "libft/libft.h"


int ft_printf(const char *format, ...)
{
	va_list vl;
	int	suivant;
	int i;
	char *new_str;
	char *tmp;


	new_str = ft_strdup(format);
	i = 0 ;
	suivant = 0;
	va_start(vl, format);
	//printf("--->>>%s\n", va_arg(vl, char *));
	while (new_str[i])
	{
		if (new_str[i] == '%')
		{
			if (new_str[i + 1] == 's')
			{
				tmp = ft_strsub(new_str , i + 2, ft_strlen(new_str));
				new_str = ft_strjoin(ft_strsub(new_str,0 , i), va_arg(vl, char *));
			}
			if (new_str[i + 1] == 'd')
			{
				tmp = ft_strsub(new_str , i + 2, ft_strlen(new_str));
				new_str = ft_strjoin(ft_strsub(new_str,0 , i), ft_itoa(va_arg(vl, int)));
			}
			new_str = ft_strjoin(new_str, tmp);
			//printf("-----> len = %d i = %d ,%s\n", ft_strlen(format), i + 2, ft_strsub(format , i + 2, ft_strlen(format)));
		}
		i++;
	}
	ft_putstr(new_str);
	va_end(vl);
	return 1;
}
int ft_return1(void)
{
	return (1);
}


int main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("avant : tu t'apelles |%%s|\n");
		ft_printf("apres : tu t'apelles |%s|", argv[argc - 1]);
	}
	if (argc == 3)
	{
		printf("avant : tu t'apelles |%%s| et tu as |%%d| ans\n");
		ft_printf("apres : tu t'apelles |%s| et tu as |%d| ans", argv[argc - 2], ft_atoi(argv[argc - 1]));
	}
	return (0);
}