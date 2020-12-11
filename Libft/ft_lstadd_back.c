/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:14:19 by ketaouki          #+#    #+#             */
/*   Updated: 2020/12/08 07:26:39 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *list;

	list = *alst;
	if (alst)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			list = ft_lstlast(*alst);
			list->next = new;
		}
	}
}
