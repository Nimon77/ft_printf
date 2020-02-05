/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimon <nsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 17:09:35 by nsimon            #+#    #+#             */
/*   Updated: 2020/02/05 19:01:57 by nsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include "../libft/libft.h"
#include <stdio.h>

#include <stdarg.h>

typedef struct	s_fill
{
	char 		align;
	int			printed;
	int			space;
	int			zero;
}				t_fill;

void	ft_clear_struct(t_fill *fill);
void	ft_print_flag_i(int size, t_fill *fill, int val);
void	ft_putchar_count(char c, t_fill *fill);
void	ft_putstr_count(char *str, t_fill *fill);
void	ft_printf_int(int value, t_fill *fill);
void	ft_printf_char(char c, t_fill *fill);
void	ft_printf_str(const char *str, t_fill *fill);
char	*convert_hex(unsigned long value, char charset);
void	ft_pointer(void *ptr, t_fill *fill);
void	ft_hexa(int value, t_fill *fill, char charset);
void	ft_uint(unsigned int val, t_fill *fill);
int		ft_printf(const char *, ...);

#endif //LIBFTPRINTF_H
