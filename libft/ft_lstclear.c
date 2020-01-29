/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimon <nsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:07:24 by nsimon            #+#    #+#             */
/*   Updated: 2020/01/29 17:44:02 by nsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*tmp;

	if (lst && del)
	{
		current = *lst;
		while (current != NULL)
		{
			tmp = current;
			current = current->next;
			ft_lstdelone(tmp, del);
		}
		*lst = NULL;
	}
}
