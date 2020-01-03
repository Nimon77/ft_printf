/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimon <nsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 13:37:47 by nsimon            #+#    #+#             */
/*   Updated: 2019/12/23 18:18:51 by nsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_int(int val, t_fill_list *fill)
{
	size_t	i;
	char	*value;

	value = ft_itoa(val);
	if ((i = ft_strlen(value) + (fill->zero - ft_strlen(value))) < fill->space)
		while (i++ < fill->space)
			ft_putchar_fd(' ', 1);
	if ((i = ft_strlen(value)) < fill->zero)
		while (i++ < fill->zero)
			ft_putchar_fd('0', 1);
	fill->space = 0;
	fill->zero = 0;
	ft_putstr_fd(value, 1);
	free(value);
}

void	ft_printf_char(char c, t_fill_list *fill)
{
	size_t	i;

	i = 1;
	if (i < fill->space)
		while (i++ < fill->space)
			ft_putchar_fd(' ', 1);
	fill->space = 0;
	fill->space = 0;
	ft_putchar_fd(c, 1);
}

void	ft_printf_str(char *str)
{
	ft_putstr_fd(str, 1);
}