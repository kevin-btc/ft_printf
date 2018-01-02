#include "stdarg.h"
#include "stdio.h"
#include "libft/libft.h"


int ft_printf(const char *format, ...)
{
	va_list vl;
	int i;
	int j;
	char *new_str;
	char *tmp;
	char *c_to_s;


	new_str = ft_strdup(format);
	i = 0;
	c_to_s = ft_strnew(1);
	va_start(vl, format);
	while (new_str[i])
	{
		j = 0;
		if (new_str[i] == '%')
		{
			while (ft_isblank(new_str[i + j + 1]))
				j++;
			tmp = ft_strsub(new_str , i + j + 2, ft_strlen(new_str));
			if (new_str[i + j + 1] == 's')
				new_str = ft_strjoin(ft_strsub(new_str,0 , i), va_arg(vl, char *));
			else if (new_str[i + j + 1] == 'c')
			{
				c_to_s[0] = va_arg(vl, int);
				new_str = ft_strjoin(ft_strsub(new_str,0 , i), c_to_s);
			}
			else if (new_str[i + j + 1] == 'd'|| new_str[i + 1] == 'i')
				new_str = ft_strjoin(ft_strsub(new_str,0 , i), ft_itoa(va_arg(vl, int)));
			else if (new_str[i + j + 1] == '%')
				new_str = ft_strdup(ft_strsub(new_str,0 , i + 1));
			else
				new_str = ft_strdup(ft_strsub(new_str,0 , i));
			new_str = ft_strjoin(new_str, tmp);
		}
		i++;
	}
	va_end(vl);
	ft_putstr(new_str);
	return (ft_strlen(new_str));
}
