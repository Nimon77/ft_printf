/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimon <nsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 21:34:23 by nsimon            #+#    #+#             */
/*   Updated: 2020/01/03 21:59:30 by nsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <inttypes.h>

void	ft_pointer(void *ptr, t_fill_list *fill)
{
	long long test = (uintptr_t)ptr;

	ft_putstr_fd("0x", 1);
	printf("\npointeur l : %lld\n pointeur p : %p", test, ptr);
	fill->space = 0;
	fill->zero = 0;
}