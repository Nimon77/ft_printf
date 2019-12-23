/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimon <nsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 17:32:25 by nsimon            #+#    #+#             */
/*   Updated: 2019/12/23 18:15:14 by nsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

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

int	ft_printf(const char *format, ...)
{
	int			i;
	int 		j;
	int			val;
	va_list		args;
	t_fill_list	fill;

	va_start(args, format);
	i = 0;
	fill.zero = 0;
	fill.space = 0;
	while (format[i])
	{
		j = 1;
		if (format[i] == '%')
			while (ft_isdigit(format[i + j]) || format[i + j] == '.')
			{
				if (!ft_isdigit(format[i + j - 1]) && format[i + j - 1] != '.')
					fill.space = ft_atoi(&format[i + j]);
				if (!ft_isdigit(format[i + j - 1]) && format[i + j - 1] == '.')
					fill.zero = ft_atoi(&format[i + j]);
				j++;
			}
		if (format[i] == '%' && (val = is_flag(format[i + j])))
		{
			val == 1 ? ft_printf_char(va_arg(args, int), &fill) : val;
			val == 2 ? ft_printf_str(va_arg(args, char *)) : val;
			val == 4 ? ft_printf_int(va_arg(args, int), &fill) : val;
			val == 5 ? ft_uint(va_arg(args, unsigned int), &fill) : val;
			i += j + 1;
		}
		if (format[i] != '%')
			ft_putchar_fd(format[i++], 1);
	}
	va_end(args);
	return (0);
}
