/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimon <nsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 13:37:47 by nsimon            #+#    #+#             */
/*   Updated: 2020/02/06 16:29:31 by nsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_int(int val, t_fill *fill)
{
	char	*value;
	int 	i;

	value = ft_itoa(val);
	i = val < 0 ? 1 : 0;
	ft_print_flag_i(ft_strlen(value), fill, val);
	while (value[i] && val != 0)
		ft_putchar_count(value[i++], fill);
	val == 0 && fill->zero != 0 ? ft_putchar_count('0', fill) : 0;
	if (fill->align == '-' && fill->space > 0)
		while (fill->space-- > 0)
			ft_putchar_count(' ', fill);
	ft_clear_struct(fill);
	free(value);
}

void	ft_printf_char(char c, t_fill *fill)
{
	int i;

	i = 1;
	if (fill->align != '-' && i < fill->space)
		while (i++ < fill->space)
			ft_putchar_count(' ', fill);
	ft_putchar_count(c, fill);
	if (fill ->align == '-' && i < fill->space)
		while (i++ < fill->space)
			ft_putchar_count(' ', fill);
	ft_clear_struct(fill);
}

void	ft_printf_str(const char *str, t_fill * fill)
{
	char 	*cpy_str;
	int		i;

	i = 0;
	cpy_str = str ? ft_strdup(str) : ft_strdup("(null)");
	if (fill->zero < (int)ft_strlen(cpy_str) && fill->zero >= 0)
		cpy_str[fill->zero] = '\0';
	if (fill->align != '-' && fill->align != '0')
		while (i++ < fill->space - (int)ft_strlen(cpy_str))
			ft_putchar_count(' ', fill);
	if (fill->align == '0')
		while (i++ < fill->space - (int)ft_strlen(cpy_str))
			ft_putchar_count('0', fill);
	ft_putstr_count(cpy_str, fill);
	if (fill->align == '-')
		while (i++ < fill->space - (int)ft_strlen(cpy_str))
			ft_putchar_count(' ', fill);
	free(cpy_str);
	ft_clear_struct(fill);
}

void	ft_hexa(long value, t_fill *fill, char charset)
{
	char	*str;

	str = convert_hex(value, charset);
	ft_print_flag_x(ft_strlen(str), fill, value);
	if (fill->align == '-' && fill->space > 0)
		while (fill->space-- > 0)
			ft_putchar_count(' ', fill);
	ft_clear_struct(fill);
	ft_putstr_count(str, fill);
	free(str);
}

void	ft_pourcent(t_fill *fill)
{
	int i;

	i = 1;
	if (fill->align != '-' && i < fill->space && fill->align != '0')
		while (i++ < fill->space)
			ft_putchar_count(' ', fill);
	if (fill->align == '0' && i< fill->space)
		while (i++ < fill->space)
			ft_putchar_count('0', fill);
	ft_putchar_count('%', fill);
	if (fill ->align == '-' && i < fill->space)
		while (i++ < fill->space)
			ft_putchar_count(' ', fill);
	ft_clear_struct(fill);
}