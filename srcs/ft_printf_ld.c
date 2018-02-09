
#include "ft_printf.h"

int        ft_printf_ld(char **new_str, int i, va_list vl, char *opt)
{
	char    *tmp;
	void    *tmp2;
	char	*adr;

	tmp = *new_str;
	if ((adr = ft_strchr(opt, 'l')) && ft_strchr(adr + 1, 'l'))
		tmp2 = ft_itoa(va_arg(vl, unsigned long long int));
	else if (ft_strchr(opt, 'l'))
		tmp2 = ft_itoa(va_arg(vl, unsigned long int));
	else if (ft_strchr(opt, 'j'))
		tmp2 = ft_itoa(va_arg(vl, intmax_t));
	else if (ft_strchr(opt, 'z'))
		tmp2 = ft_itoa(va_arg(vl, size_t));
	else
		tmp2 = ft_itoa(va_arg(vl, unsigned long int));
	ft_add_space((char **)&tmp2, opt);
	*new_str = ft_strjoin(ft_strsub(*new_str, 0, i), tmp2);
	ft_strdel(&tmp);
	return (ft_strlen(tmp2));
}
