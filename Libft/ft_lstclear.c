/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:15:25 by ketaouki          #+#    #+#             */
/*   Updated: 2020/12/04 14:38:36 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *temp;

	if (lst)
	{
		while (*lst != NULL)
		{
			temp = *lst;
			*lst = temp->next;
			(*del)(temp->content);
			free(temp);
		}
	}
}
