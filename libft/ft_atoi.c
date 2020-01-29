/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimon <nsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:10:46 by nsimon            #+#    #+#             */
/*   Updated: 2020/01/29 17:44:02 by nsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
			|| c == ' ')
		return (1);
	return (0);
}

static int	get_return(unsigned long long ret, int neg, const char *str)
{
	int count;

	count = 0;
	while (*str <= '1' || *str >= '9')
		str++;
	while (ft_isdigit(*(str + count)))
		count++;
	if (count >= 19)
		return (neg == -1 ? 0 : -1);
	if (ret > 9223372036854775807)
		return (neg == -1 ? 0 : -1);
	else
		return (ret * neg);
}

int			ft_atoi(const char *str)
{
	unsigned long long	ret;
	int					len;
	int					i;
	int					neg;

	neg = 1;
	i = -1;
	len = 0;
	ret = 0;
	while (ft_isspace(*str))
		str++;
	while (str[len])
		len++;
	while (++i <= len)
	{
		if (ft_isdigit(str[i]))
			ret = (ret * 10) + (str[i] - '0');
		else if (i == 0 && (str[i] == '-' || str[i] == '+'))
			neg = str[i] == '-' ? -1 : 1;
		else
			return (ret == 0 ? 0 : get_return(ret, neg, str));
	}
	return (ret == 0 ? 0 : get_return(ret, neg, str));
}
