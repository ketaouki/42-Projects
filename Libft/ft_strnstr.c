/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:47:51 by ketaouki          #+#    #+#             */
/*   Updated: 2020/12/08 10:48:01 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (s2[i] == '\0')
		return ((char*)s1);
	while ((i < n) && s1[i])
	{
		j = 0;
		while ((s1[j + i] == s2[j]) && (i + j) < n)
		{
			if (s2[j + 1] == '\0')
				return ((char*)s1 + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
