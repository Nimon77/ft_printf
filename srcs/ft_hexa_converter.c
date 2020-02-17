/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_converter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimon <nsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 02:40:21 by nsimon            #+#    #+#             */
/*   Updated: 2020/02/17 15:21:15 by nsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_reverse(char *conv)
{
	int		i;
	int		size;
	char	*tmp;

	size = (int)ft_strlen(conv) - 1;
	i = 0;
	if (!(tmp = (char *)malloc(sizeof(tmp) * size + 1)))
		return (NULL);
	while (size >= 0)
		tmp[i++] = conv[size--];
	tmp[i] = '\0';
	free(conv);
	return (tmp);
}

char		*convert_hex(unsigned long value, char charset)
{
	int		val;
	char	actuel[2];
	char	*conv;
	char	*tmp;

	conv = ft_strdup("");
	actuel[1] = '\0';
	while (value > 0)
	{
		val = (int)(value % 16);
		actuel[0] = (char)(val > 9 ? (val + charset) : (val + '0'));
		tmp = conv;
		conv = ft_strjoin(conv, actuel);
		free(tmp);
		value /= 16;
	}
	if (ft_strlen(conv) == 0)
	{
		actuel[0] = '0';
		tmp = conv;
		conv = ft_strjoin(conv, actuel);
		free(tmp);
	}
	return (ft_reverse(conv));
}
