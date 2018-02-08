
#include "ft_printf.h"

char    *ft_count_caract(char *opt, int nbr_letters_add)
{
	int        i;
	char    *space;
	int        nbr;
	char    c;

	i = 0;
	c = ' ';
	while (opt[i])
	{
		if (ft_strchr(opt, '-') == NULL && opt[i] == '0')
		{
			c = '0';
		}
		if (ft_isdigit(opt[i]) && opt[i] != '0')
		{
			if ((nbr = ft_atoi(&opt[i]) - nbr_letters_add) < 1)
				return (NULL);
			if (ft_strchr(opt, '+') != NULL && ft_strchr(opt, '-') != NULL && opt[0] == '0')
				nbr--;
			else if (ft_strchr(opt, '+') != NULL && opt[0] == '0')
				nbr--;
			space = ft_strnew(nbr);
			ft_memset(space, c, nbr);
			return (space);
		}
		i++;
	}
	return (NULL);
}

void    ft_add_space(char **tmp2, char *opt)
{
	char *str_added;
	str_added = ft_count_caract(opt, ft_strlen(*tmp2));
	if (str_added != NULL)
	{
		if (ft_strchr(opt, '-'))
		{
			*tmp2 = ft_strjoin(*tmp2, str_added);
		}
		else
			*tmp2 = ft_strjoin(str_added, *tmp2);
	}
}
/*
void	ft_add_plus(char *opt, char **tmp2)
{
	if (*tmp2[0] != '-' && ft_strchr(opt, '+') != NULL)
	{
		ft_add_space((char **)&(*tmp2), opt);
		*tmp2 = ft_strjoin("+", *tmp2);
	}
	else
		ft_add_space((char **)&(*tmp2), opt);
}*/
