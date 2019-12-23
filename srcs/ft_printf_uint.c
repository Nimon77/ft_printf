/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimon <nsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:47:30 by nsimon            #+#    #+#             */
/*   Updated: 2019/12/23 18:17:03 by nsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/libftprintf.h"

static void	ft_strrcpy(char *value, char *tmp)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen(tmp) - 1;
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
		if ((tmp[i] = (n % 10)) < 0)
			tmp[i] = -tmp[i] + '0';
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

void	ft_uint(unsigned int n, t_fill_list *fill)
{
	size_t			i;
	char			*value;

	value = ft_itoa_unsigned(n);
	if ((i = ft_strlen(value) + (fill->zero - ft_strlen(value))) < fill->space)
		while (i++ < fill->space)
			ft_putchar_fd(' ', 1);
	if ((i = ft_strlen(value)) < fill->zero)
		while (i++ < fill->zero)
			ft_putchar_fd('0', 1);
	fill->space = 0;
	fill->zero = 0;
	ft_putstr_fd(value, 1);
	free(value);
}
