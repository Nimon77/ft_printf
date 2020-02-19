/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimon <nsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 21:34:23 by nsimon            #+#    #+#             */
/*   Updated: 2020/02/19 00:32:46 by nsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_pointer(void *ptr, t_fill *fill)
{
	unsigned long	test;
	char			*conv;
	int				i;

	test = ptr ? (uintptr_t)ptr : 0;
	conv = fill->zero == 0 && test == 0 ? ft_strdup("") : convert_hex(test, 87);
	i = (int)ft_strlen(conv) + 2;
	if (fill->align != '-' && fill->align != '0')
		while (i++ < fill->space)
			ftpcharcnt(' ', fill);
	ft_putstr_count("0x", fill);
	if (fill->align == '0')
		while (i++ < fill->space)
			ftpcharcnt('0', fill);
	if (fill->align != '-' && fill->align != '0')
		while (i++ <= fill->zero +2)
			ftpcharcnt('0', fill);
	ft_putstr_count(conv, fill);
	if (fill->align == '-')
		while (i++ < fill->space)
			ftpcharcnt(' ', fill);
	free(conv);
	ft_clear_struct(fill);
}
