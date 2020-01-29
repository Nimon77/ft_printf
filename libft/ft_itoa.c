/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimon <nsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:05:42 by nsimon            #+#    #+#             */
/*   Updated: 2020/01/29 17:44:02 by nsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char		*ft_itoa(int n)
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
		if (n / 10 == 0 && n < 0)
			tmp[i++] = '-';
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
