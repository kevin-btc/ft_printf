/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 21:03:11 by kgricour          #+#    #+#             */
/*   Updated: 2018/02/02 14:39:28 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <wchar.h>

int		ft_printf(const char *format, ...);
int		ft_printf_s(char **new_str, int i, va_list vl, char *opt);
int		ft_check_valide_conv(char *s, int *j);
char    *ft_get_opt(char *s);
void    ft_add_space(char **tmp2, char *opt);

#endif
