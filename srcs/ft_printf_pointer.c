/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimon <nsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 21:34:23 by nsimon            #+#    #+#             */
/*   Updated: 2020/01/03 22:55:52 by nsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <inttypes.h>

char	*convert_hex(long value)
{
	int		i;
	int		val;
	char	actuel[2];
	char	*conv;

	i = 0;
	conv = NULL;
	actuel[1] = '\0';
	while (value > 0)
	{
		val = (int)(value % 16);
		actuel[0] = val + '0';
		conv = ft_strjoin(conv, actuel)
	}
}

void	ft_pointer(void *ptr, t_fill_list *fill)
{
	long test = (uintptr_t)ptr;

	ft_putstr_fd("0x", 1);
	printf("\npointeur l : %lld\n pointeur p : %p", test, ptr);
	fill->space = 0;
	fill->zero = 0;
}