/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimon <nsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:19:31 by nsimon            #+#    #+#             */
/*   Updated: 2019/11/13 16:58:04 by nsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (alst && new)
	{
		tmp = *alst;
		if (tmp == NULL)
			*alst = new;
		else
		{
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new;
		}
	}
}
