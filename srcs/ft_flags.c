/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimon <nsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 14:52:12 by nsimon            #+#    #+#             */
/*   Updated: 2020/02/06 15:52:40 by nsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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

void	ft_print_flag_u(int size, t_fill *fill, unsigned int val)
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

void	ft_print_flag_x(int size, t_fill *fill, long val)
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
