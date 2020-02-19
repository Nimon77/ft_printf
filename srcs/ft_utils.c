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

void	ftpcharcnt(char c, t_fill *fill)
{
	ft_putchar_fd(c, 1);
	fill->printed++;
}

void	ft_putstr_count(char *str, t_fill *fill)
{
	ft_putstr_fd(str, 1);
	fill->printed += ft_strlen(str);
}

void	ft_clear_struct(t_fill *fill)
{
	fill->align = 0;
	fill->space = -1;
	fill->zero = -1;
}
