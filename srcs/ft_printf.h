/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 21:03:11 by kgricour          #+#    #+#             */
/*   Updated: 2018/02/07 22:21:02 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <wchar.h>
# include <stdarg.h>
# include "libft.h"
# include <inttypes.h>

int		ft_printf(const char *format, ...);
int		ft_printf_s(char **new_str, int i, va_list vl, char *opt);
int		ft_printf_id(char **new_str, int i, va_list vl, char *opt);
int		ft_printf_ld(char **new_str, int i, va_list vl, char *opt);
int		ft_printf_x(char **new_str, int i, va_list vl, char *opt);
int		ft_printf_xx(char **new_str, int i, va_list vl, char *opt);
char	*ft_count_caract(char *opt, int nbr_letters_add);
void	ft_add_space(char **tmp2, char *opt);
int		ft_printf_pct(char **new_str, char *opt, int i);
int		ft_check_valide_conv(char *s, int *j);
char	*ft_get_opt(char *s);
void    ft_add_space(char **tmp2, char *opt);
void	ft_add_plus(char *opt, char **tmp2);

#endif
