/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:11:16 by ketaouki          #+#    #+#             */
/*   Updated: 2020/12/08 07:08:20 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tab;
	size_t	i;

	i = 0;
	if (!(tab = (char *)malloc(size * nmemb)))
		return (NULL);
	while (i < (size * nmemb))
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}
