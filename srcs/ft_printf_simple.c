/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimon <nsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 13:37:47 by nsimon            #+#    #+#             */
/*   Updated: 2019/12/18 15:47:24 by nsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

void	ft_printf_int(int value)
{
	char	*val;

	val = ft_itoa(value);
	ft_putstr_fd(val, 1);
	free(val);
}

void	ft_printf_char(char c)
{
	ft_putchar_fd(c, 1);
}

void	ft_printf_str(char *str)
{
	ft_putstr_fd(str, 1);
}