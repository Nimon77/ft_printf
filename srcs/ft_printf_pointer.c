/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimon <nsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 21:34:23 by nsimon            #+#    #+#             */
/*   Updated: 2020/01/24 15:24:33 by nsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_pointer(void *ptr, t_fill_list *fill)
{
	unsigned long	test;
	char			*conv;
	size_t	i;

	test = ptr ? (uintptr_t)ptr : 0;
	conv = convert_hex(test, 87);
	i = ft_strlen(conv) + 2;
	if (fill->align != '-')
		while (i++ < fill->space)
			ft_putchar_fd(' ', 1);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(conv, 1);
	if (fill->align == '-')
		while (i++ < fill->space)
			ft_putchar_fd(' ', 1);
	free(conv);
	fill->space = 0;
	fill->zero = 0;
}