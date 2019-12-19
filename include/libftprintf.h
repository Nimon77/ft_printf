/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimon <nsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 17:09:35 by nsimon            #+#    #+#             */
/*   Updated: 2019/12/18 14:07:44 by nsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include "../libft/libft.h"
#include <stdio.h>

#include <stdarg.h>

void	ft_printf_int(int value);
void	ft_printf_char(char c);
void	ft_printf_str(char *str);
void	ft_printf_uint(unsigned int value);
int		ft_printf(const char *, ...);

#endif //LIBFTPRINTF_H
