/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimon <nsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:17:18 by nsimon            #+#    #+#             */
/*   Updated: 2020/01/29 17:44:02 by nsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calc_split(const char *s, char c)
{
	int i;
	int split;

	if (!s)
		return (-1);
	if (s[0] == '\0')
		return (0);
	i = 0;
	split = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			split++;
		i++;
	}
	if (s[i - 1] != c)
		split++;
	return (split);
}

static int	calc_word(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static char	**error(char **split, int nb_split)
{
	int	i;

	i = 0;
	while (i <= nb_split)
	{
		if (split[nb_split] != NULL)
			free(split[i]);
		i++;
	}
	free(split);
	split = NULL;
	return (NULL);
}

char		**ft_split(const char *s, char c)
{
	char	**split;
	int		i;
	int		nb_split;
	int		world_len;
	int		line;

	if ((nb_split = calc_split(s, c)) == -1)
		return (NULL);
	i = 0;
	line = 0;
	if ((split = malloc(sizeof(*split) * (nb_split + 1))) == NULL)
		return (NULL);
	while (line < nb_split && s[i] != '\0')
	{
		world_len = calc_word(&s[i], c) + 1;
		if (s[i] != c)
		{
			if ((split[line] = malloc(sizeof(**split) * world_len)) == NULL)
				return (error(split, nb_split));
			ft_strlcpy(split[line++], &s[i], world_len);
		}
		i += world_len;
	}
	split[line] = NULL;
	return (split);
}
