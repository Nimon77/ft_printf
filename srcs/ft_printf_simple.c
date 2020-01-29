/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimon <nsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 13:37:47 by nsimon            #+#    #+#             */
/*   Updated: 2020/01/29 16:56:39 by nsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_int(int val, t_fill *fill)
{
	size_t	i;
	int		j;
	char	*value;

	value = ft_itoa(val);
	i = ft_strlen(value);
	j = (int)(fill->zero - ft_strlen(value));
	if (fill->align == '\0')
		while (i++ < fill->space - (j < 0 ? 0 : j))
			ft_putchar_count(' ', fill);
	if (fill->align == '0')
		while (i++ < fill->space - (j < 0 ? 0 : j))
			ft_putchar_count('0', fill);
	i = 0;
	while (i++ < (size_t)(j < 0 ? 0 : j))
		ft_putchar_count('0', fill);
	ft_putstr_count(value, fill);
	i += ft_strlen(value) - 1;
	if (fill->align == '-')
		while (i++ < fill->space)
			ft_putchar_count(' ', fill);
	fill->space = 0;
	fill->zero = 0;
	free(value);
}

void	ft_printf_char(char c, t_fill *fill)
{
	size_t i;

	i = 1;
	if (fill->align != '-' && i < fill->space)
		while (i++ < fill->space)
			ft_putchar_count(' ', fill);
	ft_putchar_count(c, fill);
	if (fill ->align == '-' && i < fill->space)
		while (i++ < fill->space)
			ft_putchar_count(' ', fill);
	fill->space = 0;
	fill->space = 0;
}

void	ft_printf_str(const char *str, t_fill * fill)
{
	char 	*cpy_str;
	size_t	i;

	i = 0;
	cpy_str = ft_strdup(str);
	if (fill->zero < ft_strlen(cpy_str))
		cpy_str[fill->zero] = '\0';
	if (fill->align != '-')
		while (i++ < fill->space - fill->zero)
			ft_putchar_count(' ', fill);
	ft_putstr_count(cpy_str, fill);
	if (fill->align == '-')
		while (i++ < fill->space - fill->zero)
			ft_putchar_count(' ', fill);
	free(cpy_str);
	fill->space = 0;
	fill->zero = 0;
}

void	ft_hexa(int value, t_fill *fill, char charset)
{
	size_t	i;
	char	*str;

	str = convert_hex(value, charset);
	if ((i = ft_strlen(str) + (fill->zero - ft_strlen(str))) < fill->space)
		while (i++ < fill->space)
			ft_putchar_count(' ', fill);
	if ((i = ft_strlen(str)) < fill->zero)
		while (i++ < fill->zero)
			ft_putchar_count('0', fill);
	fill->space = 0;
	fill->zero = 0;
	ft_putstr_count(str, fill);
	free(str);
}