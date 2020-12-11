/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:42:39 by ketaouki          #+#    #+#             */
/*   Updated: 2020/12/08 07:14:51 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		j;
	int		k;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	j = ft_strlen(s1) + ft_strlen(s2);
	k = 0;
	if (!(dest = malloc(sizeof(char) * j + 1)))
		return (NULL);
	j = 0;
	while (s1[j])
	{
		dest[k++] = s1[j++];
	}
	j = 0;
	while (s2[j])
	{
		dest[k++] = s2[j++];
	}
	dest[k] = '\0';
	return (dest);
}
