/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimon <nsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 21:34:23 by nsimon            #+#    #+#             */
/*   Updated: 2020/01/04 02:27:44 by nsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char *ft_reverse(char *conv)
{
	int		i;
	int		size;
	char	*tmp;

	size = (int)ft_strlen(conv) - 1;
	i = 0;
	tmp = (char *)malloc(sizeof(tmp) * size + 1);
	while (size >= 0)
		tmp[i++] = conv[size--];
	free(conv);
	return (tmp);
}

static char	*convert_hex(long value)
{
	int		val;
	char	actuel[2];
	char	*conv;
	char	*tmp;

	conv = (char *)malloc(sizeof(conv));
	conv[0] = '\0';
	actuel[1] = '\0';
	while (value > 0)
	{
		val = (int)(value % 16);
		actuel[0] = (char)(val > 9 ? (val + 87) : (val + '0'));
		tmp = conv;
		conv = ft_strjoin(conv, actuel);
		if (tmp)
			free(tmp);
		value /= 16;
	}
	return (ft_reverse(conv));
}

void	ft_pointer(void *ptr, t_fill_list *fill)
{
	long test;
	char *conv;

	if (ptr)
	{
		test = (uintptr_t) ptr;
		ft_putstr_fd("0x", 1);
		conv = convert_hex(test);
		ft_putstr_fd(conv, 1);
		free(conv);
	}
	else
		ft_putstr_fd("(nil)", 1);
	fill->space = 0;
	fill->zero = 0;
}