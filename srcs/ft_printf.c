/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimon <nsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 17:32:25 by nsimon            #+#    #+#             */
/*   Updated: 2019/12/19 15:57:47 by nsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

int	is_flag(const char *format)
{
	if (format[0] == '%')
	{
		if (format[1] == 'c')
			return (1);
		if (format[1] == 's')
			return (2);
		if (format[1] == 'p')
			return (3);
		if (format[1] == 'd')
			return (4);
		if (format[1] == 'i')
			return (4);
		if (format[1] == 'u')
			return (5);
		if (format[1] == 'x')
			return (6);
		if (format[1] == 'X')
			return (7);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int			i;
	int			value;
	va_list		args;

	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if ((value = is_flag(&format[i])))
		{
			value == 1 ? ft_printf_char(va_arg(args, int)) : value;
			value == 2 ? ft_printf_str(va_arg(args, char *)) : value;
			value == 4 ? ft_printf_int(va_arg(args, int)) : value;
			value == 5 ? ft_printf_uint(va_arg(args, unsigned int)) : value;
			i += 2;
		}
		if (!is_flag(&format[i]))
			ft_putchar_fd(format[i++], 1);
	}
	va_end(args);
	return (0);
}
