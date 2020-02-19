/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimon <nsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:47:30 by nsimon            #+#    #+#             */
/*   Updated: 2020/02/17 15:21:56 by nsimon           ###   ########.fr       */
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

void		ft_uint(unsigned int n, t_fill *fill)
{
	char			*value;

	value = ft_itoa_unsigned(n);
	ft_print_flag_u(ft_strlen(value), fill, n);
	fill->zero == 0 && n == 0 ? 0 : ft_putstr_count(value, fill);
	if (fill->align == '-' && fill->space > 0)
		while (fill->space-- > 0)
			ftpcharcnt(' ', fill);
	ft_clear_struct(fill);
	free(value);
}
