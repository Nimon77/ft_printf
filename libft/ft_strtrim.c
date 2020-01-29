/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimon <nsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:29:43 by nsimon            #+#    #+#             */
/*   Updated: 2020/01/29 17:44:02 by nsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in(const char c, const char *to_find)
{
	int	i;

	i = 0;
	while (to_find[i] != '\0')
		if (to_find[i++] == c)
			return (1);
	return (0);
}

char		*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	len;
	char	*ptr;

	start = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (is_in(s1[start], set))
		start++;
	len = ft_strlen(s1);
	if (start == len)
		return (ft_strdup(""));
	while (is_in(s1[len - 1], set))
		len--;
	len -= start - 1;
	if ((ptr = malloc(sizeof(*ptr) * len)) == NULL)
		return (NULL);
	ft_strlcpy(ptr, &s1[start], len);
	return (ptr);
}
