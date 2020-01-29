/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimon <nsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:17:35 by nsimon            #+#    #+#             */
/*   Updated: 2020/01/29 17:44:02 by nsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*newstr;

	if (s == NULL)
		return (NULL);
	if ((newstr = malloc(sizeof(*newstr) * len + 1)) == NULL)
		return (NULL);
	i = 0;
	if (start < ft_strlen(s))
		while (i < len)
			newstr[i++] = s[start++];
	newstr[i] = '\0';
	return (newstr);
}
