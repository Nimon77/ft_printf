/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimon <nsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 13:37:47 by nsimon            #+#    #+#             */
/*   Updated: 2020/01/28 16:11:19 by nsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_int(int val, t_fill_list *fill)
{
	size_t	i;
	int		j;
	char	*value;

	value = ft_itoa(val);
	i = ft_strlen(value);
	j = (int)(fill->zero - ft_strlen(value));
	if (fill->align != '-')
		while (i++ < fill->space - (j < 0 ? 0 : j))
		{
			ft_putchar_fd(' ', 1);
			fill->printed++;
		}
	i = 0;
	while (i++ < (size_t)(j < 0 ? 0 : j))
		ft_putchar_fd('0', 1);
	fill->printed += i;
	ft_putstr_fd(value, 1);
	fill->printed += ft_strlen(value);
	i += ft_strlen(value) - 1;
	if (fill->align == '-')
		while (i++ < fill->space)
		{
			ft_putchar_fd(' ', 1);
			fill->printed++;
		}
	fill->space = 0;
	fill->zero = 0;
	free(value);
}

void	ft_printf_char(char c, t_fill_list *fill)
{
	size_t	i;

	i = 1;
	if (fill->align != '-' && i < fill->space)
		while (i++ < fill->space)
			ft_putchar_fd(' ', 1);
	ft_putchar_fd(c, 1);
	if (fill ->align == '-' && i < fill->space)
		while (i++ < fill->space)
			ft_putchar_fd(' ', 1);
	fill->space = 0;
	fill->space = 0;
}

void	ft_printf_str(const char *str, t_fill_list * fill)
{
	char 	*cpy_str;
	size_t	i;

	i = 0;
	cpy_str = ft_strdup(str);
	if (fill->zero < ft_strlen(cpy_str))
		cpy_str[fill->zero] = '\0';
	if (fill->align != '-')
		while (i++ < fill->space - fill->zero)
			ft_putchar_fd(' ', 1);
	ft_putstr_fd(cpy_str, 1);
	if (fill->align == '-')
		while (i++ < fill->space - fill->zero)
			ft_putchar_fd(' ', 1);
	free(cpy_str);
	fill->space = 0;
	fill->zero = 0;
}

void	ft_hexa(int value, t_fill_list *fill, char charset)
{
	size_t	i;
	char	*str;

	str = convert_hex(value, charset);
	if ((i = ft_strlen(str) + (fill->zero - ft_strlen(str))) < fill->space)
		while (i++ < fill->space)
			ft_putchar_fd(' ', 1);
	if ((i = ft_strlen(str)) < fill->zero)
		while (i++ < fill->zero)
			ft_putchar_fd('0', 1);
	fill->space = 0;
	fill->zero = 0;
	ft_putstr_fd(str, 1);
	free(str);
}