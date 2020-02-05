/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimon <nsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:03:48 by nsimon            #+#    #+#             */
/*   Updated: 2020/02/05 19:20:35 by nsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar_count(char c, t_fill *fill)
{
	ft_putchar_fd(c, 1);
	fill->printed++;
}

void	ft_putstr_count(char *str, t_fill *fill)
{
	ft_putstr_fd(str, 1);
	fill->printed += ft_strlen(str);
}

void	ft_print_flag_i(int size, t_fill *fill, int val)
{
	int 	zero;
	int 	neg;

	neg = val < 0 ? 1 : 0;
	zero = fill->zero;
	if ((fill->space == -1 || fill->space == 0) && fill->zero == 0 && val == 0)
		return;
	if (fill->align == '0' && zero < 0)
	{
		zero = fill->space;
		zero = zero > size - neg ? zero - size : 0;
		fill->space = -1;
	}
	else if (zero != -1)
		zero = zero > size - neg ? zero - size + neg : 0;
	fill->space = fill->space > size ? fill->space - size: 0;
	fill->space = zero > 0 ? fill->space - zero : fill->space;
	fill->space = val == 0 && fill->zero == 0 ? fill->space + 1 : fill->space;
	if (fill->align != '-' && fill->space > 0)
		while (fill->space-- > 0)
			ft_putchar_count(' ', fill);
	neg == 1 ? ft_putchar_count('-', fill) : 0;
	if (zero > 0)
		while (zero-- > 0)
			ft_putchar_count('0', fill);
}

void	ft_clear_struct(t_fill *fill)
{
	fill->align = 0;
	fill->space = -1;
	fill->zero = -1;
}
