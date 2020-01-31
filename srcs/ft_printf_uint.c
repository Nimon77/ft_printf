/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimon <nsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:47:30 by nsimon            #+#    #+#             */
/*   Updated: 2020/01/31 17:26:22 by nsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

static void	ft_strrcpy(char *value, char *tmp)
{
	int	i;
	int	j;

	j = 0;
	i = (int)ft_strlen(tmp) - 1;
	while (i >= 0)
		value[j++] = tmp[i--];
	value[j] = '\0';
}

static char	*ft_itoa_unsigned(unsigned int n)
{
	int		i;
	char	tmp[12];
	char	*value;

	i = 0;
	while (n != 0)
	{
		if ((tmp[i] = (char)(n % 10)) < 0)
			tmp[i] = (char)(-tmp[i] + '0');
		else
			tmp[i] += '0';
		i++;
		n /= 10;
	}
	if (i == 0)
		tmp[i++] = '0';
	tmp[i] = '\0';
	if ((value = malloc(sizeof(*value) * (ft_strlen(tmp) + 1))) == NULL)
		return (NULL);
	ft_strrcpy(value, tmp);
	return (value);
}

void	ft_uint(unsigned int n, t_fill *fill)
{
	int				i;
	char			*value;

	value = ft_itoa_unsigned(n);
	if ((i = ft_strlen(value) + (fill->zero - ft_strlen(value))) < fill->space)
		while (i++ < fill->space)
			ft_putchar_fd(' ', 1);
	if ((i = ft_strlen(value)) < fill->zero)
		while (i++ < fill->zero)
			ft_putchar_fd('0', 1);
	fill->space = -1;
	fill->zero = -1;
	ft_putstr_fd(value, 1);
	free(value);
}
