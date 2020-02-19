/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimon <nsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 17:32:25 by nsimon            #+#    #+#             */
/*   Updated: 2020/02/19 00:19:24 by nsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		is_flag(const char format)
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
	if (format == '%')
		return (8);
	return (0);
}

int		ft_getprec(const char *s, t_fill *fill, va_list *args)
{
	int	i;
	int res;

	i = 0;
	while (ft_isdigit(s[++i]) || s[i] == '.' || s[i] == '-' || s[i] == '*')
	{
		if (s[i] == '-' || (s[i] == '0' && s[i - 1] == '%'))
			fill->align = s[i];
		if (!ft_isdigit(s[i - 1]) && s[i - 1] != '.' && ft_isdigit(s[i]))
			fill->space = ft_atoi(&s[i]);
		if (!ft_isdigit(s[i - 1]) && s[i - 1] == '.' && ft_isdigit(s[i]))
			fill->zero = ft_atoi(&s[i]);
		if (s[i] == '*' && s[i - 1] != '.')
		{
			if ((res = va_arg(*args, int)) < 0)
				fill->align = '-';
			res < 0 ? res *= -1 : res;
			fill->space = res;
		}
		(s[i] == '*' && s[i - 1] == '.') ? fill->zero = va_arg(*args, int) : *s;
		if (s[i] == '.' && !ft_isdigit(s[i + 1]) && s[i + 1] != '*')
			fill->zero = 0;
	}
	return (i);
}

void	ft_select(int val, va_list *args, t_fill *fill, int *tab)
{
	val == 1 ? ft_printf_char(va_arg(*args, int), fill) : 0;
	val == 2 ? ft_printf_str(va_arg(*args, char *), fill) : 0;
	val == 3 ? ft_pointer(va_arg(*args, void *), fill) : 0;
	val == 4 ? ft_printf_int(va_arg(*args, int), fill) : 0;
	val == 5 ? ft_uint(va_arg(*args, unsigned int), fill) : 0;
	val == 6 ? ft_hexa(va_arg(*args, unsigned int), fill, 87) : 0;
	val == 7 ? ft_hexa(va_arg(*args, unsigned int), fill, 55) : 0;
	val == 8 ? ft_pourcent(fill) : 0;
	tab[0] += tab[1] + 1;
}

int		ft_printf(const char *format, ...)
{
	int			tb[3];
	va_list		args;
	t_fill		fill;

	va_start(args, format);
	tb[0] = 0;
	fill.align = 0;
	fill.zero = -1;
	fill.space = -1;
	fill.printed = 0;
	while (format[tb[0]])
	{
		tb[1] = 0;
		if (format[tb[0]] == '%')
			tb[1] = ft_getprec(&format[tb[0]], &fill, &args);
		if (format[tb[0]] == '%' && (tb[2] = is_flag(format[tb[0] + tb[1]])))
			ft_select(tb[2], &args, &fill, tb);
		if ((format[tb[0]] != '%' || is_flag(format[tb[0] + 1]) == 0)
				&& format[tb[0]] && tb[2] == 0)
			format[tb[0]] != '%' ? ftpcharcnt(format[tb[0]++], &fill) : tb[0]++;
		tb[2] = 0;
	}
	va_end(args);
	return (fill.printed);
}
