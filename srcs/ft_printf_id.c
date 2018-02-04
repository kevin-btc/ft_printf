#include "ft_printf.h"

int        ft_printf_id(char **new_str, int i, va_list vl, char *opt)
{
	char    *tmp;
	void    *tmp2;

	tmp = *new_str;
	if (ft_strchr(opt, 'h') && ft_strchr(opt + 1, 'h'))
		tmp2 = ft_itoa((char)va_arg(vl, int));
	else if (ft_strchr(opt, 'l') && ft_strchr(opt + 1, 'l'))
		tmp2 = ft_itoa(va_arg(vl, long long int));
	else if (ft_strchr(opt, 'h'))
		tmp2 = ft_itoa((short int)va_arg(vl, int));
	else if (ft_strchr(opt, 'l'))
		tmp2 = ft_itoa(va_arg(vl, long int));
	else if (ft_strchr(opt, 'j'))
		tmp2 = ft_itoa(va_arg(vl, intmax_t));
	else if (ft_strchr(opt, 'z'))
		tmp2 = ft_itoa(va_arg(vl, size_t));
	else
		tmp2 = ft_itoa(va_arg(vl, int));
	ft_add_space((char **)&tmp2, opt);
	*new_str = ft_strjoin(ft_strsub(*new_str, 0, i), tmp2);
	ft_strdel(&tmp);
	return (ft_strlen(tmp2));
}