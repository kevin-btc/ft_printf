
#include "ft_printf.h"

int        ft_printf_pct(char **new_str, char *opt, int i)
{
	char    *tmp2;
	int	j;
	int	len;

	j = 0;
	len = 0;
	tmp2 = ft_strnew(0);
	while (new_str[0][i + j + 1] != '%')
	{
		if (new_str[0][i + j + 1] != ' ')
			break;
		j++;
	}
	if (ft_strchr(opt, '-') == NULL && new_str[0][i + j + 1] != '%')
	{
		ft_add_space(&tmp2, opt);
		tmp2 = ft_strjoin(tmp2, "%");
		len = ft_strlen(tmp2);
		tmp2 = ft_strjoin(ft_strsub(*new_str, 0 , i),ft_strdup(tmp2 + 1));
	}
	else if (ft_strchr(opt, '-') != NULL)
	{
		ft_add_space(&tmp2, opt);
		tmp2 = ft_strjoin("%", tmp2 + 1);
		len = ft_strlen(tmp2);
		tmp2 = ft_strjoin(ft_strsub(*new_str, 0 , i),ft_strdup(tmp2));
	}
	else
	{
		tmp2 = ft_strdup("%");
		len = ft_strlen(tmp2);
		tmp2 = ft_strjoin(ft_strsub(*new_str, 0 , i),ft_strdup(tmp2));
	}
	*new_str = ft_strdup(tmp2);
	return (len);
}
