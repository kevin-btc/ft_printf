#include "stdarg.h"
#include "stdio.h"
#include "libft/libft.h"


int ft_printf(const char *format, ...)
{
	va_list vl;
	int i;
	char *new_str;
	char *tmp;
	char *c_to_s;


	new_str = ft_strdup(format);
	i = 0 ;
	c_to_s = ft_strnew(1);
	va_start(vl, format);
	while (new_str[i])
	{
		if (new_str[i] == '%')
		{
			if (new_str[i + 1] == 's')
			{
				tmp = ft_strsub(new_str , i + 2, ft_strlen(new_str));
				new_str = ft_strjoin(ft_strsub(new_str,0 , i), va_arg(vl, char *));
			}
			if (new_str[i + 1] == 'c')
			{
				c_to_s[0] = va_arg(vl, int);
				tmp = ft_strsub(new_str , i + 2, ft_strlen(new_str));
				new_str = ft_strjoin(ft_strsub(new_str,0 , i), c_to_s);
			}
			if (new_str[i + 1] == 'd'|| new_str[i + 1] == 'i')
			{
				tmp = ft_strsub(new_str , i + 2, ft_strlen(new_str));
				new_str = ft_strjoin(ft_strsub(new_str,0 , i), ft_itoa(va_arg(vl, int)));
			}
			if (new_str[i + 1] == '%')
			{
				tmp = ft_strsub(new_str , i + 2, ft_strlen(new_str));
				new_str = ft_strjoin(ft_strsub(new_str,0 , i), "%");
			}
			new_str = ft_strjoin(new_str, tmp);
		}
		i++;
	}
	va_end(vl);
	ft_putstr(new_str);
	return (ft_strlen(new_str));
}
