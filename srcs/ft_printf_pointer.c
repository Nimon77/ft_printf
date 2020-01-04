/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimon <nsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 21:34:23 by nsimon            #+#    #+#             */
/*   Updated: 2020/01/04 02:44:44 by nsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_pointer(void *ptr, t_fill_list *fill)
{
	long test;
	char *conv;

	if (ptr)
	{
		test = (uintptr_t)ptr;
		ft_putstr_fd("0x", 1);
		conv = convert_hex(test, 87);
		ft_putstr_fd(conv, 1);
		free(conv);
	}
	else
		ft_putstr_fd("(nil)", 1);
	fill->space = 0;
	fill->zero = 0;
}