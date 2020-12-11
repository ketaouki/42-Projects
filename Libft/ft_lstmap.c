/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:15:58 by ketaouki          #+#    #+#             */
/*   Updated: 2020/12/05 15:42:10 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new;
	t_list *newelem;

	if (!lst || !f)
		return (0);
	new = NULL;
	while (lst)
	{
		if (!(newelem = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&new, del);
			return (0);
		}
		ft_lstadd_back(&new, newelem);
		lst = lst->next;
	}
	return (new);
}
