/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimon <nsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 17:09:35 by nsimon            #+#    #+#             */
/*   Updated: 2020/01/24 15:05:01 by nsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include "../libft/libft.h"
#include <stdio.h>

#include <stdarg.h>

typedef struct	s_fill_list
{
	char 		align;
	size_t		space;
	size_t		zero;
}				t_fill_list;

void	ft_printf_int(int value, t_fill_list *fill);
void	ft_printf_char(char c, t_fill_list *fill);
void	ft_printf_str(const char *str, t_fill_list *fill);
char	*convert_hex(unsigned long value, char charset);
void	ft_pointer(void *ptr, t_fill_list *fill);
void	ft_hexa(int value, t_fill_list *fill, char charset);
void	ft_uint(unsigned int val, t_fill_list *fill);
int		ft_printf(const char *, ...);

#endif //LIBFTPRINTF_H
