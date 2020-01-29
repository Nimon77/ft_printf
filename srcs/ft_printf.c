/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimon <nsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 17:32:25 by nsimon            #+#    #+#             */
/*   Updated: 2020/01/29 18:10:44 by nsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	is_flag(const char format)
{
	if (format == 'c')
		return (1);
	if (format == 's')
		return (2);
	if (format == 'p')
		return (3);
	if (format == 'd')
		return (4);
	if (format == 'i')
		return (4);
	if (format == 'u')
		return (5);
	if (format == 'x')
		return (6);
	if (format == 'X')
		return (7);
	return (0);
}

int	ft_getprec(const char *str, t_fill *fill)
{
	int	i;

	i = 1;
	while (ft_isdigit(str[i]) || str[i] == '.' || str[i] == '-')
	{
		if (str[i] == '-' || (str[i] == '0' && str[i - 1] == '%'))
			fill->align = str[i];
		if (!ft_isdigit(str[i - 1]) && str[i - 1] != '.')
			fill->space = ft_atoi(&str[i]);
		if (!ft_isdigit(str[i - 1]) && str[i - 1] == '.')
			fill->zero = ft_atoi(&str[i]);
		if (str[i] == '.' && fill->align == '0')
			fill->align = '\0';
		i++;
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int			i;
	int 		j;
	int			val;
	va_list		args;
	t_fill	fill;

	va_start(args, format);
	i = 0;
	fill.zero = 0;
	fill.space = 0;
	fill.printed = 0;
	while (format[i])
	{
		j = 0;
		if (format[i] == '%')
			j = ft_getprec(&format[i], &fill);
		if (format[i] == '%' && (val = is_flag(format[i + j])))
		{
			val == 1 ? ft_printf_char(va_arg(args, int), &fill) : val;
			val == 2 ? ft_printf_str(va_arg(args, char *), &fill) : val;
			val == 3 ? ft_pointer(va_arg(args, void *), &fill) : val;
			val == 4 ? ft_printf_int(va_arg(args, int), &fill) : val;
			val == 5 ? ft_uint(va_arg(args, unsigned int), &fill) : val;
			val == 6 ? ft_hexa(va_arg(args, int), &fill, 87) : val;
			val == 7 ? ft_hexa(va_arg(args, int), &fill, 55) : val;
			i += j + 1;
		}
		if (format[i] != '%' && format[i])
			ft_putchar_count(format[i++], &fill);
	}
	va_end(args);
	return (fill.printed);
}
