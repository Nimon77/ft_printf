/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimon <nsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 17:09:35 by nsimon            #+#    #+#             */
/*   Updated: 2019/12/23 18:15:14 by nsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include "../libft/libft.h"
#include <stdio.h>

#include <stdarg.h>

typedef struct	s_fill_list
{
	size_t		space;
	size_t		zero;
}				t_fill_list;

void	ft_printf_int(int value, t_fill_list *fill);
void	ft_printf_char(char c, t_fill_list *fill);
void	ft_printf_str(char *str);
void	ft_pointer(void *ptr, t_fill_list *fill);
void	ft_uint(unsigned int val, t_fill_list *fill);
int		ft_printf(const char *, ...);

#endif //LIBFTPRINTF_H
